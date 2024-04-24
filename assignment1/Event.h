#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Event {

	public:
		//constructor
		Event(string title, string description, int startTime, int duration);
		
		bool equals(Event&);
		bool lessThan(Event& e);
		bool conflictsWith(Event& e);
		
		//getter
		string getTitle();
		
		//print function
		void print();
	
	
	private:
		string title;
		string description;
		//start time between 0 and 23
		int startTime;
		//duration in hours
		int duration;


};
#endif
