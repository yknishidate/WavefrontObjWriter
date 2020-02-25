#pragma once
#include <string>
#include <cstdlib>
#include "vector.h"

namespace wow{
class Vertex{
    Vec3 position;
    Vec2 texCoord;
    Vec3 normal;

public:
    Vertex(const float& x=0, const float& y=0, const float& z=0)
        : position(x, y, z), texCoord(0, 0), normal(x, y, z){}
    void setPosition(const float& x, const float& y, const float& z){
        position = {x, y, z};
    }
    void setTexCoord(const float& x, const float& y){
        texCoord = {x, y};
    }
    void setNormal(const float& x, const float& y, const float& z){
        normal = {x, y, z};
    }

    Vec3 getPosition(){ return position;}
    Vec2 getTexCoord(){ return texCoord;}
    Vec3 getNormal(){ return normal;}
};


class Face{
    std::int32_t numIndices;
    Vec4i indices;

public:
    Face(const std::int32_t& v0, const std::int32_t& v1, const std::int32_t& v2, const std::int32_t& v3=-1)
        : indices(v0, v1, v2, v3){
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
    std::int32_t unusedVerticesCount;
    bool texCoordEnabled;
    bool normalEnabled;

public:
    Obj(): unusedVerticesCount(0), texCoordEnabled(false), normalEnabled(false){};

    void output(const std::string& filename){
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
    void appendVertex(const Vertex& vertex){
        vertices.push_back(vertex);
        unusedVerticesCount++;
    }
    void appendVertex(const Vec3& vec){
        vertices.push_back(Vertex(vec.x, vec.y, vec.z));
        unusedVerticesCount++;
    }
    void appendVertex(const float& x, const float& y, const float& z){
        vertices.push_back(Vertex(x, y, z));
        unusedVerticesCount++;
    }
    void appendFace(const Face& face){
        faces.push_back(face);
        unusedVerticesCount = 0;
    }
    void appendFace(const std::int32_t& v0, const std::int32_t& v1, const std::int32_t& v2, const std::int32_t& v3=-1){
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
    
    void enableTextureCoordinates(const bool& arg = true){
        texCoordEnabled = arg;
    }

    void enableNormal(const bool& arg = true){
        normalEnabled = arg;
    }
};
}