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

    weak_ptr<Image> createImage(const string& name, const string& pathName, int width, int height);
    shared_ptr<Video> createVideo(const string& name, const string& pathName, int duration);
    shared_ptr<Film> createFilm(const string& name, const string& pathName, float* durations, int nbOfChapters);
    shared_ptr<Group> createGroup(const string& name);

    shared_ptr<Media> searchMedia (const string& name);
    shared_ptr<Group> searchGroup (const string& name);

    void show(const string& name);
    void playMedia(const string& name);

    void erase(const string& name);
};









#endif // MEDIAMANAGER


