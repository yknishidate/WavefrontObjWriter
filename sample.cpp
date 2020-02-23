
#include "obj.h"

Obj createQuad(Vec3 startPoint, float len){
    Obj obj;
    Vertex vertex;
    
    vertex.setPosition(startPoint.x, startPoint.y, 0);
    obj.appendVertex(vertex);

    vertex.setPosition(startPoint.x + len, startPoint.y, 0);
    obj.appendVertex(vertex);
    
    vertex.setPosition(startPoint.x + len, startPoint.y + len, 0);
    obj.appendVertex(vertex);
    
    vertex.setPosition(startPoint.x, startPoint.y + len, 0);
    obj.appendVertex(vertex);

    obj.closeFace();

    return obj;
}

int main(){
    Obj obj = createQuad(Vec3(0,0,0), 100);
    
    obj.output("quad");
}
