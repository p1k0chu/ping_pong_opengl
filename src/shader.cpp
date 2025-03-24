#include "main.hpp"
#include "shader.hpp"
#include <cassert>
#include <iostream>
#include "shader.hpp"
#include "glad/glad.h"

Shader::Shader(): shaderProgram(initShaderProgram()) {
    makeSureShaderCompiled(shaderProgram);

    colorUniform = glGetUniformLocation(shaderProgram, "color");
    assert(colorUniform != -1);
}

Shader::~Shader() {
    glDeleteProgram(shaderProgram);
}

void Shader::setColor(const float &red, const float &green, const float &blue, const float &alpha) {
    glUniform4f(colorUniform, red, green, blue, alpha);
}

void Shader::use() {
    glUseProgram(shaderProgram);
}

uint Shader::getShaderProgram() {
    return shaderProgram;
}


const char *vertexShaderSource =
    "#version 460 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec4 aColor;\n"

    "out vec4 color;\n"

    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   color = aColor;"
    "}";

const char *fragmentShaderSource =
    "#version 460 core\n"
    "in vec4 color;\n"
    "out vec4 FragColor;\n"

    "void main()\n"
    "{\n"
    "    FragColor = color\n"
    "}";

/// panics if compilation failed
void makeSureShaderCompiled(const uint &shader) {
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        std::cerr << "Failed to compile shader" << std::endl;
        panic();
    }
}

/// returns an object id to the shader program
uint initShaderProgram() {
    uint vertexShader{glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    uint fragmentShader{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    makeSureShaderCompiled(vertexShader);
    makeSureShaderCompiled(fragmentShader);

    uint shaderProgram{glCreateProgram()};
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    {
        int success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            std::cerr << "Failed to link the shader program!" << std::endl;
            panic();
        }
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}


