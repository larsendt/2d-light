#ifndef _ENGINE_H
#define _ENGINE_H

#include <GL/glfw.h>
#include <Shader.h>

class Engine
{
    public:
        Engine(int argc, char *argv[]);
        ~Engine();
        int run();

    private:
        void draw();
        void setWindowTitle(); 

        unsigned int m_frameCount;
        double m_elapsedTime;
};

#endif
