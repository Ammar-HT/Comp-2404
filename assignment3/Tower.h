#ifndef TOWER_H
#define TOWER_H

#include "Entity.h"

using namespace std;

class Tower: public Entity{

    public:
        static void resetId(){nextId = 1;}
        Tower(const Location& location = *(new Location(0,0)));
        void print()const;

    private:
        static const char code;
        static int nextId;

};
#endif