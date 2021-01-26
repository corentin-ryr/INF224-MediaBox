//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
using namespace std;
#include <sstream>
#include "tcpserver.h"

#include "Video.h"
#include "Film.h"
#include "Image.h"
#include "Group.h"
#include "MediaManager.h"

const int PORT = 3331;


int main(int argc, char* argv[])
{
    MediaManager * manager = new MediaManager();

    weak_ptr<Image> image = manager->createImage("image", "/home/corentin/Documents/inf224/assets/image.png", 100, 200);
    float durations [2] = {10, 20};
    weak_ptr<Film> film = manager->createFilm("film", "path",  durations, 2);

    shared_ptr<Group> group = manager->createGroup("Group Name");
    group->push_front(shared_ptr<Film>(film));
    group->push_front(shared_ptr<Image>(image));

    cout << "\n Show the image : \n";
    manager->show("image");

    cout << "\n Show the group : \n";
    manager->show("Group Name");


    manager->erase("image");



    // // cree le TCPServer
    // auto* server =
    // new TCPServer( [&](string const& request, string& response) {

    //     // the request sent by the client to the server
    //     cout << "request: " << request << endl;

    //     // the response that the server sends back to the client
    //     response = "RECEIVED: " + request;

    //     // return false would close the connecytion with the client
    //     return true;
    // });


    // // lance la boucle infinie du serveur
    // cout << "Starting Server on port " << PORT << endl;

    // int status = server->run(PORT);

    // // en cas d'erreur
    // if (status < 0) {
    //     cerr << "Could not start Server on port " << PORT << endl;
    //     return 1;
    // }

    return 0;
}

