#include "io.h"
#include "location.h"
#include "command.h"
#include "exceptions.h"

Location::Location(){
	this->hasBeenVisited = false;
	this->locations = LocationConnections();
	this->entities = std::set<Entity*>();
}

Entity* Location::matchTokenToEntity(std::string noun){
	std::vector<Entity*> candidates = std::vector<Entity*>();
	std::set<std::string> tokens = std::set<std::string>();
	for (std::set<Entity*>::iterator it = this->entities.begin(); it != this->entities.end(); it++){
		tokens = (*it)->getTokens();
		if (tokens.count(noun)){
			candidates.push_back(*it);
		}
	}
	if (candidates.size() == 1){
		return candidates[0];
	} else if (candidates.size() > 0) {
		throw CannotDoThat("More than one candidate for noun " + noun);
	} else {
		return 0;
	}
}

void Location::processCommand(Command command, Actor* player){
	std::string verb = command.verb;
	std::string objectNoun = command.object.noun;
	std::string objectOfPrepositionNoun = command.prepositionalPhrase.objectOfPreposition.noun;
	Entity* object = 0;
	Entity* objectOfPreposition = 0;
	
	if (objectNoun != ""){
		object = this->matchTokenToEntity(objectNoun);
	}
	
	if (objectOfPrepositionNoun != ""){
		objectOfPreposition = this->matchTokenToEntity(objectOfPrepositionNoun);
	}

	if (verb == "go"){
		this->handleTravel(player,
		   			       objectNoun);
		return;
	}
	
	
	if (verb == "look"){
		if (objectOfPrepositionNoun != "" && !objectOfPreposition){
			throw CannotDoThat("There is no " + objectOfPrepositionNoun + " here to look at.");
		}
		this->handleLook(player,
		                 objectOfPreposition);
		return;
	}

	if (verb == "talk"){
		if (objectOfPrepositionNoun != "" && !objectOfPreposition){
			throw CannotDoThat("There is no " + objectOfPrepositionNoun + " here to talk to.");
		}
		objectOfPreposition->handleTalk();
		return;
	}
	
	if (verb == "ask"){
		if (objectNoun == ""){
			std::set<Entity*> objects = this->findActors(player);
			if (objects.size() == 0){
				throw CannotDoThat("There is no one here to answer your questions.");
			} else if (objects.size() > 1){
				throw CannotDoThat("To whom are you directing your question?");
			} else {
				object = *(objects.begin());
			}
		}
		if (objectNoun != "" && !object){
			throw CannotDoThat("There is no " + objectNoun + " here to answer your questions.");
		}
		object->handleAsk(objectOfPrepositionNoun);
		return;
	}

	throw CannotDoThat("I do not understand what you are trying to do");
	
}

std::set<Entity*> Location::findActors(Actor* player){
	std::set<Entity*> results = std::set<Entity*>();
	Entity* entity;
	for (std::set<Entity*>::iterator it = this->entities.begin(); it != this->entities.end(); it++){
		entity = *it;
		if (entity->type() == "actor" && entity != player){
			results.insert(entity);
		}
	}
	return results;
}

void Location::handleLook(Actor* player,
	   				      Entity* target){
	if (target){
		target->handleLook();
	} else {
		outputString(this->getDescription());
	}
}

void Location::handleTravel(Actor* player, std::string direction){
	Location* newLocation = 0;
	if (direction == "north"){
		newLocation = this->locations.north;
	} else if (direction == "south") {
		newLocation = this->locations.south;
	} else if (direction == "east"){
		newLocation = this->locations.east;
	} else if (direction == "west"){
		newLocation = this->locations.west;
	} else if (direction == "up"){
		newLocation = this->locations.up;
	} else if (direction == "down"){
		newLocation = this->locations.down;
	} else if (direction == ""){
		throw CannotDoThat("Where are you trying to go?");
	}
	else {
		throw CannotDoThat(direction + " is not a direction");
	}

	if (newLocation){
		player->setLocation(newLocation);
		player->announceLocation();
	} else {
		throw CannotDoThat("You cannot go that way");
	}
}

std::string Location::getDescription(){
	return this->getDescriptionText() + this->getSubDescription();
}

std::string Location::getSubDescription(){
	std::string subDescription = std::string();
	for (std::set<Entity*>::iterator it = this->entities.begin(); it != this->entities.end(); it++){
		subDescription += (*it)->getAnnouncement() + "  ";
	}
	return subDescription;
}

void Location::announce(){
	outputString(this->getTitle());
	if (!this->hasBeenVisited){
		outputString(this->getDescriptionText());
	}
	this->hasBeenVisited = true;
	outputString(this->getSubDescription());
}

void Location::addLocation(Location* connectedLocation, Direction direction){
	switch (direction){
		case north:
			this->locations.north = connectedLocation;
			break;
		case south:
			this->locations.south = connectedLocation;
			break;
		case east:
			this->locations.east = connectedLocation;
			break;
		case west:
			this->locations.west = connectedLocation;
			break;
		case up:
			this->locations.up = connectedLocation;
			break;
		case down:
			this->locations.down = connectedLocation;
			break;
	}
}

void Location::addEntity(Entity* entityToAdd){
	this->entities.insert(entityToAdd);
}

void Location::removeEntity(Entity* entityToRemove){
	this->entities.erase(entityToRemove);
}