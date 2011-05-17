#include <string>

#include "actor.h"

#ifndef ARCHMAGEACTORS_H
#define ARCHMAGEACTORS_H

Actor* getActor(std::string actorName);
void buildActors();
void addActorsToDictionary(Dictionary* dictionary);


#endif