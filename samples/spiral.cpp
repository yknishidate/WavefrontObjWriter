#include <cmath>
#include "../obj.h"
using namespace wow;
constexpr double PI = 3.14159265359;

LineObj createSimpleSpiral(Vec3 startPoint = Vec3(0, 0, 0), float maxRad = 100, float numLaps = 2, int segments = 128){
    LineObj obj;

    float rad = 0;
    for(int i=0; i<segments; i++){
        float x = cos(float(i)/segments * 2*PI * numLaps)*rad;
        float y = sin(float(i)/segments * 2*PI * numLaps)*rad;
        obj.appendVertex(x, y, 0);
        rad += maxRad / segments;
    }

    obj.finishLine();
    return obj;
}


LineObj createSpiral(Vec3 startPoint = Vec3(0, 0, 0), float maxRad = 100, float numLaps = 2, int segments = 128){
    LineObj obj;

    float rad = 0;
    for(int i=0; i<segments; i++){
        float x = cos(float(i)/segments * 2*PI * numLaps)*rad;
        float y = sin(float(i)/segments * 2*PI * numLaps)*rad;
        obj.appendVertex(x, y, 0);
        rad += maxRad / segments;
    }
    obj.finishLine();
    
    // decoration
    int d = 10;
    for(int i=0; i<segments-d; i++){
        obj.appendLine(i, i+d);
    }

    return obj;
}

int main(){
    LineObj obj = createSpiral();
    
    obj.output("spiral");
}
