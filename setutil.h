#include <set>
#include <string>

std::set<std::string> makeSetOfStrings(std::string* arrayOfElements){
	std::set<std::string> setOfStrings = std::set<std::string>();
	int i = 0;
	std::string currentElement = arrayOfElements[i];
	while (currentElement != ""){
		setOfStrings.insert(currentElement);
		i++;
		currentElement = arrayOfElements[i];
	}
	return setOfStrings;
}