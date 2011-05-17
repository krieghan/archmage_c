#include <string>
#include <map>
#include <vector>
#include <set>

#ifndef DICTIONARY_H
#define DICTIONARY_H

enum PartOfSpeech {noun, verb, adjective, article, preposition, direction};

std::string getPartOfSpeechString(PartOfSpeech partOfSpeech);

class Dictionary {
public:
	Dictionary();
	std::set<PartOfSpeech> getPartOfSpeech(std::string in);
	std::string getSynonym(std::string, PartOfSpeech);
	void addWord(std::string word, PartOfSpeech);
	void addSynonym(std::string word, std::string synonym, PartOfSpeech);
private:
	
	std::map<std::string, std::set<PartOfSpeech>> partsOfSpeech;
	std::map<std::string, std::string>* getMap(PartOfSpeech partOfSpeech);
	std::map<std::string, std::string> nouns;
	std::map<std::string, std::string> verbs;
	std::map<std::string, std::string> adjectives;
	std::map<std::string, std::string> articles;
	std::map<std::string, std::string> prepositions;
	std::map<std::string, std::string> directions;
};

#endif 