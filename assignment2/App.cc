#include "App.h"

App::App(const string& title, const string& description, const string& icon){
    this->title = title;
    this->description = description;
    this->icon = icon;

}
App::App(){
    title = "default";
    description = "default";
    icon = "default";
}

string App::getTitle() const { return title;}

bool App::equals(const string& title) const{
    return title == title;
}

void App::print() const{

    cout << "Title:          " << title << endl;
    cout << "Description:    " << description << endl;

}

void App::printWithIcon() const{

    cout << "Title:          " << title << endl;
    cout << "Description:    " << description << endl;
    cout << "Icon:           " << icon << endl;

}