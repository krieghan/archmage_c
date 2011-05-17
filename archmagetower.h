#include "archmagelocations.h"
#include "location.h"
#include "exceptions.h"

class ArchMageLab : public Location {
public:
	std::string getTitle(){
		return "Archmage's Lab";
	}
	std::string getDescriptionText(){
		std::string intro = "You are in the archmage's lab.  This is where your master, Baldevarth, works.  ";
		std::string east = "To the east is Baldevarth's ritual room.  ";
		return intro + east;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmageritualroom"),
			              east);
	}
};

class ArchMageRitualRoom : public Location {
public:
	std::string getTitle(){
		return "Archmage's Ritual Room";
	}
	std::string getDescriptionText(){
		std::string intro = "You are in the archmage's ritual room, where Baldevarth the Archmage uses his powers to look far and wide across the landscape of the kingdom.  ";
		std::string west = "To the west is Baldevarth's lab.  ";
		std::string east = "To the east is Baldevarth's bedroom.  ";
		std::string north = "To the north is Baldevarth's library, where your master hoards his knowledge of the arcane.  ";
		std::string south = "To the south are the gargoyles who defend the tower.  ";
		return intro + west + east + north + south;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagelab"),
			              west);
		this->addLocation(getLocation("archmagebedroom"),
			              east);
		this->addLocation(getLocation("archmagelibrary"),
			              north);
		this->addLocation(getLocation("gargoyleroom"),
			              south);
	}
};

class ArchMageBedroom : public Location {
public:
	std::string getTitle(){
		return "Archmage's Bedroom";
	}
	std::string getDescriptionText(){
		std::string intro =  "This is the Baldevarth's bedroom, where your master rests from a long day of study and vigilance over the kingdom.  ";
		std::string west = "To the west is Baldevarth's ritual room, where your master watches cautiously over lands near and far.  ";
		return intro + west;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmageritualroom"),
			              west);
	}
};

class ArchMageLibrary : public Location {
public:
	std::string getTitle(){
		return "Archmage's Library";
	}
	std::string getDescriptionText(){
		std::string intro1 = "This is Baldevarth's library, where your master houses his catalogue of magical knowledge, ";
		std::string intro2 = "in addition to personal books that he has picked up over the years.  ";
		std::string intro = intro1 + intro2;
		std::string south = "To the south is Baldevarth's ritual room.  ";
		return intro + south;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmageritualroom"),
			              south);
	}
};

class GargoyleRoom : public Location {
public:
	std::string getTitle(){
		return "Gargoyle Room";
	}
	std::string getDescriptionText(){
		std::string gargoyles1 = "These are the gargoyles who defend Baldevarth's tower.  They stare at you suspiciously.  ";  
		std::string gargoyles2 = "It is your understanding that these gargoyles have been in the tower since Baldevarth came here.  ";
		std::string gargoyles3 = "He applied wards to ordinary animals to twist their features and turn them to stone.  ";
		std::string gargoyles = gargoyles1 + gargoyles2 + gargoyles3;
		std::string north = "To the north is Baldevarth's ritual room.  ";
		std::string south = "To the south is the master's suite, which lies vacant.  The door is locked, and the gargoyles will not let you enter.  ";
		std::string down = "There is a staircase here which leads down into the atrium of Baldevarth's tower.  ";
		return gargoyles + north + south + down;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmageritualroom"),
			              north);
		this->addLocation(getLocation("masterritualroom"),
			              south);
		this->addLocation(getLocation("archmagecenterroom"),
						  down);
	}
	void handleTravel(Actor* player, std::string direction){
		if (direction == "south"){
			throw CannotDoThat("The master mage suite is off-limits.  The archmage warned you when he took you in that the gargoyles would not allow you to enter.");
		}
		Location::handleTravel(player, direction);
	}
};

class MasterRitualRoom : public Location {
	std::string getTitle(){
		return "Master's Ritual Room";
	}
	std::string getDescriptionText(){
		return "";
	}
	void setupConnections(){
		this->addLocation(getLocation("gargoyleroom"),
			              north);
	}
};

class ArchMageCenterRoom : public Location {
	std::string getTitle(){
		return "Center Room";
	}
	std::string getDescriptionText(){
		std::string desc = "You have entered the main room of the archmage's tower.  ";
		std::string south = "To the south is the entryway.  ";
		std::string north = "To the north is the map room, and beyond that your own suite.  ";
		std::string east = "You and your master prepare meals in the kitchen to the east.  ";
		std::string west = "A large storage room is to the west.  ";
		std::string staircase = "A staircase runs up to the top floor and down to the cellar.  ";
		std::string navigation = north + south + east + west + staircase;
		return desc + navigation;
	}
	void setupConnections(){
		this->addLocation(getLocation("maproom"),
			              north);
		this->addLocation(getLocation("archmagecloset"),
						  west);
		this->addLocation(getLocation("archmagekitchen"),
			              east);
	    this->addLocation(getLocation("towerentry"),
		                  south);
		this->addLocation(getLocation("gargoyleroom"),
			              up);
		this->addLocation(getLocation("archmagecellar"),
			              down);
	}
};

