#include "glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>

#include "game.hpp"

#define FPS 60

Game::Game(GLFWwindow *window)
    : defaultBackground{0.0f, 0.0f, 0.0f}, window(window),
      player1(Box(-1.0f, 0.0f, 0.0f, 0.07f, 0.4f)),
      player2(Box(1.0f, 0.0f, 0.0f, 0.07f, 0.4f)),
      ball(Ball(0.0f, 0.0f, 0.0f, 0.04f, 16)) {

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Game::mainLoop() {
    float dt{0.0f};

    while (!glfwWindowShouldClose(this->window)) {
        auto time = glfwGetTime();

        this->tick(dt);

        dt = glfwGetTime() - time;

        if (dt < 1.0f / FPS) {
            std::this_thread::sleep_for(
                std::chrono::microseconds((uint)(1.0f / FPS - dt) * (uint)1e6));
        }

        dt = glfwGetTime() - time;
    }
}

void Game::tick(float dt) {
    this->processInput(dt);
    this->player1.putInBounds();
    this->player2.putInBounds();
    this->ball.tick(dt);
    this->ball.putInBounds();

    if(boxCollidesWithBall(this->player1, this->ball) || boxCollidesWithBall(this->player2, this->ball)) {
        this->ball.direction += std::numbers::pi;
    }

    this->shader.use();

    this->clear();
    this->player1.render();
    this->player2.render();
    this->ball.render();

    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Game::processInput(float dt) {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->window, true);
    }
    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS) {
        this->player1.y += 1 * dt;
    }
    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS) {
        this->player1.y -= 1 * dt;
    }
}

Game::~Game() { glfwTerminate(); }

void Game::clear() {
    glClearColor(this->defaultBackground[0], this->defaultBackground[1],
                 this->defaultBackground[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void framebuffer_size_callback(GLFWwindow *, int width, int height) {
    int size = std::min(width, height);
    glViewport(0, 0, size, size);
}

bool boxCollidesWithBall(Box &box, Ball &ball) {
    if ((ball.radius + box.width / 2) > std::abs(box.x - ball.x) &&
        (ball.radius + box.height / 2) > std::abs(box.y - ball.y)) {
        return true;
    }

    return false;
}
