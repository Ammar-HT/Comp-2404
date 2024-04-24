#ifndef NETWORK_H
#define NETWORK_H

#include "CellPhone.h"
#include "Tower.h"
#include <vector>

using namespace std;

class Network{

    public:
        //constructor
        Network();
        //destructor
        ~Network();
        //member functions
        void addCellPhone(const string&, const Location&);
        void addTower(const Location&);
        void routeMessage(const Message&);
        void moveCellPhone(const string&, const Location&);
        bool getMessageHistory(const string& id, const List** messages);
        void getMessagesWith(const string& id1, const string& id2, List& outputList);
        void resetIds() const;
        void printTowers() const;
        void printCellPhones() const;

    private:
        vector<CellPhone*> cellphones;
        vector<Tower*> towers;
        CellPhone* getCellPhone(const string& id, const vector<CellPhone*> cellphones) const;
        Tower* getTower(const string& id, const vector<Tower*> towers) const;
        Tower* findClosestTower(const Location& loc)const;
};

#endif