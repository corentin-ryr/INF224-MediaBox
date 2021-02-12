
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

weak_ptr<Group> MediaManager::createGroup(const string& name) {
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


/**
 * @brief Show the media or group corresponding to the name in the specified output stream.
 * 
 * @param out 
 * @param name 
 */
void MediaManager::show(ostream &out, const string& name) {
    shared_ptr<Media> media = this->searchMedia(name);
    shared_ptr<Group> group = this->searchGroup(name);

    if (media)
    {
        media->show(out);
    }   
    else if(group)
    {
        group->show(out);
    }
    else 
    {
        out << "No media were found" << endl;
    }
        
}

/**
 * @brief Play the media correspsonding to the name in the correct application
 * 
 * @param name 
 */
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

/**
 * @brief Delete the media from all the groups and from the list of media
 * 
 * @param name Name on the media to delete.
 */
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

/**
 * @brief Delete the specified group
 * 
 * @param name 
 */
void MediaManager::eraseGroup(const string& name) {
    groupMap.erase(name); //Erasing the group will call its destructor which in turn call the destructor of all its media (no need to iterate the group)
}


