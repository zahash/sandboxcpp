#ifndef SANDBOXCPP_GL
#define SANDBOXCPP_GL

// #define GLEW_STATIC
#define GLEW_NO_GLU

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int glrun(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (int init = glewInit(); init != GLEW_OK)
    {
        std::cout << "Error: glewInit => " << init << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    // unsigned int bufId;
    // glGenBuffers(1, &bufId);
    // glBindBuffer(GL_ARRAY_BUFFER, bufId);
    // float pos[6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
    // glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &pos, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.5, 0.2, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#endif
