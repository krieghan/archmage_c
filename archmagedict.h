#include "dictionary.h"

#ifndef ARCHMAGEDICT_H
#define ARCHMAGEDICT_H

Dictionary* createArchMageDictionary(){
	Dictionary* dictionary = new Dictionary();
	std::string nouns[] = {"stone", "magic"};
	std::string verbs[] = {"throw", "go", "look", "ask"};
	std::string directions[] = {"north", "east", "south", "west", "up", "down"};
	std::string prepositions[] = {"at", "to", "about"};
	
	for (int i = 0; i < sizeof(nouns) / sizeof(std::string); i++){
		dictionary->addWord(nouns[i], noun);
	}

	for (int i = 0; i < sizeof(verbs) / sizeof(std::string); i++){
		dictionary->addWord(verbs[i], verb);
	}

	for (int i = 0; i < sizeof(directions) / sizeof(std::string); i++){
		dictionary->addWord(directions[i], direction);
	}

	for (int i = 0; i < sizeof(prepositions) / sizeof(std::string); i++){
		dictionary->addWord(prepositions[i], preposition);
	}

	dictionary->addSynonym("rock", "stone", noun);

	dictionary->addSynonym("walk", "go", verb);
	dictionary->addSynonym("run", "go", verb);
	dictionary->addSynonym("examine", "look", verb);
	dictionary->addSynonym("speak", "talk", verb);

	dictionary->addSynonym("n", "north", direction);
	dictionary->addSynonym("s", "south", direction);
	dictionary->addSynonym("w", "west", direction);
	dictionary->addSynonym("e", "east", direction);
	dictionary->addSynonym("u", "up", direction);
	dictionary->addSynonym("d", "down", direction);
	return dictionary;
}

#endif