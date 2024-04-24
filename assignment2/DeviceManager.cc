#include "DeviceManager.h"

DeviceManager::DeviceManager(){
    DeviceArray devices;
}

DeviceManager::~DeviceManager(){
    for (int i=0; i< devices.size(); i++){
        Device* deleteDevice = devices.get(i);
        delete deleteDevice;
    }
}

bool DeviceManager::addDevice(const string& name, const string& deviceType, const string& os) {
    Device* newDevice = new Device(name,deviceType,os);
    if (devices.add(newDevice))
        return true;
    else
        cout << "Unable to add device!" << endl;
        return false;
}

void DeviceManager::deleteDevice(int index){
    if (devices.get(index)){
        cout << "Device " << devices.get(index)->getName() << " deleted" << endl;
        Device* deleteDevice = devices.remove(index);
        delete deleteDevice;
    }else{
        cout << "Unable to find device to delete!" << endl;
    }
}

void DeviceManager::cloneDevice(int cloneTo, int cloneFrom){
    if (devices.get(cloneFrom) && devices.get(cloneTo)){
        cout << "Neither are null " << endl;
        cout << "Cloning apps " << endl;
        devices.get(cloneTo)->cloneApps(*devices.get(cloneFrom));
        cout << "Device " << devices.get(cloneTo)->getName() <<" cloned" << endl;
    }else{
        cout << "Could not find device to clone!" << endl;
    }
}

Device* DeviceManager::getDevice(int index) const{
    if (devices.get(index)){
        return devices.get(index); 
    }
    cout << "Could not find device!" << endl;
    return nullptr;
}

void DeviceManager::printDevices() const{
    cout << "Devices: " << endl;
    for (int i = 0; i < devices.size(); i++){
        cout << i << ":" << endl;
        devices.get(i)->print();
        cout << endl;
    }
}

void DeviceManager::printDeviceDetails(int index) const{
    if (devices.get(index)){
        devices.get(index)->printWithApps();
    }else{
        cout << "Could not find device!" << endl;
    }
}