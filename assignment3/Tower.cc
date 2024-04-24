#include "Tower.h"

int Tower::nextId = 1;
const char Tower::code = 'T';

Tower::Tower(const Location& location):Entity(code, nextId++, location){
    this->location = location;
}

void Tower::print() const{
    cout << "Printing from Tower..." << endl;
    cout << "ID:                 " << id << endl;
    cout << "Location:           "; location.print();
    cout << endl;
    cout << "Number of Messages: " << Entity::getNumMessages() << endl;
}
