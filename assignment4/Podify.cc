#include "Podify.h"

Podify::~Podify(){
    for (int i = 0; i < podcasts.getSize(); ++i){
        for (int j = 0; j < podcasts[i]->getSize(); ++j){
            delete podcasts[i]->get(j);
        }
    }

    for (int i = 0; i < podcasts.getSize(); ++i){
        delete podcasts[i];
    }
}

void Podify::addPodcast(Podcast* podcast){
    podcasts += podcast;
}

void Podify::addEpisode(Episode* episode, const string& podcastTitle){

    int counter = 0;
    while (counter < podcasts.getSize()){
        if (podcasts[counter]->equals(podcastTitle)){
            podcasts[counter]->add(episode);
            return;
        }
        ++counter;
    }
    cout << "Could not find Podcast to add Episode !!!" << endl;

}

const Array<Podcast*>& Podify::getPodcasts() const{
    return podcasts;
}

Podcast* Podify::getPodcast(int index) const{
    if (index >= 0 && index <= podcasts.getSize()){
        return podcasts[index];
    }
    cout << "Error finding the podcast at that index!" << endl;
    return nullptr;
}

Podcast* Podify::getPodcast(const string& title) const{
    int i = 0;
    while (i < podcasts.getSize()){
        if (podcasts[i]->equals(title)){
            return podcasts[i];
        }
        ++i;
    }
    cout << "Error finding the podcast with the given title!" << endl;
    exit(1);

}

void Podify::getEpisodes(Search& search, Array<Episode*>& arrayOfEpisodes){

    for (int i = 0; i < podcasts.getSize(); ++i){
        for (int j = 0; j < podcasts[i]->getSize(); ++j){
            Episode* thisEpisode = podcasts[i]->get(j);
            if (search.matches(thisEpisode)){
                arrayOfEpisodes+= thisEpisode;
            }
        }
    }
}