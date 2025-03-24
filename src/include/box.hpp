#include <sys/types.h>

class Box {
    public:
        Box(float x, float y, float z, float width, float height, float red, float green, float blue);
        Box(float x, float y, float z, float width, float height);

        ~Box();

        float x, y, z;
        float width, height;
        float color[3];

        void render();
        void putInBounds();
    private:

        uint vbo, vao, ebo;

        void fillVBO();
        void fillEBO();
};
