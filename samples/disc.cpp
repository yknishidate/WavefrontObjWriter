
#define PI 3.14159265359
#include <cmath>
#include "../obj.h"

Obj createDisc(float rad=100, int div=32){
    Obj obj;

    // append vertices
    obj.appendVertex(0, 0, 0);      // center vertex
    for(int i=0; i<div; i++){
        float x = cos(float(i)/div * 2*PI)*rad;
        float y = sin(float(i)/div * 2*PI)*rad;
        obj.appendVertex(x, y, 0);
    }

    // append faces
    for(int i=0; i<div-1; i++){
        obj.appendFace(0, i+1, i+2);
    }
    obj.appendFace(0, div, 1);      // last face

    return obj;
}


int main(){
    Obj obj = createDisc();
    obj.output("disc");
}
