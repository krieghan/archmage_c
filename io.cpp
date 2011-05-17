#include <vector>
#include "io.h"

int getFirstSpaceBeforeThreshold(std::string stringIn, int threshold){
	int currentIndex = threshold;
	while (stringIn[currentIndex] != ' '){
		currentIndex--;
	}
	return currentIndex;
}
	

void wrapifyString(std::string &stringIn, int threshold){
	int lengthOfString = stringIn.length();
	int currentThreshold = threshold;
	while(currentThreshold < lengthOfString){
		int breakIndex = getFirstSpaceBeforeThreshold(stringIn, currentThreshold);
		stringIn[breakIndex] = '\n';
		currentThreshold = breakIndex + threshold;
	}
}


void outputString(std::string stringToOutput){
	wrapifyString(stringToOutput, 75);
	std::cout << stringToOutput << std::endl;
}

std::string getInput(std::string query){
	std::string input = "";
	getline(std::cin, input);
	return input;
}