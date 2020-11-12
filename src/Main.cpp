#include <string>
#include <iostream>
#include "IOUtils.h"
#include "MarkdownConverter.h"

#define REAL_ARGS_COUNT(argc) (argc-1)
#define EXECUTABLE_NAME(argv) (argv[0])
#define INPUT_FILE(argv) (argv[1])
#define OUTPUT_FILE(argv) (argv[2])

#define MIN_ARGS_COUNT 1
#define MAX_ARGS_COUNT 2

#define SUCCESS 0
#define COMMAND_ERROR 1
#define CONVERT_ERROR 2

void usage(std::string executableName);

std::string getOutputFile(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	if(REAL_ARGS_COUNT(argc) < MIN_ARGS_COUNT || REAL_ARGS_COUNT(argc) > MAX_ARGS_COUNT)
	{
		usage(EXECUTABLE_NAME(argv));
		return COMMAND_ERROR;
	}
	else
	{			
		std::string markdownContent(readAllChars(INPUT_FILE(argv)));

		std::string htmlContent;
		bool convertSuccess = markdownToHtml(markdownContent, htmlContent);
			
		if(convertSuccess)
		{	
			writeAllChars(getOutputFile(argc, argv), htmlContent);
			return SUCCESS;
		}
		else
		{
			return CONVERT_ERROR;
		}
	}
}

void usage(std::string executableName)
{
	std::cout << executableName << " Markdown File [HTML File]" << std::endl;
}

std::string getOutputFile(int argc, char* argv[])
{
	if(REAL_ARGS_COUNT(argc) == MAX_ARGS_COUNT)
	{
		return std::string(OUTPUT_FILE(argv));
	}
	else
	{
		return std::string(INPUT_FILE(argv)) + ".html";
	}
}
