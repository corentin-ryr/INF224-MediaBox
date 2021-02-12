#include "Group.h"

/**
 * @brief Print the name of the group and then it shows each media it contains.
 * 
 * @param s The output stream to print in.
 */
void Group::show(ostream &s) {
    s << this->getName() << "\n";

    list<shared_ptr<Media>>::iterator el = this->begin();
    for(; el != this->end(); el++) {
        (*el)->show(s);
    }

    
}
