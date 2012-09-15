#include "Engine.h"
#include "dbg.h"
#include <stdio.h>

Engine::Engine(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    debug("Initializing");

    if(glfwInit() != GL_TRUE)
        debug("Failed to initialize GLFW");
}

Engine::~Engine()
{
    glfwTerminate();
}

//---------------------------------
// Public Methods
//---------------------------------
void GLFWCALL resize(int width, int height);

int Engine::run()
{
    debug("Main loop");
    glfwOpenWindow(800, 600, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("Light Engine : 0.00 fps");
    glfwSwapInterval(1);
    glfwSetWindowSizeCallback(resize);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_TEXTURE_2D);

    // the main loop
    while(true)
    {
        glfwPollEvents();

        if(glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
            break;

        setWindowTitle();
        draw();
        m_frameCount += 1;
    }
    
    debug("Terminating");
    glfwCloseWindow();
    return 0;
}

//-------------------------------
// Private Methods
//-------------------------------

void Engine::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glfwSwapBuffers();
}

void Engine::setWindowTitle()
{
    if(glfwGetTime() - m_elapsedTime < 1)
        return;

    m_elapsedTime = glfwGetTime();

    double framerate = m_frameCount / glfwGetTime(); 
    char titlebuf[100];

    sprintf(titlebuf, "Light Engine : %.2f fps", framerate);
    glfwSetWindowTitle(titlebuf);
}

void GLFWCALL resize(int width, int height)
{
    double ar = (double)width/height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ar, ar, -1, 1, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
