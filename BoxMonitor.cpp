#include <cstdlib>
#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "getBMP.h"

float rotate_y = 0.0;
float rotate_x = 0.0;
GLuint texture[5]; // Array of texture ids.
GLuint texture2;   // Texture id for the second cube.
GLuint texture3;   // Texture id for the third cube.
GLuint texture4;   // Texture id for the fourth cube.
GLuint texture5;   // Texture id for the fifth cube.
GLuint texture6;   // Texture id for the sixth cube.
int currentTexture = 0;
unsigned char chessboard[64][64][4]; // Storage for chessboard image.
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // Directional light from the top-right-front
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // White diffuse light

void createChessboard(void) {
    int i, j;
    for (i = 0; i < 64; i++)
        for (j = 0; j < 64; j++)
            if ((((i / 8) % 2) && ((j / 8) % 2)) || (!((i / 8) % 2) && !((j / 8) % 2)))
            {
                chessboard[i][j][0] = 0x00;
                chessboard[i][j][1] = 0x00;
                chessboard[i][j][2] = 0x00;
                chessboard[i][j][3] = 0xFF;
            }
            else
            {
                chessboard[i][j][0] = 0xDD;
                chessboard[i][j][1] = 0xDD;
                chessboard[i][j][2] = 0xDD;
                chessboard[i][j][3] = 0xFF;
            }
}

void loadTextures() {
    imageFile* image[6];
    image[0] = getBMP("../../Textures/depan.bmp");
    image[1] = getBMP("../../Textures/belakangmonitor.bmp"); // Replace with the path to your second texture
    image[2] = getBMP("../../Textures/atas.bmp");
    image[3] = getBMP("../../Textures/bawah.bmp");
    image[4] = getBMP("../../Textures/sampingkanan.bmp");
    image[5] = getBMP("../../Textures/sampingkanan.bmp");

    glGenTextures(6, texture);

    // Load external texture for the first cube.
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load external texture for the second cube.
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->width, image[1]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load external texture for the third cube.
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->width, image[2]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load external texture for the fourth cube.
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->width, image[3]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load external texture for the fifth cube.
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->width, image[4]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load external texture for the sixth cube.
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->width, image[5]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load internal texture for the chessboard.
    createChessboard();
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, chessboard);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -8.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    setupLighting();

    glEnable(GL_TEXTURE_2D);

    // Sisi Depan
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[currentTexture]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.8, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.8, 0.5);
    glEnd();
    glPopMatrix();

    // Sisi Belakang
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.8, -0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.8, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.8, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.8, -0.5);
    glEnd();
    glPopMatrix();

    // Sisi Atas
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 0.8, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.8, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.8, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.8, -0.5);
    glEnd();
    glPopMatrix();

    // Sisi Bawah
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -0.8, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, -0.8, -0.5);
    glEnd();
    glPopMatrix();

    // Sisi Kanan
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -0.8, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 0.8, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 0.8, 0.5);
    glEnd();
    glPopMatrix();

    // Sisi Kiri
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -0.8, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -0.8, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 0.8, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.8, 0.5);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

void animate(int value) {
    rotate_y += 1.0;
    glutPostRedisplay();
    glutTimerFunc(16, animate, 0); // 16 milidetik untuk sekitar 60 frame per detik
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 100.0);
}

void keyInput(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    else if (key == ' ')
    {
        currentTexture = (currentTexture + 1) % 2;
        glutPostRedisplay();
    }
    else if (key == 127)
    {
        rotate_x = 0.0;
        rotate_y = 0.0;
        glutPostRedisplay();
    }
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Textured Box");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyInput);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    glewExperimental = GL_TRUE;
    glewInit();

    loadTextures();

    glutTimerFunc(25, animate, 0);  // 25 milidetik pertama untuk memulai animasi

    glutMainLoop();
    return 0;
}

