#ifndef PODIFY_H
#define PODIFY_H

#include "Array.h"
#include "Podcast.h"
#include "Search.h"

class Podify{

    public:
        //destructor
        ~Podify();

        //member functions
        void addPodcast(Podcast*);
        void addEpisode(Episode*, const string&);
        const Array<Podcast*>& getPodcasts() const;
        Podcast* getPodcast(int index) const;
        Podcast* getPodcast(const string& title)const;
        void getEpisodes(Search&, Array<Episode*>&);

    private:
        Array<Podcast*> podcasts;

};

#endif