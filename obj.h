#pragma once
#include <string>
#include <cstdlib>
#include "vector.h"

class Vertex{
    Vec3 position;
    Vec2 texCoord;
    Vec3 normal;

public:
    Vertex(float x=0, float y=0, float z=0){
        position = {x, y, z};
        texCoord = {0, 0};
        normal = {x, y, z};
    }
    void setPosition(float x, float y, float z){
        position = {x, y, z};
    }
    void setTexCoord(float x, float y){
        texCoord = {x, y};
    }
    void setNormal(float x, float y, float z){
        normal = {x, y, z};
    }

    Vec3 getPosition(){ return position;}
    Vec2 getTexCoord(){ return texCoord;}
    Vec3 getNormal(){ return normal;}
};


class Face{
    int numIndices;
    Vec4i indices;

public:
    Face(int v0, int v1, int v2, int v3=-1){
        indices = {v0, v1, v2, v3};
        if(v3 == -1) numIndices = 3;
        else         numIndices = 4;
    }

    int getNumIndices(){return numIndices;}
    Vec4i getIndices(){return indices;}
};


// Obj
class Obj{
private:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
    int unusedVerticesCount;
    bool texCoordEnabled;
    bool normalEnabled;

public:
    Obj(): unusedVerticesCount(0), texCoordEnabled(false), normalEnabled(false){};

    void output(std::string filename){
        std::ofstream file(filename + ".obj");

        file << "# WaveFront *.obj file" << std::endl;
        file << "o " << filename << std::endl;

        int numVertices = vertices.size();
        // Position
        for(int i=0; i<numVertices; i++){
            Vec3 position = vertices[i].getPosition();
            file << std::fixed;
            file << "v " << position.x << " " << position.y << " " << position.z << std::endl;
        }
        // Texture Coordinate
        if(texCoordEnabled){
            for(int i=0; i<numVertices; i++){
                Vec2 texCoord = vertices[i].getTexCoord();
                file << "vt " << texCoord.x << " " << texCoord.y << std::endl;
            }
        }
        // Normal
        if(normalEnabled){
            for(int i=0; i<numVertices; i++){
                Vec3 normal = vertices[i].getNormal();
                file << "vn " << normal.x << " " << normal.y << " " << normal.z << std::endl;
            }
        }

        // Face
        int numFaces = faces.size();
        if(texCoordEnabled && normalEnabled){
            for(int i=0; i<numFaces; i++){
                int num = faces[i].getNumIndices();
                Vec4i indices = faces[i].getIndices();

                file << "f ";
                file << indices.x+1 << "/" << indices.x+1 << "/" << indices.x+1 << " ";
                file << indices.y+1 << "/" << indices.y+1 << "/" << indices.y+1 << " ";
                file << indices.z+1 << "/" << indices.z+1 << "/" << indices.z+1 << " ";
                if(num == 4){
                    file << indices.w+1 << "/" << indices.w+1 << "/" << indices.w+1;
                }
                file << std::endl;
            }
        }
        else if(texCoordEnabled){
            for(int i=0; i<numFaces; i++){
                int num = faces[i].getNumIndices();
                Vec4i indices = faces[i].getIndices();

                file << "f ";
                file << indices.x+1 << "/" << indices.x+1 << " ";
                file << indices.y+1 << "/" << indices.y+1 << " ";
                file << indices.z+1 << "/" << indices.z+1 << " ";
                if(num == 4){
                    file << indices.w+1 << "/" << indices.w+1;
                }
                file << std::endl;
            }
        }
        else if(normalEnabled){
            for(int i=0; i<numFaces; i++){
                int num = faces[i].getNumIndices();
                Vec4i indices = faces[i].getIndices();

                file << "f ";
                file << indices.x+1 << "//" << indices.x+1 << " ";
                file << indices.y+1 << "//" << indices.y+1 << " ";
                file << indices.z+1 << "//" << indices.z+1 << " ";
                if(num == 4){
                    file << indices.w+1 << "//" << indices.w+1;
                }
                file << std::endl;
            }
        }
        else{ // position only
            for(int i=0; i<numFaces; i++){
                int num = faces[i].getNumIndices();
                Vec4i indices = faces[i].getIndices();

                file << "f ";
                file << indices.x+1 << " ";
                file << indices.y+1 << " ";
                file << indices.z+1 << " ";
                if(num == 4){
                    file << indices.w+1;
                }
                file << std::endl;
            }
        }
    }
    void appendVertex(Vertex vertex){
        vertices.push_back(vertex);
        unusedVerticesCount++;
    }
    void appendVertex(Vec3 vec){
        vertices.push_back(Vertex(vec.x, vec.y, vec.z));
        unusedVerticesCount++;
    }
    void appendVertex(float x, float y, float z){
        vertices.push_back(Vertex(x, y, z));
        unusedVerticesCount++;
    }
    void appendFace(Face face){
        faces.push_back(face);
        unusedVerticesCount = 0;
    }
    void appendFace(int v0, int v1, int v2, int v3=-1){
        faces.push_back(Face(v0, v1, v2, v3));
        unusedVerticesCount = 0;
    }
    void closeFace(){
        int numVertices = vertices.size();
        if(unusedVerticesCount == 3){
            Face face(numVertices-3, numVertices-2, numVertices-1);
            faces.push_back(face);
            unusedVerticesCount = 0;
        }
        else if(unusedVerticesCount == 4){
            Face face(numVertices-4, numVertices-3, numVertices-2, numVertices-1);
            faces.push_back(face);
            unusedVerticesCount = 0;
        }
        else{
            std::cout << "ERROR: Face must consists of 3 or 4 vertices." <<  std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    
    void enableTextureCoordinates(bool arg = true){
        texCoordEnabled = arg;
    }

    void enableNormal(bool arg = true){
        normalEnabled = arg;
    }
};