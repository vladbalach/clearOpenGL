#include "inc/glew.h"
#include "inc/glfw3.h"
#include <iostream>

void processInput(GLFWwindow *window);
/*
* resize callback
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void renderLoop(GLFWwindow *window) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow *createWindow(int width, int height) {
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return 0;
    }
    // get drawing context on window
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

int main() {
    if (glfwInit() == GL_FALSE) {
        std::cerr << "Error init glfw" << std::endl;
        return 1;
    }
    GLFWwindow *window = createWindow(600, 800);
    if (window == 0) {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    // set callback for resize
    renderLoop(window);
    // free all resources
    glfwTerminate();
    return 0;
}
