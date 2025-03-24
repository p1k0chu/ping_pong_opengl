#pragma once

#include <sys/types.h>

class Shader {
  public:
    Shader();
    ~Shader();

    uint getShaderProgram();
    void use();
  private:
    uint shaderProgram;
};

uint initShaderProgram();
void makeSureShaderCompiled(const uint &shader);
