#include "Media.h"


#pragma region Constructeur
Media::Media() {}

Media::Media(string name, string pathName) : name(name), pathName(pathName) { }

Media::~Media()
{ }

#pragma endregion

#pragma region Setters / Getters
void Media::setName(string name)
{
    Media::name = name;
}

void Media::setPathName(string pathName)
{
    Media::pathName = pathName;
}

string Media::getName() const
{
    return Media::name;
}

string Media::getPathName() const
{
    return Media::pathName;
}

#pragma endregion

void Media::show(ostream &out) const
{
    out
        << "Name: " << this->getName() << "\n"
        << "PathName: " << this->getPathName()
        << endl;
}
