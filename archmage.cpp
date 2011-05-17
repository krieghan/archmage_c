#include <string>

#include "parser.h"
#include "command.h"
#include "dictionary.h"
#include "io.h"
#include "exceptions.h"
#include "archmagedict.h"
#include "archmagelocations.h"
#include "archmageactors.h"



int main(){
	Dictionary* dictionary = createArchMageDictionary();
	Parser* parser = new Parser(dictionary);
	std::string userInput;
	buildLocations();
	buildActors();
	addActorsToDictionary(dictionary);
	Actor* player = getActor("player");
	Command command;
	player->announceLocation();
	while(true){
		userInput = getInput();
		try {
			command = parser->parseSentence(userInput);
		} catch(UnknownWord unknownWord) {
			outputString("I do not know the word '" + unknownWord.word + "'");
			continue;
		} catch(InvalidSentenceStructure invalidSentenceStructure) {
			outputString("I do not know how to interpret a phrase with the structure: " + invalidSentenceStructure.phraseStructure);
			continue;
		}

		try {
			player->getLocation()->processCommand(command,
			   								      player);
		} catch(CannotDoThat cannotDoThat){
			outputString(cannotDoThat.message);
		}
	}
	
	return 0;
}