/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesh.cpp
 * Author: snbl
 * 
 * Created on October 15, 2018, 9:29 PM
 */

#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) 
{
    m_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    
    
    // Create a Buffer, tell OpenGL how to interpret it and put the data into it
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);                    // Generate buffers                        
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);   // Tells OpenGL to interpret this buffer as a vertex array
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW); // Take some data from ram, move it to GPU memory and interpret it as vertex array
    
    // Now we have to tell the GPU how to interpret the data
    glEnableVertexAttribArray(0);       // We tell OpenGL that there's an array for one of our attributes
    glVertexAttribPointer(  0,          // Here we tell OpenGL how that attribute array should be interpreted
                            3,          // 3 pieces of date because vec3
                            GL_FLOAT,   
                            GL_FALSE,
                            0,
                            0   );
    glBindVertexArray(0);
}


Mesh::~Mesh() 
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw()
{
    glBindVertexArray(m_vertexArrayObject);
    
    glDrawArrays(   GL_TRIANGLES, 
                    0,              // Where in the array do we want to start to draw?
                    m_drawCount     // Draw all the data
                );
    
    glBindVertexArray(0);
}