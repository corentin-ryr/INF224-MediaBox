#include "Group.h"

void Group::show(ostream &s) {
    s << this->getName() << "\n";

    list<shared_ptr<Media>>::iterator el = this->begin();
    for(; el != this->end(); el++) {
        (*el)->show(s);
    }

    
}
