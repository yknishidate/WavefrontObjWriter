#define PI 3.14159265359

#include <cmath>
#include "../obj.h"

void addCube(Obj &obj, Vec3 centerPoint, float size, int &index){
    obj.appendVertex(centerPoint + Vec3(-1.0, -1.0, -1.0) * size);
    obj.appendVertex(centerPoint + Vec3( 1.0, -1.0, -1.0) * size);
    obj.appendVertex(centerPoint + Vec3( 1.0, -1.0,  1.0) * size);
    obj.appendVertex(centerPoint + Vec3(-1.0, -1.0,  1.0) * size);
    obj.appendVertex(centerPoint + Vec3(-1.0,  1.0, -1.0) * size);
    obj.appendVertex(centerPoint + Vec3( 1.0,  1.0, -1.0) * size);
    obj.appendVertex(centerPoint + Vec3( 1.0,  1.0,  1.0) * size);
    obj.appendVertex(centerPoint + Vec3(-1.0,  1.0,  1.0) * size);

    obj.appendFace(index + 0, index + 4, index + 5, index + 1);
    obj.appendFace(index + 1, index + 5, index + 6, index + 2);
    obj.appendFace(index + 7, index + 6, index + 5, index + 4);
    obj.appendFace(index + 0, index + 1, index + 2, index + 3);
    obj.appendFace(index + 4, index + 0, index + 3, index + 7);
    obj.appendFace(index + 6, index + 7, index + 3, index + 2);
    index += 8;
}

void addMengerSponge(Obj &obj, Vec3 centerPoint, float size, int &index){
    
    if(size < 1) return;

    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            for(int k=-1; k<2; k++){
                Vec3 point = centerPoint + Vec3(i, j, k)*size*2;
                if(std::abs(i)+std::abs(j)+std::abs(k) <= 1)
                    addCube(obj, point, size, index);
                else
                    addMengerSponge(obj, point, size/3.0, index);
            }
        }
    }

}

int main(){
    Obj obj;
    int index = 0;
    addMengerSponge(obj, Vec3(0, 0, 0), 10, index); 
    obj.output("menger_sponge");
}
