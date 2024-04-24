#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>

using namespace std;

class App {

    public:
        //constructor
        App(const string& title, const string& description, const string& icon);
        App();
        
        //getter
        string getTitle() const;
        //equals
        bool equals(const string& title) const;
        //print
        void print() const;
        void printWithIcon() const;

    private:
        string title;
        string description;
        string icon;

};
#endif