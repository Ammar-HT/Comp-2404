#include "PodcastPlayer.h"
#include <fstream>

void AudioPlayer::play(const Episode& m, ostream& ost){
    ost << m.getAudio();
}

void VideoPlayer::play(const Episode& m, ostream& ost){
    ost << m.getAudio();
    ifstream infile(m.getVideoFile());

    if (!infile){
        cout << "Error: could not open file" << endl;
        exit(1);
    }

    string line;
    while(getline(infile,line)){
        ost << line << endl;
    }
    infile.close();

}

// ostream& operator<<(ostream& ost, const Episode& episode){
//     episode.print(ost);
//     return ost;
// }