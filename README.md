# Hi ^-^

This is a learning project.

# Building

if you are on windows then unfortunately you are on your own  
(use visual studio and create cmake project somehow, dont forget dependencies: `GL`, `glfw`)

## Linux :3
1. have a c++ compiler (probably gcc) and cmake, make  
    and install dependencies for the program:  
    - `GL`(present on most systems), 
    - `glfw`  
    easiest way is to install the packages with your package manager
2. clone the repo
    ```sh
    git clone https://github.com/p1k0chu/ping_pong_opengl.git
    cd ping_pong_opengl
    ```
3. make a build directory and init the build system
    ```sh
    mkdir build && cd build
    cmake ../src
    ```
4. to build & run:
    ```sh
    cmake --build .
    ./PingPong
    ```
    can also combine into one command:
    ```sh
    cmake --build . && ./PingPong
    ```

