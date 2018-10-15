/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.cpp
 * Author: snbl
 * 
 * Created on October 15, 2018, 8:23 PM
 */
#include <iostream>
#include <fstream>
#include "Shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName) {
    m_program = glCreateProgram();
    
    // Create the shaders
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);    // Create a VERTEX_SHADER
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);  // Create a FRAGMENT_SHADER
    
    // Now add the shaders to our overarching programm
    for (unsigned int i = 0; i < NUM_SHADERS; ++i)
    {
        glAttachShader(m_program, m_shaders[i]);                                    // Attach the shaders to our program
    }
    
    
    // Before linking the program we need to bind 
    glBindAttribLocation(m_program, 0, "position");
    
    
    // We also need to link the shaders
    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");
    
    // At last we want to validate that everything worked out as expected
    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

}   


Shader::~Shader() {
    for (unsigned int i = 0; i < NUM_SHADERS; ++i)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    
    glDeleteProgram(m_program);
}

void Shader::Bind() {
    glUseProgram(m_program);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0)
        std::cerr << "Error: Shader creation failed!" << std::endl;
    
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];
    
    shaderSourceStringLengths[0] = text.length();
    shaderSourceStrings[0] = text.c_str();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);
    
    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");
    
    return shader;
}


static std::string LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());
    
    std::string output;
    std::string line;
    
    if (file.is_open())
    {
        while (file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }
    return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };
    
    if (isProgram) {
        glGetProgramiv(shader, flag, &success);
    }
    else {
        glGetShaderiv(shader, flag, &success);
    }
    if (success == GL_FALSE) {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        
        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}