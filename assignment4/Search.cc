#include "Search.h"

ostream& operator<<(ostream& ost, const Search& s){
    s.print(ost);
    return ost;
}

//H_Search Class
H_Search::H_Search(const string& host){
    this->host = host;
}

bool H_Search::matches(const Episode* other){
    return this->host == other->getHost();
}

void H_Search::print(ostream& ost) const{
    ost << "Host: " << this->host << endl;
}

//C_Search Class
C_Search::C_Search(const string& category){
    this->category = category;
}

bool C_Search::matches(const Episode* other){
    return this->category == other->getCategory();
}

void C_Search::print(ostream& ost) const{
    ost << "Category: " << this->category << endl;
}

//HorC_Search Class
HorC_Search::HorC_Search(const string& host, const string& category): H_Search(host), C_Search(category){}

bool HorC_Search::matches(const Episode* other){
    return H_Search::matches(other) || C_Search::matches(other);
}

void HorC_Search::print(ostream& ost)const{
    H_Search::print(ost); 
    C_Search::print(ost);
}