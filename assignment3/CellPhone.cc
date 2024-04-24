#include "CellPhone.h"

int CellPhone::nextId = 1;
const char CellPhone::code = 'C';

CellPhone::CellPhone(const string& number, const Location& location): Entity(code,nextId,location){
    this->number = number;
    this->location = location;
    nextId++;
}

void CellPhone::setLocation(const Location& newLocation){
    this->location = newLocation;
}

void CellPhone::getMessageWith(const string& id, List& messages) const{
    this->getMessageHistory()->getMessagesWith(id,messages);
}

void CellPhone::print() const{
    cout << "Printing..." << endl;
    cout << "Cell Phone ID:      " << id << endl;
    cout << "Phone number:       " << number << endl;
    cout << "Location:           "; location.print();
    cout << endl;
    cout << "Number of messages: " << getNumMessages() << endl;
}