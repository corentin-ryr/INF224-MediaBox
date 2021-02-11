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

    // These two methods are only used by show and play
    shared_ptr<Media> searchMedia (const string& name);
    shared_ptr<Group> searchGroup (const string& name);
    
public:
    MediaManager();
    ~MediaManager();

    weak_ptr<Image> createImage(const string& name, const string& pathName, int width, int height);
    weak_ptr<Video> createVideo(const string& name, const string& pathName, int duration);
    weak_ptr<Film> createFilm(const string& name, const string& pathName, float* durations, int nbOfChapters);
    weak_ptr<Group> createGroup(const string& name);

    

    void show(ostream &out, const string& name);
    void playMedia(const string& name);

    void eraseMedia(const string& name);
    void eraseGroup(const string& name);
};





#endif // MEDIAMANAGER


