#include "AppMarket.h"

AppMarket::AppMarket(){
    AppArray apps;
}

AppMarket::~AppMarket(){
    for(int i = 0; i < apps.size(); i++){
        App* deleteThisApp = apps.get(i);
        delete deleteThisApp;
    }
}

bool AppMarket::addApp(const string& title, const string& description, const string& icon){
    App* newApp = new App(title,description,icon);
    if (apps.add(newApp)){
        cout << "New app added sucessfully!" << endl;
        return true;
    }
    cout<< "Unable to add new app!" << endl;
    return false;
}

bool AppMarket::deleteApp(int index){
    if (apps.get(index)){
        cout << "App " << apps.get(index)->getTitle() << " deleted " << endl;
        delete apps.remove(index);
        return true;
    }

    cout << "Could not delete app!" << endl;
    return false; 
}

App* AppMarket::getApp(int index) const{
    if (apps.get(index))
        return apps.get(index);
    
    cout << "App does not exist!" << endl;
    return nullptr;
}

void AppMarket::printApps() const{
    cout << "Apps: " << endl;
    for (int i = 0; i < apps.size(); i++){
        cout << i << ":" << endl;
        apps.get(i)->print();
        cout << endl;
    }
}

void AppMarket::printAppDetails(int index) const{
    apps.get(index)->printWithIcon();
}