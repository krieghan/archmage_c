#include "parser.h"
#include "stringutil.h"
#include "vectorutil.h"

Parser::Parser(Dictionary* dictionary){
	this->dictionary = dictionary;
}

std::vector<std::string> Parser::getSentenceStructures(std::vector<std::string>& words){
	std::vector<std::string> structures = std::vector<std::string>();
	std::string word;
	std::vector<std::string> listOfPartsOfSpeech;
	std::string partsOfSpeechStr;
	std::set<PartOfSpeech> partsOfSpeech;
	PartOfSpeech partOfSpeech;
	for (unsigned int i = 0; i < words.size(); i++){
		word = words[i];
		partsOfSpeech = this->dictionary->getPartOfSpeech(word);
		if (partsOfSpeech.size() == 0){
			throw UnknownWord(word);
		}
		partOfSpeech = *partsOfSpeech.begin();
		if (partOfSpeech == article){
			continue;
		}

		if (partOfSpeech == noun){
			if (i == 0 || listOfPartsOfSpeech[i - 1] != "adjective"){
				listOfPartsOfSpeech.push_back("adjective");
				vector_insert<std::string>(words, i, "");
				i += 1;
			}

		}
		
		listOfPartsOfSpeech.push_back(getPartOfSpeechString(partOfSpeech));
		
	}
	partsOfSpeechStr = join_string(listOfPartsOfSpeech, " ");
	structures.push_back(partsOfSpeechStr);
	return structures;
}

Command Parser::evaluateSentenceStructures(std::vector<std::string> sentenceStructures, std::vector<std::string> words){
	std::string sentenceStructure = sentenceStructures[0];
	Command command = Command();
	command.subject = NounPhrase();
	command.object = NounPhrase();
	command.prepositionalPhrase = PrepositionalPhrase();
	command.prepositionalPhrase.objectOfPreposition = NounPhrase();
	if (sentenceStructure == "verb adjective noun"){
		command.verb = this->dictionary->getSynonym(words[0], verb);
		command.object.adjective = this->dictionary->getSynonym(words[1], adjective);
		command.object.noun = this->dictionary->getSynonym(words[2], noun);
	} else if (sentenceStructure == "verb adjective noun preposition adjective noun"){
		command.verb = this->dictionary->getSynonym(words[0], verb);
		command.object.adjective = this->dictionary->getSynonym(words[1], adjective);
		command.object.noun = this->dictionary->getSynonym(words[2], noun);
		command.prepositionalPhrase.preposition = this->dictionary->getSynonym(words[3], preposition);
		command.prepositionalPhrase.objectOfPreposition.adjective = this->dictionary->getSynonym(words[4], adjective);
		command.prepositionalPhrase.objectOfPreposition.noun = this->dictionary->getSynonym(words[5], noun);
	} else if (sentenceStructure == "verb direction"){
		command.verb = this->dictionary->getSynonym(words[0], verb);
		command.object.noun = this->dictionary->getSynonym(words[1], direction);
	} else if (sentenceStructure == "direction"){
		command.verb = "go";
		command.object.noun = this->dictionary->getSynonym(words[0], direction);
	} else if (sentenceStructure == "verb"){
		command.verb = this->dictionary->getSynonym(words[0], verb);
	} else if (sentenceStructure == "verb preposition adjective noun"){
		command.verb = this->dictionary->getSynonym(words[0], verb);
		command.prepositionalPhrase.preposition = this->dictionary->getSynonym(words[1], preposition);
		command.prepositionalPhrase.objectOfPreposition.adjective = this->dictionary->getSynonym(words[2], adjective);
		command.prepositionalPhrase.objectOfPreposition.noun = this->dictionary->getSynonym(words[3], noun);
	}
	
	else {
		throw InvalidSentenceStructure(sentenceStructure);
	}
	return command;
}

Command Parser::parseSentence(std::string sentence){
	std::vector<std::string> words = split_string(sentence, " ");
	std::vector<std::string> sentenceStructures = this->getSentenceStructures(words);
	Command command = this->evaluateSentenceStructures(sentenceStructures, words);
	return command;
}

UnknownWord::UnknownWord(std::string word){
	this->word = word;
}

InvalidSentenceStructure::InvalidSentenceStructure(std::string phraseStructure){
	this->phraseStructure = phraseStructure;
}