#ifndef ACTOR_H
#define ACTOR_H

#include "location.h"
#include "entity.h"
#include "io.h"

class Location;

class Actor : public Entity {
public:
	Actor();
	virtual std::string getTitle()=0;
	virtual std::string getAnnouncement() { return this->getTitle() + " is here."; }
	void setLocation(Location* location);
	Location* getLocation();
	void announceLocation();
	std::string type() {return "actor"; }
	virtual void handleLook() {};
	virtual void handleTalk() { outputString(this->getTitle() + " has nothing to say"); }
	virtual void handleAsk(std::string topic) { outputString(this->getTitle() + " knows nothing about that topic"); }
private:
	Location* location;
};

#endif