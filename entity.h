#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
	virtual std::string getTitle()=0;
	virtual std::string getAnnouncement()=0;
	virtual std::set<std::string> getTokens()=0;
	virtual void handleLook()=0;
	virtual void handleTalk()=0;
	virtual void handleAsk(std::string topic)=0;
	virtual std::string type()=0;
};

#endif