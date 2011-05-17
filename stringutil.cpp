#include "stringutil.h"

std::vector<std::string> split_string(std::string stringToSplit, std::string delimiter){
	std::vector<std::string> listOfStrings = std::vector<std::string>();
	std::string workingString = std::string();
	int delimiterLength = delimiter.length();
	int stringLength = stringToSplit.length();
	for (int i = 0; i < stringLength; i++){
		char thisChar = stringToSplit[i];
		std::string delimiterCandidate = slice_string(stringToSplit, i, i + delimiterLength);
		if (delimiterCandidate == delimiter){
			if (workingString.size() > 0){
				listOfStrings.push_back(workingString);
				workingString = std::string();
			}
		} else {
			workingString.push_back(thisChar);
		}
	}
	if (workingString.size() > 0){
		listOfStrings.push_back(workingString);
	}
	return listOfStrings;
}

std::string join_string(std::vector<std::string> listToJoin, std::string joinDelimiter){
	std::string newString = std::string();
	if (listToJoin.size() == 0){
		return newString;
	}
	add_string(newString, listToJoin[0]);
	for (unsigned int i = 1; i < listToJoin.size(); i++){
		add_string(newString, joinDelimiter);
		add_string(newString, listToJoin[i]);
	}

	return newString;
}

void add_string(std::string& string1, std::string& string2){
	int string2length = string2.length();
	for (int i = 0; i < string2length; i++){
		string1.push_back(string2[i]);
	}
}

std::string concat_string(std::string string1, std::string string2){
	std::string newString = std::string();
	add_string(newString, string1);
	add_string(newString, string2);
	return newString;
}

std::string slice_string(std::string stringToSlice, int begin, int end){
	std::string slice = std::string();
	for (int i = begin; i < end; i++){
		slice.push_back(stringToSlice[i]);
	}
	return slice;
}