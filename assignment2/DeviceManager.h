#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "DeviceArray.h"
#include "Device.h"

using namespace std;

class DeviceManager{

    public:
        //constructor
        DeviceManager();
        //destructor
        ~DeviceManager();
        //other member functions
        bool addDevice(const string& name, const string& deviceType, const string& os);
        void deleteDevice(int index);
        Device* getDevice(int index) const;
        void cloneDevice(int cloneTo, int cloneFrom);
        void printDevices() const;
        void printDeviceDetails(int index) const;

    private:
        DeviceArray devices;
        
};
#endif