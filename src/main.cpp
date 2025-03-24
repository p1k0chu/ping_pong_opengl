#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "main.hpp"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_VERSION_MAJOR,  4);
    glfwWindowHint(GLFW_VERSION_MINOR,  6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}

void panic() {
    glfwTerminate();
    exit(1);
}
