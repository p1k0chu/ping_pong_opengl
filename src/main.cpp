#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

#include "game.hpp"
#include "main.hpp"

#define DEFAULT_W_SIZE 720

int main() {
    srand(time(NULL));

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow *window =
        glfwCreateWindow(DEFAULT_W_SIZE, DEFAULT_W_SIZE, "Ping Pong OpenGL", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create glfw window" << std::endl;
        panic();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to init GLAD" << std::endl;
        panic();
    }

    Game game{window};
    framebuffer_size_callback(window, DEFAULT_W_SIZE, DEFAULT_W_SIZE);
    game.mainLoop();
}

void panic() {
    glfwTerminate();
    exit(1);
}
