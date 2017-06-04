#include "version.h"

Version::~Version(){}

ostream& operator<<(ostream& f, const Version& v){
    f<<v.getTitle()<<endl;
    f<<v.getDate_modif()<<endl;
    return f;
}
