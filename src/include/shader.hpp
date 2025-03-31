#pragma once

#include <sys/types.h>

class Shader {
  public:
    Shader();
    ~Shader();

    Shader(Shader& r) = delete;
    Shader& operator=(Shader& r) = delete;

    uint getShaderProgram();
    void use();
  private:
    uint shaderProgram;
};

uint initShaderProgram();
void makeSureShaderCompiled(const uint &shader);
