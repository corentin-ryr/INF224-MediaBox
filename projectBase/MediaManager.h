#if !defined(MEDIAMANAGER)
#define MEDIAMANAGER

#include<map>
#include <algorithm>

#include "Group.h"
#include "Media.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class MediaManager
{
private:
    map<string, shared_ptr<Group>> groupMap;
    map<string, shared_ptr<Media>> mediaMap;
    
public:
    MediaManager();
    ~MediaManager();

    shared_ptr<Image> createImage(string name, string pathName, int width, int height);
    shared_ptr<Video> createVideo(string name, string pathName, int duration);
    shared_ptr<Film> createFilm(string name, string pathName, float* durations, int nbOfChapters);
    shared_ptr<Group> createGroup(string name);

    shared_ptr<Media> searchMedia (string name);
    shared_ptr<Group> searchGroup (string name);

    void show(string name);
    void playMedia(string name);

    void erase(string name);
};









#endif // MEDIAMANAGER


