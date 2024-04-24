#include "Message.h"

Message::Message(const string& sender, const string& receiver, const string& message){
    this->sender = sender;
    this->receiver = receiver;
    this->message = message;
}

string Message::getSender() const{
    return this->sender; 
}

string Message::getReceiver() const{
    return this->receiver;
}

void Message::print() const{
    cout << "Printing Message... " << endl;

    cout << "Sender:    " << sender << endl;
    cout << "Receiver:  " << receiver << endl;
    cout << "Message:   " << message << endl;
    cout << endl;
}