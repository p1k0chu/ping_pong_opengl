#include "box.hpp"
#include "glad/glad.h"

Box::Box(float x, float y, float z, float width, float height, float red,
         float green, float blue)
    : x(x), y(y), z(z), width(width), height(height), color{red, green, blue} {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glBindVertexArray(0);

    fillEBO();
}
Box::Box(float x, float y, float z, float width, float height)
    : Box::Box(x, y, z, width, height, 1.0f, 1.0f, 1.0f) {}

Box::~Box() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void Box::render() {
    fillVBO();

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

#define EDGE_MARGIN_Y 0.02f
#define EDGE_MARGIN_X 0.01f

void Box::putInBounds() {
    if (this->y < height / 2.0f - 1.0f + EDGE_MARGIN_Y) {
        this->y = height / 2.0f - 1.0f + EDGE_MARGIN_Y;
    } else if (this->y > 1.0f - height / 2.0f - EDGE_MARGIN_Y) {
        this->y = 1.0f - height / 2.0f - EDGE_MARGIN_Y;
    }

    if (this->x < width / 2.0f - 1.0f + EDGE_MARGIN_X) {
        this->x = width / 2.0f - 1.0f + EDGE_MARGIN_X;
    } else if (this->x > 1.0f - width / 2.0f - EDGE_MARGIN_X) {
        this->x = 1.0f - width / 2.0f - EDGE_MARGIN_X;
    }
}

void Box::fillVBO() {
    glBindVertexArray(vao);

    float vertices[] = {
        x - width / 2, y + height / 2, z, color[0], color[1],
        color[2], // top left
        x + width / 2, y + height / 2, z, color[0], color[1],
        color[2], // top right
        x + width / 2, y - height / 2, z, color[0], color[1],
        color[2], // bottom right
        x - width / 2, y - height / 2, z, color[0], color[1],
        color[2] // bottom left
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
}

void Box::fillEBO() {
    glBindVertexArray(vao);

    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
