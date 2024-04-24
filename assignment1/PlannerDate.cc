#include "PlannerDate.h"

PlannerDate::PlannerDate(Date& date){

	this->date = date;
	numEvents = 0;
	
}

PlannerDate::~PlannerDate(){

	for (int i=0; i<this->numEvents;i++){
		delete(events[i]);
	}

}

bool PlannerDate::equals(Date& d){

	return this->date.equals(d);

}

bool PlannerDate::equals(PlannerDate& d){

	return this->date.equals(d.date);

}
bool PlannerDate::lessThan(Date& d){

	return this->date.lessThan(d);

}
bool PlannerDate::lessThan(PlannerDate& d){

	return this->date.lessThan(d.date);

}

bool PlannerDate::addEvent(string title, string description, int startTime, int duration){
	
	if (numEvents >= 12){
		return false;
	}
	
	Event* newEvent = new Event(title,description,startTime,duration);
	
	int index = 0;
	
	while (index < numEvents){
		if (newEvent->lessThan(*events[index])){
			for (int i= numEvents; i > index; --i){
				events[i] = events[i-1];
			}
			break;
		}
		++index;
	
	}
	events[index] = newEvent;
	++numEvents;
	
	return true;
	

}
bool PlannerDate::hasEvent(string title){

	for(int i = 0; i < numEvents; i++){
		if (events[i]->getTitle() == title){
			return true;
		}
	}
	return false;

}
bool PlannerDate::hasConflict(){

	for (int i=0; i < numEvents -1; i++){
		for (int j=i+1; j < numEvents; j++){
			if (events[i]->conflictsWith(*events[j])){
				return true;
			}
		}
	}
	return false;

}

void PlannerDate::print(){

	for(int i=0;i< numEvents;i++){
		this->events[i]->print();
		this->date.print();
	}
	cout << "numEvents " << this->numEvents << endl;


}










