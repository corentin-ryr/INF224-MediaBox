#ifndef VIDEO
#define VIDEO

#include <string>
#include <iostream>
#include "Media.h"

class Video : public Media
{
friend class MediaManager;

private:
    int duration = 0;

protected:
    Video(const string& name, const string& pathName, int duration) : Media(name, pathName), duration(duration) { }
    Video() {};

public:
    ~Video(){ cout << "Delete video" << endl; }

    int getDuration() const {return duration;}

    void setDuration(int duration){this->duration = duration;}

    /**
     * @brief Print the name and pathName variables
     * 
     * @param s Output stream where the variables should be printed
     */
    void show(std::ostream &s) const override { 
        Media::show(s);
        s << "Duration: " << this->getDuration() << endl;
    }

    void play() const override {
        string argument = "mpv " + this->getPathName() + " &";
        system(argument.c_str());
    }

};

#endif
