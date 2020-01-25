#ifndef __SIMPLE_FILM_H 
#define __SIMPLE_FILM_H 

#include <string> 
#include <iostream> 
//@author Yusuf Ziya Dilek ID:21501462
using namespace std;


class Film {
public:    Film(const string fTitle = "", const string fDirector = "", const unsigned int fYear = 0, const unsigned int fDuration = 0);
		   Film(const Film& fToCopy);   
		   ~Film();
		   void operator=(const Film& right);
		   string getTitle() const;
		   string getDirector() const;
		   unsigned int getYear() const;
		   unsigned int getDuration() const;

		   friend ostream& operator<<(ostream& out, const Film& f);

private:    string title;   
			string director;  
			unsigned int year;  
			unsigned int duration;
};
#endif
