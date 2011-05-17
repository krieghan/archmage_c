#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "parser.h"
#include "actor.h"
#include "entity.h"

class Actor;
class Location;

enum Direction {north, south, east, west, up, down};

struct LocationConnections {
	Location* north;
	Location* south;
	Location* east;
	Location* west;
	Location* up;
	Location* down;
};

class Location {
public:
	Location();
	virtual std::string getTitle()=0;
	
	virtual void setupConnections()=0;
	virtual void processCommand(Command command,
				                Actor* player);
	virtual void handleTravel(Actor* player,
			   		          std::string direction);
	std::string getDescription();
	std::string getSubDescription();
	void handleLook(Actor* player,
				    Entity* target);
	void announce();
	void addEntity(Entity* entityToAdd);
	void removeEntity(Entity* entityToRemove);
	
protected:
	void addLocation(Location* connectedLocation,
		             Direction direction);
	virtual std::string getDescriptionText()=0;
private:
	bool hasBeenVisited;
	LocationConnections locations;
	std::set<Entity*> entities;
	Entity* matchTokenToEntity(std::string noun);
	std::set<Entity*> findActors(Actor* player);
};



#endif