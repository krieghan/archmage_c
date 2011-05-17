#include <map>
#include "io.h"
#include "setutil.h"
#include "archmageactors.h"
#include "archmagelocations.h"

std::map<std::string, Actor*> actors = std::map<std::string, Actor*>();

Actor* getActor(std::string actorName){
	return actors[actorName];
}

class Player : public Actor {
	std::string getTitle(){
		return "Player";
	}
	std::set<std::string> getTokens(){
		std::string tokens[] = {"you", "me", "player", "myself", "yourself", ""};
		return makeSetOfStrings(tokens);
	}
	void handleLook(){
		outputString("Look there, it's you!");
	}
	std::string getAnnouncement(){
		return "";
	}
};

class Baldevarth : public Actor {
	std::string getTitle(){
		return "The Archmage Baldevarth";
	}
	std::set<std::string> getTokens(){
		std::string tokens[] = {"baldevarth", "man", "mage", "archmage", "master", ""};
		return makeSetOfStrings(tokens);
	}	
	void handleLook(){
		std::string desc = "The Archmage Baldevarth is your mentor and friend.  His dark hair comes down to his shoulders, ";
		desc += "and is just barely streaked with gray.  His bright blue eyes are the clearest you've ever seen.  ";
		desc += "Despite his fairly youthful appearance, you happen to know that he is much, much older than he looks.  ";
		desc += "He looks down and smiles upon you kindly.";
		outputString(desc);
	}
	void handleTalk(){
		outputString("Baldevarth: Good day, my enthusiastic protege.  What can I do for you?");
	}
	void handleAsk(std::string topic){
		//std::set<std::string> magicTopics = makeSetOfStrings({"magic", ""});
		//std::set<std::string> archmageTopics = makeSetOfStrings({"archmage", "mage", "baldevarth", "man", "himself", ""});
		//std::set<std::string> townTopics = makeSetOfStrings({"town", "city", "village", ""});
		//std::set<std::string> kingdomTopics = makeSetOfStrings({"kingdom", ""});
		//std::set<std::string> ritualTopics = makeSetOfStrings({"ritual", ""});

		//std::string answer = std::string();
		//if (magicTopics.count(topic)){
		//	answer = "I have immersed myself in its study for over 70 years.  You could say I have seen it all.  ";
		//	answer += "You have been with me for only 4.  There are still new lessons for you to learn.  ";
		//	answer += "As for me, I have only my duty to the people of this land to drive me out of bed each morning.";
		//} else if (archmageTopics.count(topic)){
			
		//} else {
		//	answer = "I'm afraid I know nothing useful about that topic, my friend.";
		//}

		//outputString("Baldevarth: " + answer);
	}
};

void buildActors(){
	actors["player"] = new Player();
	actors["baldevarth"] = new Baldevarth();
	
	//Set actor locations
	Location* archmageStudy = getLocation("archmagelab");
	actors["player"]->setLocation(archmageStudy);
	actors["baldevarth"]->setLocation(archmageStudy);
}

void addActorsToDictionary(Dictionary* dictionary){
	Actor* actor;
	std::set<std::string> tokens;
	std::string token;
	for (std::map<std::string, Actor*>::iterator actorIterator = actors.begin(); actorIterator != actors.end(); actorIterator++){
		actor = (*actorIterator).second;
		tokens = actor->getTokens();
		for (std::set<std::string>::iterator tokenIterator = tokens.begin(); tokenIterator != tokens.end(); tokenIterator++){
			token = *tokenIterator;
			dictionary->addWord(token, noun);
		}
	}
}

