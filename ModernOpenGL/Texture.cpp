/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.cpp
 * Author: snbl
 * 
 * Created on October 15, 2018, 10:19 PM
 */

#include "include/Texture.h"
#include "include/stb_image.h"
#include <cassert>
#include <iostream>

Texture::Texture(const std::string& fileName) 
{
    int width, height, numComponents;
    unsigned char* imageData = stbi_load((fileName).c_str(), &width, &height, &numComponents, 4);
    
    if (imageData == NULL)
        std::cerr << "Texture loading failed for texture: " << fileName << std::endl;
    
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);       // reading outside the texture width repeatedly
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);       // reading outside the texture height repeatedly
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   // What happens when the texture takes less pixels than our resolution -> linear interpolation
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   // What happens when the texture takes more pixels -> linear extrapolation
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);    
    
    stbi_image_free(imageData);
}



Texture::~Texture() 
{
    glDeleteTextures(1, &m_texture);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}