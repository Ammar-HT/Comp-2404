#ifndef PLANNER_H
#define PLANNER_H

#include "PlannerDate.h"

using namespace std;

class Planner {

	public:
		//constructor
		Planner();
		//destructor
		~Planner();
		
		//functions for adding Events
		void addEvent(string title, string description, Date& date, int startTime, int duration);
		void addDailyEvent(string title, string description, Date& startDate, Date& endDate, int StartTime, int duration);
		void addWeeklyEvent(string title, string description, Date& startDate, Date& endDate, int startTime, int duration);
		
		//functions for printing;
		void printAllDates();
		void printDate(Date&);
		void printDatesInRange(Date& startDate, Date& endDate);
		void printDatesWithEvent(string title);
		void printDatesWithConflict();
	
	private:	
		//private functions
		PlannerDate* getDate(Date&);
		//member variables
		PlannerDate* planners[12];
		int numOfElements;

};

#endif
