#include "List.h"

List::List(){
    head = NULL;
    tail = NULL;
    numMessages = 0;
}

List::~List(){
    Node* current;
    while (head != nullptr){
        current = head;
        head = head->next;
        delete current;
    }
}

bool List::isEmpty() const{
    return numMessages == 0;
}

int List::getSize() const{
    return numMessages;
}


Message *List::removeFirst(){
    Node* current = head;
    if(current){
        Message* goner = current->data;
        head = current->next; 
        delete current;
        --numMessages;
        return goner;
    }
    return nullptr;
}

void List::add(Message * message){
    Node* newNode = new Node;
    newNode->data = message;
    newNode->next = nullptr;
    if (head == nullptr) { //if empty then...
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++numMessages;
}

void List::print() const{
    cout << "Printing Messages from the list... " << endl;
    Node* current = head;
    while (current != nullptr){
        current->data->print();
        current = current->next;
    }
}

void List::getMessagesWith(const string& id, List& outputList){
    Node* current = head;
    while (current != nullptr){
        if (current->data->getSender() == id || current->data->getReceiver() == id){
            outputList.add(current->data);
        }
        current = current->next;
    }
}

void List::getMessagesWith(const string& id1, const string& id2, List& outputList){
    Node* current = head;
    while (current != nullptr){
        if (current->data->getSender() == id2 || current->data->getReceiver() == id1 ){
            outputList.add(current->data);
        }else if (current->data->getReceiver() == id2 && current->data->getSender() == id1){
            outputList.add(current->data);
        }
        current = current->next;
    }
}

bool List::removeMessagesWith(const string& id, List& outputList){
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr){
        Node* removing = current;
        if (current->data->getSender() == id || current->data->getReceiver() == id){
            outputList.add(current->data);
            if (previous == nullptr) {
                head = current->next;
                current = head;
            }else if (previous != nullptr){
                previous->next = current->next;
                current = current->next;
            }
            delete removing;
            --numMessages;
        }else{
            previous = current;
            current = current->next;
        }
    }
    return false;
}
