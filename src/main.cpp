#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "main.hpp"
#include "game.hpp"

int main() {
    srand(time(NULL));

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Ping Pong OpenGL", NULL, NULL);
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
    framebuffer_size_callback(window, 1280, 720);
    game.mainLoop();
}

void panic() {
    glfwTerminate();
    exit(1);
}

