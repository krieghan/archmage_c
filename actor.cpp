#include "actor.h"

Actor::Actor(){
	this->location = 0;
}

void Actor::setLocation(Location* location){
	if (this->location){
		this->location->removeEntity(this);
	}
	this->location = location;
	this->location->addEntity(this);
}

Location* Actor::getLocation(){
	return this->location;
}

void Actor::announceLocation(){
	this->getLocation()->announce();
}