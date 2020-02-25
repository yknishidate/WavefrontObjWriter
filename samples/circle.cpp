#include <cmath>
#include "../obj.h"
using namespace wow;
constexpr double PI = 3.14159265359;

LineObj createCircle(float rad = 100, int segments = 128){
    LineObj obj;

    for(int i=0; i<segments; i++){
        float x = cos(float(i)/segments * 2*PI) * rad;
        float y = sin(float(i)/segments * 2*PI) * rad;
        obj.appendVertex(x, y, 0);
    }

    obj.closeLine();
    return obj;
}

int main(){
    LineObj obj = createCircle();
    
    obj.output("circle");
}
