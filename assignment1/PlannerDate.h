#ifndef PLANNERDATE_H
#define PLANNERDATE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Event.h"

using namespace std;

class PlannerDate {

	public:
		//constructor
		PlannerDate(Date&);
		//Destructor
		~PlannerDate();
		bool equals(Date&);
		bool equals(PlannerDate&);
		bool lessThan(Date&);
		bool lessThan(PlannerDate&);
		
		bool addEvent(string title, string description, int startTime, int duration);
		bool hasEvent(string title);
		bool hasConflict();
	
		void print();
	private:
		Date date;
		Event* events[12];
		int numEvents;


};

#endif
