#ifndef FILM
#define FILM

#include <string>
#include <iostream>
#include "Video.h"

class Film : public Video
{
friend class MediaManager;

private:
    float* durations;
    int nbOfChapters = 0;
    Film(const string& name, const string& pathName, float* durations, int nbOfChapters);

public:
    ~Film();

    void setDurations (float* durations, int nbOfChapters);

    const float* getDurations() const;

    int getNumberOfChapters() const;

    void show(ostream &s) const;
};


#endif