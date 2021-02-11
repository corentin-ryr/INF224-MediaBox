#ifndef MYCLASS
#define MYCLASS

#include <string>
#include <iostream>
using namespace std;

class Media
{

private:
    string name = "";
    string pathName = "";

protected: //To prevent the creation of a media object which is not an image, video...
    /**
     * @brief Construct a new My Class object without defining the variables
     * 
     */
    Media();

    /**
     * @brief Construct a new My Class object and defines the variables
     * 
     * @param name Name of the media
     * @param pathName Path of the media file
     */
    Media(const string& name, const string& pathName);

    ~Media();

public:
    string getName() const;
    string getPathName() const;

    void setName(const string& name);
    void setPathName(const string& pathName);

    /**
     * @brief Print the name and pathName variables
     * 
     * @param s Output stream where the variables should be printed
     */
    virtual void show(ostream &s) const;

    virtual void play() const = 0;
};

#endif
