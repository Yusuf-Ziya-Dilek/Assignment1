#include "Actor.h"

//Constructor
Actor::Actor(const string aName, const string aBirthPlace, const unsigned int aBirthYear) {
	name = aName;
	birthPlace = aBirthPlace;
	birthYear = aBirthYear;
}

//Copy Constructor
Actor::Actor(const Actor& actorToCopy) {
	name = actorToCopy.name;
	birthPlace = actorToCopy.birthPlace;
	birthYear = actorToCopy.birthYear;
}

//Destructor
Actor::~Actor() {
	//cout << name << " named Actor is deleted" << endl;
}

//Overlooading assigment operator
void Actor::operator=(const Actor& right) {
	name = right.name;
	birthPlace = right.birthPlace;
	birthYear = right.birthYear;
}

//Getters
string Actor::getName() const {
	return name;
}

string Actor::getBirthPlace() const {
	return birthPlace;
}

unsigned int Actor::getBirthYear() const {
	return birthYear;
}

ostream& operator<<(ostream& out, const Actor& a) {
	out << a.getName() << ", " << a.getBirthPlace() << ", " << a.getBirthYear() << endl;
	return out;
}
