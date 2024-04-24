#include "Entity.h"

Entity::Entity(const char& c, int num, const Location& location){

    id = c + to_string(num);
    this->location = location;
}

Entity::~Entity(){
    while (messageHistory.getSize() > 0){
        delete messageHistory.removeFirst();
    }
}

List* Entity::getMessageHistory() const{
    return (List*)&messageHistory;
}

const Location& Entity::getLocation() const{
    return location;
}

void Entity::addMessage(const Message& m){
    Message* copy = new Message(m);
    messageHistory.add(copy);
}

int Entity::getNumMessages() const{
    return messageHistory.getSize();
}

bool Entity::equals(const string& id) const{
    return this->id == id;
}

void Entity::print() const{
    cout << "Printing..." << endl;

    cout << "ID:                 " << id << endl;
    cout << "Location:           "; location.print(); 
    cout << endl;
    cout << "Number of Messages: " << getNumMessages() << endl;
}