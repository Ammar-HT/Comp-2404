#include "Podcast.h"

Podcast::Podcast(const string& title, const string& host){
    this->title = title;
    this->host = host;
}

bool Podcast::equals(const string& title) const{
    return this->title == title;
}

Episode* Podcast::get(int index) const{
    return episodes[index];
}

int Podcast::getSize() const{
    return episodes.getSize();
}

void Podcast::print(ostream& ost) const{

    ost << "Podcast Title: " << this->title << endl;
    ost << "Host:          " << this->host << endl;
}

void Podcast::printWithEpisodes(ostream& ost) const{
    print(ost);
    for (int i = 0; i < episodes.getSize(); ++i){
        episodes[i]->print(ost);
    }
    
}

void Podcast::add(Episode* episode){
    if (episodes.isFull()){
        cout << "Full!! Cannot add more!!"<< endl;
        return;
    }else{
        episodes += episode;
    }
}

ostream& operator<<(ostream& ost, const Podcast& podcast){
    podcast.print(ost);
    return ost;
}