class MapRoom : public Location {
	std::string getTitle(){
		return "Map Room";
	}
	std::string getDescriptionText(){
		std::string intro = "This is Baldevarth's map room.  ";
		std::string maps = "A map of the kingdom is framed on the wall.  Maps of various foreign lands are rolled up and lean against the walls of the room.  ";
		std::string north = "To the north is your personal library, the entryway to your suite.  ";
		std::string south = "To the south is the main room of Baldevarth's tower.  ";
		return intro + maps + north + south;
	}
	void setupConnections(){
		this->addLocation(getLocation("magelibrary"),
			              north);
		this->addLocation(getLocation("archmagecenterroom"),
			              south);
	}
};

class ArchmageCloset : public Location {
	std::string getTitle(){
		return "Closet";
	}
	std::string getDescriptionText(){
		std::string intro = "This is the closet.  ";
		std::string clothes = "Old robes, overcoats and tunics hang along the walls, with additional garments folded up and stacked on the floor.  ";
		std::string oddsAndEnds = "Unused and largely unwanted odds and ends such as brooms, boxes and cloth sacks litter the floor of the closet.  ";
		std::string east = "The only way out is the the east, which leads back to the main room of Baldevarth's tower.  ";
		return intro + clothes + oddsAndEnds + east;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagecenterroom"),
			              east);
	}
};

class ArchmageKitchen : public Location {
	std::string getTitle(){
		return "Kitchen";
	}
	std::string getDescriptionText(){
		std::string intro = "This is Baldevarth's kitchen.  You and your master prepare and eat meals here.  ";
		std::string table = "An old wooden table and two chairs sit here for your and Baldevarth's use.  ";
		std::string west = "To the west is the main room of Baldevarth's tower.  ";
		return intro + table + west;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagecenterroom"),
			              west);
	}
};

class ArchmageTowerEntry : public Location {
	std::string getTitle(){
		return "Archmage Tower Entry";
	}
	std::string getDescriptionText(){
		std::string intro = "This is the entryway to Baldevarth's tower.  ";
		std::string guard = "The guard, Mical, stands vigilant against intruders.  ";
		std::string north = "To the north is the main room of Baldevarth's tower.  ";
		std::string south = "The outside of the tower lies past the exit to the south.  ";
		return intro + guard + north + south;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagecenterroom"),
			              north);
	}
};

class ArchmageCellar : public Location {
	std::string getTitle(){
		return "Root Cellar";
	}
	std::string getDescriptionText(){
		std::string intro = "This it the root cellar, where Baldevarth keeps his vegetables, roots and herbs.  Some are used as ingredients in potions, other in cooking.  ";
		std::string up = "Up the stairs is the main room of Baldevarth's tower.  ";
		std::string east = "To the east is the room where Baldevarth keeps his furnace.  ";
		return intro + up + east;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagecenterroom"),
			              up);
		this->addLocation(getLocation("archmagefurnaceroom"),
			              east);
	}
};

class ArchmageFurnaceRoom : public Location {
	std::string getTitle(){
		return "Furnace Room";
	}
	std::string getDescriptionText(){
		std::string intro = "This is where Baldevarth keeps the furnace that heats his tower.  ";
		std::string west = "To the west is Baldevarth's root cellar.  ";
		return intro + west;
	}
	void setupConnections(){
		this->addLocation(getLocation("archmagecellar"),
			              west);
	}
};

class MageLibrary : public Location {
	std::string getTitle(){
		return "Your Library";
	}
	std::string getDescriptionText(){
		std::string intro = "This is your libary.  In this room, you store knowledge that you accumulate along your journey to become a Master.  ";
		std::string library = "When you use your powers, you draw upon what is stored on the shelves of this library.  ";
		std::string east = "To the east is your bedroom.  ";
		std::string west = "To the west is your lab, where you practice your craft.  ";
		std::string south = "To the south is Baldevarth's map room.";
		return intro + library + east + west + south;
	}
	void setupConnections(){
		this->addLocation(getLocation("maproom"),
			              south);
		this->addLocation(getLocation("magelab"),
			              west);
		this->addLocation(getLocation("magebedroom"),
			              east);
	}
};

class MageLab : public Location {
	std::string getTitle(){
		return "Your Lab";
	}
	std::string getDescriptionText(){
		std::string intro = "This is your lab, where you practice your craft.  ";
		std::string alchemy = "Flasks and beakers are neatly arranged on the counter, along with other equipment to aid in your potion making.  ";
		std::string ritual = "A small stone table sits in the corner of the room.  The table has a faded brown pentacle drawn upon it.  Here, you may perform small rituals to aid you in your journey.  ";
		std::string east = "To the east is your library.  ";
		return intro + alchemy + ritual + east;
	}
	void setupConnections(){
		this->addLocation(getLocation("magelibrary"),
			              east);
	}
};

class MageBedroom : public Location {
	std::string getTitle(){
		return "Your Bedroom";
	}
	std::string getDescriptionText(){
		std::string intro = "This is your bedroom, where you sleep.  ";
		std::string west = "To the west is your library.  ";
		return intro + west;
	}
	void setupConnections(){
		this->addLocation(getLocation("magelibrary"),
			              west);
	}
};

class 