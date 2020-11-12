#include "IOUtils.h"
#include <fstream>

std::string readAllChars(const std::string& path)
{
	std::ifstream file(path);
	
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	
	return content;
}

void writeAllChars(const std::string& path, const std::string& content)
{
	std::ofstream file(path);
	file << content;
	file.close();
}
