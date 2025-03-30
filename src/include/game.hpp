#pragma once

#include "shader.hpp"
#include <GLFW/glfw3.h>
#include <sys/types.h>

#include "box.hpp"
#include "ball.hpp"

class Game {
  public:
    Game(GLFWwindow *window);
    ~Game();

    Game(Game& r) = delete;
    Game& operator=(Game& r) = delete;

    float defaultBackground[3];

    void clear();
    void tick(float dt);
    void mainLoop();
    void processInput(float dt);

  private:
    GLFWwindow *window;
    Shader shader;

    Box player1;
    Box player2;
    Ball ball;
};

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

