#pragma once

#include <sys/types.h>

class Shader {
  public:
    Shader();
    ~Shader();

    uint getShaderProgram();
    void use();
    void setColor(const float &red, const float &green, const float &blue, const float &alpha);
  private:
    uint shaderProgram;
    int colorUniform;
};

uint initShaderProgram();
void makeSureShaderCompiled(const uint &shader);
