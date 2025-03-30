
#include <sys/types.h>

class Ball {
  public:
    Ball(float x, float y, float z, float radius, ushort sections, float red, float green, float blue);
    Ball(float x, float y, float z, float radius, ushort sections);
    ~Ball();

    Ball(Ball &r) = delete;
    Ball& operator=(Ball& r) = delete;

    float x, y, z;
    float radius;
    ushort sections;
    float color[3];

    float direction; // 1 to 360

    void render();
    void tick(float dt);
    void putInBounds();

  private:
    uint vao, vbo;

    void fillVBO();
};
