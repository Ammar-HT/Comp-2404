#include "Planner.h"

Planner::Planner(){

	numOfElements = 0;

}

Planner::~Planner(){

	for (int i=0; i<numOfElements;i++){
			delete(planners[i]);
		}

}

PlannerDate* Planner::getDate(Date& planner){
	//Checking if there is plannerDate that matches the given date.
	for (int index =0; index < numOfElements; index++){
		if (planners[index]->equals(planner)){
			return planners[index];
		}
	}
	//Create a new plannerdate and add it to the planners
	PlannerDate* newPlannerDate = new PlannerDate(planner);
	
	int position = 0;
	while (position < numOfElements){
		if (newPlannerDate->lessThan(*planners[position])){
			for (int i = numOfElements; i > position; --i){
				planners[i] = planners[i-1];
			}
			break;
		}
		++position;
	}
	
	planners[position] = newPlannerDate;
	++numOfElements;
	
	return planners[position];
}

void Planner::addEvent(string title, string description, Date& date, int startTime, int duration){

	if (numOfElements >= 12){
		cout << "There is no room for a new PlannerDate or Event." << endl;
	}else{
		
		PlannerDate* newPlannerDate = getDate(date);
		newPlannerDate->addEvent(title, description, startTime, duration);
		
	}

}

void Planner::addDailyEvent(string title, string description, Date& startDate, Date& endDate, int startTime, int duration){

	while ((startDate.lessThan(endDate))){
		addEvent(title, description, startDate, startTime, duration);
		
		startDate.incDate();
	}
}

void Planner::addWeeklyEvent(string title, string description, Date& startDate, Date& endDate, int startTime, int duration){

	while (startDate.lessThan(endDate)){
		addEvent(title, description, startDate, startTime, duration);
		
		startDate.addDays(7);
	}

}

void Planner::printAllDates(){

	for (int i=0; i<numOfElements; i++){
		planners[i]->print();
	}

}

void Planner::printDate(Date& givenDate){

	for (int i=0; i<numOfElements; i++){
		if (planners[i]->equals(givenDate)){
			planners[i]->print();
		}
	}
	cout << "No such PlannerDate exists." << endl;

}

void Planner::printDatesInRange(Date& startDate, Date& endDate){

	while (startDate.lessThan(endDate)){
		printDate(startDate);
		
		startDate.incDate();
	}

}

void Planner::printDatesWithEvent(string title){

	for (int i=0; i<numOfElements; i++){
		if (planners[i]->hasEvent(title)){
			planners[i]->print();
		}
	}

}

void Planner::printDatesWithConflict(){

	for (int i=0; i<numOfElements; i++){
		if (planners[i]->hasConflict()){
			planners[i]->print();
		}
	}

}




