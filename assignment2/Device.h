#ifndef DEVICE_H
#define DEVICE_H

#include "AppArray.h"

using namespace std;

class Device{

    public:
        //constructor
        Device(const string&,const string&,const string&);
        //destructor
        ~Device();
        //member functions
        string getName() const;
        bool equals(const string& name) const;
        bool addApp(App app);
        bool deleteApp(const string& title);
        void cloneApps(const Device&);
        int numApps() const;
        void print() const;
        void printWithApps() const;

    private:
        string name;
        string deviceType;
        string os;
        AppArray arrayOfApps;
};
#endif