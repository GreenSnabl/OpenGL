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

#include "Shader.h"
#include "Display.h"

int main() {
    Display display(800, 600, "Hello World!");
    
    Shader shader("./res/basicShader");
    
    while (!display.isClosed())
    {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.Bind();
        
        display.update();
    }

}