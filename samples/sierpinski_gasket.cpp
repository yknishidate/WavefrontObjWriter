#define PI 3.14159265359
#include <cmath>
#include "../obj.h"

void addSierpinskiGasket(Obj& obj, Vec2 startPoint = Vec2(0, 0), float len = 100, float minimum = 1){
    if(len < minimum) return;

    // v0 (bottom)
    float x = startPoint.x + len/2.0;
    float y = startPoint.y;
    obj.appendVertex(x, y, 0);
    Vec2 nextPoint0(x, y);

    // v1 (right top)
    x = startPoint.x + len * 3.0/4.0;
    y = startPoint.y + len * std::sqrt(3)/4.0;
    obj.appendVertex(x, y, 0);

    // v2 (left top)
    x = startPoint.x + len/4.0;
    y = startPoint.y + len * std::sqrt(3)/4.0;
    obj.appendVertex(x, y, 0);
    Vec2 nextPoint1(x, y);

    obj.closeFace();

    addSierpinskiGasket(obj, startPoint, len/2.0, minimum);
    addSierpinskiGasket(obj, nextPoint0, len/2.0, minimum);
    addSierpinskiGasket(obj, nextPoint1, len/2.0, minimum);

    return;
}

int main(){
    Obj obj;
    addSierpinskiGasket(obj); 
    obj.output("sierpinski_gasket");
}
