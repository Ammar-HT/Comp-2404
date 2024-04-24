#include "Network.h"

Network::Network(){}

Network::~Network(){
    for (CellPhone* phone : cellphones) {
        delete phone;
    }
    cellphones.clear();
    
    for (Tower* tower : towers) {
        delete tower;
    }
    towers.clear();
}

void Network::addCellPhone(const string& number, const Location& location){
    CellPhone* newPhone = new CellPhone(number, location);
    cellphones.push_back(newPhone);
}

void Network::addTower(const Location& location){
    Tower* newTower = new Tower(location);
    towers.push_back(newTower);
}

void Network::routeMessage(const Message& message){
    string sender = message.getSender();
    string receiver = message.getReceiver();

    bool checkingForPhones = true;
    Tower* senderTower = nullptr;
    Tower* receiverTower = nullptr;
    for (CellPhone* phone : cellphones) {
        if(phone->equals(sender)){
            phone->addMessage(message);

            if(findClosestTower(phone->getLocation())&& findClosestTower(phone->getLocation())!= receiverTower){//checks null
                findClosestTower(phone->getLocation())->addMessage(message);
                senderTower = findClosestTower(phone->getLocation());
            }
            checkingForPhones = false;
        }
        if(phone->equals(receiver)){
            phone->addMessage(message);

            if(findClosestTower(phone->getLocation()) && findClosestTower(phone->getLocation())!= senderTower){//checks null
                findClosestTower(phone->getLocation())->addMessage(message); 
                receiverTower = findClosestTower(phone->getLocation());
            }
            checkingForPhones = false;
        }
    }
    if (checkingForPhones){
        cout<<"Could not find CellPhones!!!"<<endl;
    }
}

void Network::moveCellPhone(const string& id, const Location& location){
    int i=0;
    while (i < cellphones.size()){
        if (cellphones[i]->equals(id)){
            cellphones[i]->setLocation(location);
            cout << "Location updated successfully!" << endl;
            return;
        }
        i++;
    }
    cout << "Could not find cellphone to update the location!" << endl;
}

bool Network::getMessageHistory(const string& id, const List** messages){
    
    if (getCellPhone(id, cellphones)){
        *messages = getCellPhone(id,cellphones)->getMessageHistory();
        return true;
    }else if (getTower(id, towers)){
        *messages = getTower(id,towers)->getMessageHistory();
        return true;
    }
    cout << "Error finding message history!" << endl;
    return false;
    
}

void Network::getMessagesWith(const string& id1, const string& id2, List& outputList){
    int i = 0;
    while (i < cellphones.size()){
        cellphones[i]->getMessageHistory()->getMessagesWith(id1,id2,outputList);
        i++;
    }
    int j = 0;
    while (j < towers.size()){
        towers[j]->getMessageHistory()->getMessagesWith(id1,id2,outputList);
        j++;
    }
}

void Network::resetIds() const{
    CellPhone::resetId();
    Tower::resetId();
}

void Network::printTowers() const{
    int i = 0;
    while (i < towers.size()){
        towers[i]->print();
        i++;
    }
}

void Network::printCellPhones() const{
    int i = 0;
    while (i < cellphones.size()){
        cellphones[i]->print();
        i++;
    }
}

//private functions 

CellPhone* Network::getCellPhone(const string& id, const vector<CellPhone*> cellphones) const{
    for (CellPhone* phone : cellphones){
        if (phone->equals(id)){
            return phone;
        }
    }
    return nullptr;
}

Tower* Network::getTower(const string& id, const vector<Tower*> cellphones) const{
    for (Tower* tower : towers){
        if (tower->equals(id)){
            return tower;
        }
    }
    return nullptr;
}

Tower *Network::findClosestTower(const Location &location) const{
    int minDistance = 5;
    Tower* closestTower = nullptr;
    for (Tower* tower : towers) {
        if(tower->getLocation().getDistance(location) < minDistance){ //gets distance between tower and location
            minDistance = tower->getLocation().getDistance(location);
            closestTower = tower;
        }
    }
    return closestTower;
}