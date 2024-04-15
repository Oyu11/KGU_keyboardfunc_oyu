#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Global variables to store state
int numVertices = 3; // Initial number of vertices
GLfloat color[3] = {1.f, 0.f, 0.f}; // Initial color (red)

/* GLUT callback Handlers */
void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color based on the global 'color' variable
    glColor3fv(color);

    // Center of the circle
    float centerX = 0.0;
    float centerY = 0.0;

    // Radius of the circle
    float radius = 0.4; // Adjust the radius to fit nicely within the green background

    // Draw the circle with the current number of vertices
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i) {
        float theta = 2.0 * 3.1415926 * i / numVertices; // Angle for each vertex
        float x = centerX + radius * cos(theta); // Calculate x coordinate
        float y = centerY + radius * sin(theta); // Calculate y coordinate
        glVertex2f(x, y); // Set vertex
    }
    glEnd();

    glFlush();
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'r':
    case 'R':
        // Change color to red
        color[0] = 1.0f;
        color[1] = 0.0f;
        color[2] = 0.0f;
        glutPostRedisplay(); // Request redraw
        break;
    case 'g':
    case 'G':
        // Change color to green
        color[0] = 0.0f;
        color[1] = 1.0f;
        color[2] = 0.0f;
        glutPostRedisplay(); // Request redraw
        break;
    case 'b':
    case 'B':
        // Change color to blue
        color[0] = 0.0f;
        color[1] = 0.0f;
        color[2] = 1.0f;
        glutPostRedisplay(); // Request redraw
        break;
    }
}

// Special keyboard callback function for arrow keys
void special(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        // Increase the number of vertices by 1
        numVertices++;
        glutPostRedisplay(); // Request redraw
        break;
    case GLUT_KEY_DOWN:
        // Decrease the number of vertices by 1, ensuring it doesn't go below 3
        if (numVertices > 3)
            numVertices--;
        glutPostRedisplay(); // Request redraw
        break;
    }
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1080,1080);
    glutCreateWindow("shape");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard); // Register keyboard callback function
    glutSpecialFunc(special); // Register special keyboard callback function
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return EXIT_SUCCESS;
}
