#ifndef CELLPHONE_H
#define CELLPHONE_H

#include "Entity.h"

using namespace std;

class CellPhone: public Entity{

    public:
        CellPhone(const string& number, const Location& location);
        void setLocation(const Location& newLocation);
        void getMessageWith(const string& id, List& messages) const;
        void print() const;
        static void resetId(){nextId = 1;}

    private:
        static const char code;
        static int nextId;
        string number;

};

#endif