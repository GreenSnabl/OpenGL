/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Display.cpp
 * Author: snbl
 * 
 * Created on October 15, 2018, 8:56 PM
 */

#include "include/Display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title) {
    // First we need to initialzie SDL
    // usually you wouldn't initialize SDL in the Display class, but we only use it for the window so hack away
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);                    // Creates 2^8 shades of red
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8); 
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); 
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); 
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);               // make the window drawable by Open_GL
    GLenum status = glewInit();
    
    if (status != GLEW_OK)
    {
        std::cerr << "Glew failed to initialize" << std::endl;
    }
    m_isClosed = false;
}

Display::~Display() {
    
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


void Display::clear(float r, float g, float b, float a) 
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::isClosed() {
    return m_isClosed;
}


void Display::update()
{
    SDL_GL_SwapWindow(m_window);
    SDL_Event e;
    
    while(SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            m_isClosed = true;      
    }
}