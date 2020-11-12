#include "MarkdownConverter.h"
#include <curl/curl.h>

size_t curlWriteIntoString(char* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*) userp)->append(contents, size * nmemb);
    return size * nmemb;
}

bool markdownToHtml(const std::string& markdown, std::string& html)
{
	curl_global_init(CURL_GLOBAL_ALL);
	
	CURLcode code = CURLE_FAILED_INIT;
	CURL* curl = curl_easy_init();
	
	if(curl)
	{
		struct curl_slist* headers = curl_slist_append(NULL, "Content-Type: text/plain");
		headers = curl_slist_append(headers, "User-Agent: mdToHtml/1.0");
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/markdown/raw");
		
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, markdown.c_str());
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteIntoString);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);

		code = curl_easy_perform(curl);

		curl_slist_free_all(headers);
		curl_easy_cleanup(curl);
	}
			
	curl_global_cleanup();
	
	return code == CURLE_OK;
}
