//
// main.cpp
// Created on 21/10/2018
//

#include <list>
#include <iostream>
using namespace std;


#include "Video.h"
#include "Film.h"
#include "Image.h"
#include "Group.h"
#include "MediaManager.h"

const int PORT = 3331;

int main(int argc, const char *argv[])
{

    MediaManager * manager = new MediaManager();

    shared_ptr<Image> image = manager->createImage("image", "/home/corentin/Documents/inf224/assets/image.png", 100, 200);
    // float durations [2] = {10, 20};
    // shared_ptr<Film> film = manager->createFilm("film", "path",  durations, 2);

    shared_ptr<Group> group = manager->createGroup("Group Name");
    // group->push_front(film);
    group->push_front(image);

    cout << "\n Show the image : \n";
    cout << "TEST SEARCH 1: " << image.use_count() << endl;
    manager->show("image");

    cout << "\n Show the group : \n";
    manager->show("Group Name");


    manager->erase("image");
    cout << "TEST SEARCH 4: " << image.use_count() << endl;

    delete(manager);



    return 0;
}
