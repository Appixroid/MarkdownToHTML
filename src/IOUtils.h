#ifndef __IO_UTILS_H__
#define __IO_UTILS_H__

#include <string>

std::string readAllChars(const std::string& path);
void writeAllChars(const std::string& path, const std::string& data);

#endif
