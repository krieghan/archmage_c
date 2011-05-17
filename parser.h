#include <string>
#include <map>
#include <vector>
#include <exception>

#include "dictionary.h"
#include "command.h"

#ifndef PARSER_H
#define PARSER_H


class InvalidSentenceStructure : public std::exception{
public:
	InvalidSentenceStructure(std::string phraseStructure);
	std::string phraseStructure;
};

class UnknownWord : public std::exception {
public:
	UnknownWord(std::string word);
	std::string word;
};


class Parser {
public:
	Parser(Dictionary* dictionary);
	Command parseSentence(std::string in);
private:
	Dictionary* dictionary;
	std::vector<std::string> getSentenceStructures(std::vector<std::string>& words);
	Command evaluateSentenceStructures(std::vector<std::string> sentenceStructures, std::vector<std::string> words);
};

#endif