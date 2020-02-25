
#include "obj.h"

int main(){
    wow::Obj obj;
    obj.appendVertex(  0,   0, 0);
    obj.appendVertex(100,   0, 0);
    obj.appendVertex(100, 100, 0);
    obj.appendVertex(  0, 100, 0);
    obj.closeFace();
    
    obj.output("quad");
}
