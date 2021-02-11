#ifndef PICTURE
#define PICTURE

#include <string>
#include <iostream>

#include "Media.h"

class Image : public Media
{
friend class MediaManager;

private:
    int width = 0;
    int height = 0;

    Image(const string& name, const string& pathName, int width, int height) : Media(name, pathName), width(width), height(height) {}

public:
    ~Image() { cout << "Delete image" << endl; }

    int getWidth() const {return width;}
    int getHeight() const {return height;}

    void setWidth(int width){this->width = width;}
    void setHeight(int height){this->height = height;}

    /**
     * @brief Print the name and pathName variables
     * 
     * @param s Output stream where the variables should be printed
     */
    void show(ostream &s) const override {
        Media::show(s);
        s << "Height: " << this->getHeight() << "\n" <<
             "Width: " << this->getWidth() << "\n" << endl;
    };

    void play() const override {
        string argument = "gimp " + this->getPathName() + " &";
        system(argument.c_str());
    }
};

#endif