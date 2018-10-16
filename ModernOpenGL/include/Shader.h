/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.h
 * Author: snbl
 *
 * Created on October 15, 2018, 8:23 PM
 */

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& fileName);
    
    void bind();
    
    virtual ~Shader();
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& orig) {}
    void operator=(const Shader& other) {}

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];

};

#endif /* SHADER_H */

