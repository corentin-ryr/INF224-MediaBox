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
    weak_ptr<Image> image2 = manager->createImage("image2", "/home/corentin/Documents/inf224/assets/image.png", 50, 60);
    float durations [2] = {10, 20};
    weak_ptr<Film> film = manager->createFilm("film", "path",  durations, 2);

    weak_ptr<Group> group = manager->createGroup("Group Name");
    group.lock()->push_front(film.lock());
    group.lock()->push_front(image.lock());

    weak_ptr<Group> group2 = manager->createGroup("Group Name 2");
    group2.lock()->push_front(film.lock());
    group2.lock()->push_front(image2.lock());




    // cree le TCPServer
    auto* server =
    new TCPServer( [&](string const& request, string& response) {

        // the request sent by the client to the server
        cout << "request: " << request << endl;

        // the response that the server sends back to the client
        response = "RECEIVED: " + request;

        //Create a string stream for the request
        stringstream ssRequest = stringstream(request);
        string action;
        string name;

        ssRequest >> action >> name;

        //Create a string stream for the response
        stringstream ssResponse;

        if (action == "search")
        {
            manager->show(ssResponse, name);

            response = ssResponse.str();
            response.erase(remove(response.begin(), response.end(), '\n'), response.end());
        }
        

        cout << response << endl;
        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

    delete(manager); //To prevent memory leak

    return 0;
}

