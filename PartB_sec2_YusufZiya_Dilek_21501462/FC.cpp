#include "FC.h"

FC::FC() {
	size = 0;
	noOfFilms = 0;
	films = NULL;
}

FC::FC(const FC& fcToCopy) {
	size = fcToCopy.size;
	noOfFilms = fcToCopy.noOfFilms;
	if (size <= 0) {
		films = NULL;
	}
	else {
		films = new Film[size];
		for (int i = 0; i < size; i++) {
			films[i] = fcToCopy.films[i];
		}
	}
}

FC::~FC() {
	if (films) {
		delete[] films;
	}
}

void FC::operator=(const FC& right) {
	size = right.size;
	noOfFilms = right.noOfFilms;
	if (size <= 0) {
		films = NULL;
	}
	else {
		films = new Film[size];
		for (int i = 0; i < size; i++) {
			films[i] = right.films[i];
		}
	}
}

bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration){
	bool flag = true;
	for (int i = 0; i < size; i++) {
		if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector) {
			flag = false;
		}
	}

	if (!flag) {
		return false;
	}
	else {
		Film* temp = films;
		films = new Film[size + 1];

		for (int i = 0; i < size; i++) {
			films[i] = temp[i];
		}

		Film* temp2 = new Film(fTitle, fDirector, fYear, fDuration);
		films[size] = *temp2;

		size++;
		noOfFilms++;

		if (temp)
			delete[] temp;
		if (temp2)
			delete temp2;

		return true;
	}
}

bool FC::removeFilm(const string fTitle, const string fDirector) {
	if (size == 0 || noOfFilms == 0) {
		return false;
	}
	else {
		int deleteIndex = -1;
		for (int i = 0; i < size; i++) {
			if (fTitle == films[i].getFilmTitle() && fDirector == films[i].getFilmDirector()) {
				deleteIndex = i;
			}
		}

		if (deleteIndex == -1) {
			return false;
		}
		else {
			Film* temp = films;
			films = new Film[size - 1];

			for (int i = 0; i < deleteIndex; i++) {
				films[i] = temp[i];
			}
			for (int i = deleteIndex + 1; i < size; i++) {
				films[i - 1] = temp[i];
			}

			size--;
			noOfFilms--;

			if (temp)
				delete[] temp;

			return true;
		}
	}
	return false;
}

unsigned int FC::getFilms(Film*& allFilms) const {

	allFilms = new Film[size];

	for (int i = 0; i < size; i++) {
		allFilms[i] = films[i];
	}

	return noOfFilms;
}

bool FC::addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace, const unsigned int aBirthYear){

	for (int i = 0; i < size; i++) {
		if (fTitle == films[i].getFilmTitle() && fDirector == films[i].getFilmDirector()) {
			Actor* newAct = new Actor(aName, aBirthPlace, aBirthYear);
			if (films[i].addActor(*newAct)) {
				if (newAct) {
					delete newAct;
				}
				return true;
			}
			else {
				return false;
			}
		}	
	}


	return false;
}

bool FC::removeActors(const string fTitle, const string fDirector){
	for (int i = 0; i < size; i++) {
		if (fTitle == films[i].getFilmTitle() && fDirector == films[i].getFilmDirector()) {
			if (films[i].removeActor()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

unsigned int FC::calculateAverageDuration() const{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + films[i].getFilmDuration();
	}
	return (sum / noOfFilms);
}
