#include "dictionary.h"

std::string getPartOfSpeechString(PartOfSpeech partOfSpeech){
	switch(partOfSpeech){
		case noun:
			return "noun";
			break;
		case verb:
			return "verb";
			break;
		case adjective:
			return "adjective";
			break;
		case article:
			return "article";
			break;
		case preposition:
			return "preposition";
			break;
		case direction:
			return "direction";
			break;
		default:
			return "none";
			break;
	}
}

Dictionary::Dictionary(){
	this->partsOfSpeech = std::map<std::string, std::set<PartOfSpeech>>();
	this->nouns = std::map<std::string, std::string>();
	this->verbs = std::map<std::string, std::string>();
	this->adjectives = std::map<std::string, std::string>();
	this->articles = std::map<std::string, std::string>();
	this->prepositions = std::map<std::string, std::string>();
	this->directions = std::map<std::string, std::string>();
}

std::map<std::string, std::string>* Dictionary::getMap(PartOfSpeech partOfSpeech){
	switch (partOfSpeech){
		case noun:
			return &this->nouns;
			break;
		case verb:
			return &this->verbs;
			break;
		case adjective:
			return &this->adjectives;
			break;
		case article:
			return &this->articles;
			break;
		case preposition:
			return &this->prepositions;
			break;
		case direction:
			return &this->directions;
			break;
		default:
			return 0;
	}
}

std::set<PartOfSpeech> Dictionary::getPartOfSpeech(std::string in){
	return this->partsOfSpeech[in]; 
}

std::string Dictionary::getSynonym(std::string word, PartOfSpeech partOfSpeech){
	std::map<std::string, std::string>* wordsForPartOfSpeech = this->getMap(partOfSpeech);
	std::string synonym;

	if (wordsForPartOfSpeech->count(word) > 0){
		synonym = (*wordsForPartOfSpeech)[word];
	} else {
		synonym = word;
	}
	return synonym;
}

void Dictionary::addWord(std::string word, PartOfSpeech partOfSpeech){
	std::set<PartOfSpeech> partsOfSpeechForThisWord = this->partsOfSpeech[word];
	this->partsOfSpeech[word].insert(partOfSpeech);

}

void Dictionary::addSynonym(std::string word, std::string synonym, PartOfSpeech partOfSpeech){
	std::map<std::string, std::string>* mapForPartOfSpeech = this->getMap(partOfSpeech);
	(*mapForPartOfSpeech)[word] = synonym;
	this->addWord(word, partOfSpeech);
	this->addWord(synonym, partOfSpeech);
}