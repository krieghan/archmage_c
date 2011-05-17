#include <vector>
#include <string>

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

std::vector<std::string> split_string(std::string stringToSplit, std::string delimiter);
std::string join_string(std::vector<std::string> listToJoin, std::string joinDelimiter);
std::string slice_string(std::string stringToSlice, int begin, int end);
void add_string(std::string& string1, std::string& string2);
std::string concat_string(std::string string1, std::string string2);

#endif