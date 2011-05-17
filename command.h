#ifndef COMMAND_H
#define COMMAND_H

struct NounPhrase {
	std::string adjective;
	std::string noun;
};

struct PrepositionalPhrase {
	std::string preposition;
	NounPhrase objectOfPreposition;
};


struct Command {
	NounPhrase subject;
	std::string verb;
	NounPhrase object;
	PrepositionalPhrase prepositionalPhrase;
};

#endif
