#include "Film.h"



Film::Film(const string& name, const string& pathName, float* durations, int nbOfChapters) : Video(name, pathName, 0)
{

    delete [] this->durations;
    this->durations = new float [nbOfChapters]; //TODO faire la copie proprement
    for (int i = 0; i < nbOfChapters; i++)
    {
        this->durations[i] = durations[i];
    }

    this->nbOfChapters = nbOfChapters;

    float totalDuration = 0;
    for (int i = 0; i < nbOfChapters; i++)
    {
        totalDuration += durations[i];
    }
    
    this->setDuration(totalDuration); 
    
}

Film::~Film()
{
    delete [] this->durations;
    cout << "Delete film" << endl; 
}

void Film::setDurations(float* durations, int nbOfChapters) {
    
    delete [] this->durations;
    this->durations = new float [nbOfChapters];
    for (int i = 0; i < nbOfChapters; i++) //TODO same
    {
        this->durations[i] = durations[i];
    }
    
    this->nbOfChapters = nbOfChapters;
}

const float* Film::getDurations() const {
    return this->durations;
}

int Film::getNumberOfChapters() const {
    return this->nbOfChapters;
}

void Film::show(ostream &s) const {
    Media::show(s);
    s << "Duration of the film chapters:";

    for (int i = 0; i < getNumberOfChapters(); i++)
    {
        s << "\nChapter duration: " << this->durations[i];
    }
    
    s << "\n" << endl;
}






