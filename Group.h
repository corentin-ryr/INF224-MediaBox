#if !defined(GROUP)
#define GROUP

#include <list>
#include <iostream>
using namespace std;
#include <memory>

#include "Media.h"

class Group : public list<shared_ptr<Media>>
{
friend class MediaManager;

private:
    string name;

    Group(string name) : list<shared_ptr<Media>>() { this->name = name; };

public:
    ~Group() { cout << "Delete group" << endl;  };

    string getName() const {return this->name; };

    void show(ostream &s);
};



#endif // GROUP
