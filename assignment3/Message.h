#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

using namespace std;

class Message{

    public:
        Message(const string& sender, const string& receiver, const string& message);

        string getSender() const;
        string getReceiver() const;
        void print() const;
        
    private:
        string sender;
        string receiver;
        string message;
};

#endif