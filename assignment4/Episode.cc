#include "Episode.h"


Episode::Episode(const string& podcastTitle, const string& host, const string& episodeTitle, const string& category, const string& audio, const string& videoFile){
    this->podcastTitle = podcastTitle;
    this->host = host;
    this->episodeTitle = episodeTitle;
    this->category = category;
    this->audio = audio;
    this->videoFile = videoFile;
}

const string& Episode::getPodcastTitle()const{return this->podcastTitle;}
const string& Episode::getHost()const{return this->host;}
const string& Episode::getEpisodeTitle()const{return this->episodeTitle;}
const string& Episode::getCategory()const{return this->category;}
const string& Episode::getAudio()const{return this->audio;}
const string& Episode::getVideoFile()const{return this->videoFile;}

void Episode::print(ostream& ost) const{

    ost << "Podcast Title:  " << this->podcastTitle << endl;
    ost << "Host:           " << this->host << endl;
    ost << "Category:       " << this->category << endl;
    ost << "Episode Title:  " << this->episodeTitle << endl;
}

ostream& operator<<(ostream& ost, const Episode& episode){
    episode.print(ost);
    return ost;
}