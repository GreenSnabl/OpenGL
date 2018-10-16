/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.h
 * Author: snbl
 *
 * Created on October 15, 2018, 10:19 PM
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>

class Texture {
public:
    Texture(const std::string& fileName);
    
    void bind();
    
    virtual ~Texture();
private:
    Texture(const Texture& other);
    void operator=(const Texture& other) {}
    
    GLuint m_texture;
};

#endif /* TEXTURE_H */

