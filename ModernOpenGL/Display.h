/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Display.h
 * Author: snbl
 *
 * Created on October 15, 2018, 8:56 PM
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

class Display {
public:
    Display(int width, int height, const std::string& title);
    
    void clear(float r, float g, float b, float a);
    void update();
    bool isClosed();
    
    virtual ~Display();
private:
    Display(const Display& orig);
    void operator=(const Display& other) {}

    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};

#endif /* DISPLAY_H */

