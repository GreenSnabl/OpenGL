/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesh.h
 * Author: snbl
 *
 * Created on October 15, 2018, 9:29 PM
 */

#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }
    
    inline glm::vec3* getPos() { return &pos; }
    inline glm::vec2* getTexCoords() { return &texCoord; }
    
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
    
};

class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    void draw();    
    virtual ~Mesh();
    
private:
    Mesh(const Mesh& other) {}
    void operator=(const Mesh& other) {}
    
    enum
    {
        POSITION_VB,
        TEXCOORD_VB,        
        NUM_BUFFERS
    };
    
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[1];
    unsigned int m_drawCount;
};

#endif /* MESH_H */

