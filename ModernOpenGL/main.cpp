/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on October 15, 2018, 8:23 PM
 */

#include <GL/glew.h>
#include "include/Shader.h"
#include "include/Display.h"
#include "include/Mesh.h"
#include "include/Texture.h"


int main() {
    Display display(800, 600, "Hello World!");
    
    Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, 0),    glm::vec2(0.0, 0.0)),
                            Vertex(glm::vec3(0, 0.5, 0),        glm::vec2(0.5, 1.0)),
                            Vertex(glm::vec3(0.5, -0.5, 0),     glm::vec2(1.0, 0.0))};
    
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    
    Shader shader("./res/basicShader");
    Texture texture("./res/yee.png");
    
    while (!display.isClosed())
    {
        display.clear(0.0f, 0.50f, 0.3f, 1.0f);
        
        shader.bind();
        texture.bind();        
        mesh.draw();
        
        display.update();
    }

}