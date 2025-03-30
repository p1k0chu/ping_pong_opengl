#include "ball.hpp"
#include "glad/glad.h"
#include <cmath>
#include <numbers>
#include <sys/types.h>

Ball::Ball(float x, float y, float z, float radius, ushort sections, float red,
           float green, float blue)
    : x(x), y(y), z(z), radius(radius), sections(sections),
      color{red, green, blue} {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

Ball::Ball(float x, float y, float z, float radius, ushort sections)
    : Ball::Ball(x, y, z, radius, sections, 1.0f, 1.0f, 1.0f) {}

Ball::~Ball() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void Ball::fillVBO() {
    size_t size = (2 + sections) * 6;

    float *array = new float[size];

    array[0] = x;
    array[1] = y;
    array[2] = z;
    array[3] = color[0];
    array[4] = color[1];
    array[5] = color[2];

    for (size_t i = 6; i < size; i += 6) {
        array[i] =
            cos(2.0 * std::numbers::pi * (i / 6 - 1.0) / sections) * radius +
            x;
        array[i + 1] =
            sin(2.0 * std::numbers::pi * (i / 6 - 1.0) / sections) * radius +
            y;
        array[i + 2] = z;
        
        array[i + 3] = color[0];
        array[i + 4] = color[1];
        array[i + 5] = color[2];
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, array, GL_DYNAMIC_DRAW);

    delete[] array;
}

void Ball::render() {
    fillVBO();

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 2 + sections);
    glBindVertexArray(0);
}
