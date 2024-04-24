#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Location.h"
#include "List.h"

using namespace std;


class Entity{

    public:
        //constructor
        Entity(const char&, int, const Location&);
        //destructor
        ~Entity();
        //member variables
        List* getMessageHistory() const;
        const Location& getLocation() const;
        void addMessage(const Message& m);
        int getNumMessages() const;
        bool equals(const string& id) const;
        void print() const;

    protected:
        string id;
        Location location;

    private:
        List messageHistory;

};

#endif
