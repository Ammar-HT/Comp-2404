#include "Device.h"

Device::Device(const string& name, const string& deviceType, const string& os){
    this->name = name;
    this->deviceType = deviceType;
    this->os = os;
    AppArray arrayOfApps; 
}

Device::~Device(){
    for (int i = 0; i < arrayOfApps.size(); ++i) {
        App* app = arrayOfApps.get(i);
        delete app;
    }
}

string Device::getName() const{
    return name;
}

bool Device::equals(const string& name) const{
    return this->name == name;
}

bool Device::addApp(App newApp){
    if (arrayOfApps.isFull()) return false;
    App* copy = new App(newApp);
    return arrayOfApps.add(copy);
}

bool Device::deleteApp(const string& title){
    App* removingApp = arrayOfApps.remove(title); 
    if (removingApp) {
        delete removingApp;
        return true;
    }
    return false;
}

void Device::cloneApps(const Device& other){
    for (int i = 0; i < arrayOfApps.size(); ++i) {
        App* app = arrayOfApps.remove(0);
        delete app;
    }
    // Copy apps from the other Device
    for (int i = 0; i < other.arrayOfApps.size(); ++i) {
        App* otherApp = other.arrayOfApps.get(i);
        if (otherApp) {
            App* appCopy = new App(*otherApp); 
            addApp(*appCopy); 
            delete appCopy;
        }
    }
}

int Device::numApps() const{
    return arrayOfApps.size();
}

void Device::print() const{
    cout << "Name:         " << name       << endl;
    cout << "Device Type:  " << deviceType << endl;
    cout << "OS:           " << os         << endl;
    cout << "Apps:         " << arrayOfApps.size() << endl;
}

void Device::printWithApps() const{
    print();
    cout <<"Printing apps: " << endl;
    for (int i = 0; i < arrayOfApps.size(); i++){
        arrayOfApps.get(i)->printWithIcon();
    }
}