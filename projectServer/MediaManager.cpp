
#include "MediaManager.h"

MediaManager::MediaManager(/* args */)
{
}

MediaManager::~MediaManager()
{
    cout << "Manager deleted" << endl;
}


#pragma region Creation of media/group
weak_ptr<Image> MediaManager::createImage(const string& name, const string& pathName, int width, int height) {
    shared_ptr<Image> image (new Image(name, pathName, width, height));
    this->mediaMap[name] = image;
    return image;
}

weak_ptr<Video> MediaManager::createVideo(const string& name, const string& pathName, int duration) {
    shared_ptr<Video> video (new Video(name, pathName, duration));
    this->mediaMap[name] = video;
    return video;
}

weak_ptr<Film> MediaManager::createFilm(const string& name, const string& pathName, float* durations, int nbOfChapters) {
    shared_ptr<Film> film (new Film(name, pathName, durations, nbOfChapters));
    this->mediaMap[name] = film;
    return film;
}

shared_ptr<Group> MediaManager::createGroup(const string& name) {
    shared_ptr<Group> group (new Group(name));    
    this->groupMap[group->getName()] = group;
    return group;
}
#pragma endregion


#pragma region Search methods
shared_ptr<Media> MediaManager::searchMedia(const string& name) {
    map<string, shared_ptr<Media>>::iterator it = this->mediaMap.find(name);

    if (it != mediaMap.end())
    {
        return it->second;
    } 
    return nullptr;
}
shared_ptr<Group> MediaManager::searchGroup(const string& name) {
    map<string, shared_ptr<Group>>::iterator it = this->groupMap.find(name);

    if (it != groupMap.end())
    {
        return it->second;
    }
    return nullptr;
}
#pragma endregion



void MediaManager::show(const string& name) {
    shared_ptr<Media> media = this->searchMedia(name);
    shared_ptr<Group> group = this->searchGroup(name);

    if (media)
    {
        media->show(cout);
    }   
    else if(group)
    {
        group->show(cout);
    }
    else 
    {
        cout << "No media were found" << endl;
    }
        
}

void MediaManager::playMedia(const string& name) {
    shared_ptr<Media> media = this->searchMedia(name);
    if (media)
    {
        media->play();
    }   
    else
    {
        cout << "No media were found" << endl;
    }
}

void MediaManager::eraseMedia(const string& name) {
    //Reference to the media to erase
    shared_ptr<Media> mediaToErase = this->searchMedia(name);
    
    //We erase every occurence of the media in the media map
    mediaMap.erase(name);
    
    //We erase every occurence of the media in the groups
    for (auto it = groupMap.begin(); it != groupMap.end(); it++)
    {
        shared_ptr<Group> group = it->second;
        group->remove(mediaToErase);
    }
}


void MediaManager::eraseGroup(const string& name) {
    //Reference to the media to erase
    //shared_ptr<Group> groupToErase = this->searchGroup(name);
    
    // //We erase every occurence of the media in the groups
    // for (auto it = groupToErase.begin(); it != groupToErase.end(); it++)
    // {
    //     shared_ptr<Media> mediaToRemove = it->second;
    //     reset(mediaToRemove);
    // }

    // //We erase every occurence of the media in the media map
    groupMap.erase(name);
}


