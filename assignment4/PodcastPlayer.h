#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include "Episode.h"


class PodcastPlayer{
    //friend ostream& operator<<(ostream&, const PodcastPlayer&);
    public:
        virtual void play(const Episode&, ostream& ) = 0;

};

class AudioPlayer : public virtual PodcastPlayer{

    public:
        virtual void play(const Episode&, ostream&);
};

class VideoPlayer: public virtual AudioPlayer{

    public:
        virtual void play(const Episode&, ostream&);

};

#endif