#include <map>

#include "archmagelocations.h"
#include "exceptions.h"

#include "archmagetower.h"

std::map<std::string, Location*> locations = std::map<std::string, Location*>();

Location* getLocation(std::string locationName){
	return locations[locationName];
}



void buildLocations(){
	Location* location;

	locations["archmagelab"] = new ArchMageLab();
	locations["archmageritualroom"] = new ArchMageRitualRoom();
	locations["archmagebedroom"] = new ArchMageBedroom();
	locations["archmagelibrary"] = new ArchMageLibrary();
	locations["gargoyleroom"] = new GargoyleRoom();
	locations["masterritualroom"] = new MasterRitualRoom();
	locations["archmagecenterroom"] = new ArchMageCenterRoom();
	locations["maproom"] = new MapRoom();
	locations["archmagecloset"] = new ArchmageCloset();
	locations["archmagekitchen"] = new ArchmageKitchen();
	locations["towerentry"] = new ArchmageTowerEntry();
	locations["archmagecellar"] = new ArchmageCellar();
	locations["archmagefurnaceroom"] = new ArchmageFurnaceRoom();
	locations["magelibrary"] = new MageLibrary();
	locations["magelab"] = new MageLab();
	locations["magebedroom"] = new MageBedroom();

	for (std::map<std::string, Location*>::iterator it = locations.begin(); it != locations.end(); it++){
		location = it->second;
		location->setupConnections();
	}
}