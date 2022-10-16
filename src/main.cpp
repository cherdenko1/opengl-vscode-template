#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

int main() {

    if(!glfwInit()) {
        
        std::cout << "Failed to Initialized glfw";
        return -1;
    }

    //window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Creating a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);

    //if window initialized
    if(window == NULL) {

        std::cout << "Failed to create window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //if glad initialized
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {

        std::cout << "Failed to initialized GLAD";
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}