#define PI 3.14159265359
#include <cmath>
#include "../obj.h"

Obj createQuad(Vec3 startPoint, float len){
    Obj obj;

    Vertex vertex;
    vertex.setNormal(0, 0, -1);

    vertex.setPosition(startPoint.x, startPoint.y, 0);
    vertex.setTexCoord(0, 0);
    obj.appendVertex(vertex);

    vertex.setPosition(startPoint.x + len, startPoint.y, 0);
    vertex.setTexCoord(1, 0);
    obj.appendVertex(vertex);
    
    vertex.setPosition(startPoint.x + len, startPoint.y + len, 0);
    vertex.setTexCoord(1, 1);
    obj.appendVertex(vertex);
    
    vertex.setPosition(startPoint.x, startPoint.y + len, 0);
    vertex.setTexCoord(0, 1);
    obj.appendVertex(vertex);

    obj.closeFace();

    return obj;
}

int main(){
    Obj obj = createQuad(Vec3(0,0,0), 100);
    obj.enableTextureCoordinates();
    obj.enableNormal();
    
    obj.output("quad");
}
