#include "Event.h"

Event::Event(string title, string description, int startTime, int duration){

	this->title = title;
	this->description = description;
	//startTime
	if (startTime >= 0 && startTime <= 23){
		this->startTime = startTime;	
	}else{
		this->startTime = 0;
	}
	//duration
	if (duration < 1){
		this->duration = 1;
	}else{
		this->duration = duration;
	}

}

bool Event::equals(Event& e){

	return this->title == e.title;

}

bool Event::lessThan(Event& e){

	return startTime < e.startTime;

}

bool Event::conflictsWith(Event& e){
	//Calculate the endtime of this event
	int endTime = startTime + duration;
	//Compare the endtime of this event to event e startime
	bool conflict = endTime > e.startTime;
	
	return conflict; 

}

string Event::getTitle(){

	return title;
}


void Event::print(){

	cout << "Title:        " << title << endl;
	cout << "Description:  " << description << endl;
	cout << "Start time:   " << startTime << endl;
	cout << "Duration:     " << duration << endl;


}
