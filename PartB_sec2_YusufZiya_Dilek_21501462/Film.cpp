#include "Film.h"

Film::Film(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration){
	title = fTitle;
	director = fDirector;
	year = fYear;
	duration = fDuration;
	actors = NULL;
	noOfActors = 0;
	size = 0;
}

Film::Film(const Film& fToCopy){
	title = fToCopy.title;
	director = fToCopy.director;
	year = fToCopy.year;
	duration = fToCopy.duration;
	noOfActors = fToCopy.noOfActors;
	size = fToCopy.size;
	if (size <= 0) {
		actors = NULL;
	}
	else {
		actors = new Actor[size];
		for (int i = 0; i < size; i++) {
			actors[i] = fToCopy.actors[i];
		}
	}
}

Film::~Film(){
	if (actors)
		delete[] actors;
}

void Film::operator=(const Film& right){
	title = right.title;
	director = right.director;
	year = right.year;
	duration = right.duration;
	noOfActors = right.noOfActors;
	size = right.size;
	if (size <= 0) {
		actors = NULL;
	}
	else {
		actors = new Actor[size];
		for (int i = 0; i < size; i++) {
			actors[i] = right.actors[i];
		}
	}
}

//Getter functions
string Film::getFilmTitle() const {
	return title;
}

string Film::getFilmDirector() const {
	return director;
}

unsigned int Film::getFilmYear() const {
	return year;
}

unsigned int Film::getFilmDuration() const {
	return duration;
}

unsigned int Film::calculateAverageActorAge() const{
	if (noOfActors == 0) {
		return 0;
	}
	else {
		int sum = 0;		
		for (int i = 0; i < noOfActors; i++) {
			sum = sum + (year - actors[i].getBirthYear());			
		}
		return sum / noOfActors;
	}
}

bool Film::addActor(Actor& newActor){
	if (size == 0) {
		actors = new Actor[1];
		actors[0] = newActor;
		size++;
		noOfActors++;
		return true;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (newActor.getName() == actors[i].getName()) {
				return false;
			}
		}
		
		Actor* temp = actors;
		actors = new Actor[size + 1];
		
		for (int i = 0; i < size; i++) {
			actors[i] = temp[i];
		}
		
		actors[size] = newActor;
		
		size++;
		noOfActors++;

		if (temp) {
			delete[] temp;
		}
		return true;
	}
}

bool Film::removeActor(){
	if (size == 0) {
		return false;
	}
	else {
		if (actors) {
			delete[] actors;
		}
		actors = NULL;		
		noOfActors = 0;
		size = 0;
		return true;
	}

	
}

ostream& operator<<(ostream& out, const Film& f){
	out << f.getFilmTitle() << ", " << f.getFilmDirector() << ", " << f.getFilmYear() << ", " << f.getFilmDuration() <<  endl;
	if (f.actors) {
		for (int i = 0; i < f.noOfActors; i++) {
			out << "    " << f.actors[i];
		}
	}
	return out;
}
