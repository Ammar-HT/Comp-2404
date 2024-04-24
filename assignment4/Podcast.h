#ifndef PODCAST_H
#define PODCAST_H

#include "Array.h"
#include "Episode.h"

class Podcast{
    friend ostream& operator<<(ostream&, const Podcast&);
    public:
        //constructor
        Podcast(const string&, const string&);
        //member functions
        bool equals(const string& title) const;
        Episode* get(int index)const;
        int getSize() const;
        virtual void print(ostream&) const;
        virtual void printWithEpisodes(ostream&) const;
        void add(Episode*);


    private:
        Array<Episode*> episodes;
        string title;
        string host;
};

#endif