#ifndef APPMARKET_H
#define APPMARKET_H

#include "AppArray.h"
#include "App.h"

using namespace std;

class AppMarket {

    public:
        //constructor
        AppMarket();
        //destructor
        ~AppMarket();
        //other member functions
        bool addApp(const string& title, const string& description, const string& icon);
        bool deleteApp(int index);
        App* getApp(int index) const;
        void printApps() const;
        void printAppDetails(int index) const;

    private:
        AppArray apps;

};
#endif