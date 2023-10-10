#include <GL/glut.h>
float rotate_y = 0;
float rotate_x = 0;

// Fungsi untuk menggambar rectangular box abu-abu
void drawRectangularBox() {
    // Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(-1.0, 0.5, 0.5);
    glEnd();

    // Belakang
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();

    // Sisi Kiri
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, 0.5);
    glEnd();

    // Sisi Kanan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glEnd();

    // Atas
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();

    // Bawah
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);  // Abu-abu
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glEnd();

    // Bagian depan cermin
    glBegin(GL_QUADS);
    glColor4f(0.5, 0.5, 0.8, 0.51);  // Warna biru dengan alpha (transparansi) 0.5
    glVertex3f(-0.9, -0.4, 0.51);  // Kiri bawah
    glVertex3f(0.9, -0.4, 0.51);   // Kanan bawah
    glVertex3f(0.9, 0.4, 0.51);    // Kanan atas
    glVertex3f(-0.9, 0.4, 0.51);   // Kiri atas
    glEnd();

    // Garis tepi bagian depan lemari (kaca)
    glColor3f(0.0, 0.0, 0.0);  // Warna hitam untuk garis tepi
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.9, -0.4, 0.51);
    glVertex3f(0.9, -0.4, 0.51);
    glVertex3f(0.9, 0.4, 0.51);
    glVertex3f(-0.9, 0.4, 0.51);
    glEnd();

    // Sekat pertama (garis vertikal)
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk sekat
    glLineWidth(2.0); // Ketebalan garis sekat

    glBegin(GL_LINES);
    glVertex3f(0.4, -0.4, 0.51); // Vertex kiri
    glVertex3f(0.4, 0.4, 0.51);  // Vertex kanan
    glEnd();

    // Sekat kedua (garis vertikal)
    glBegin(GL_LINES);
    glVertex3f(-0.4, -0.4, 0.51); // Vertex kiri
    glVertex3f(-0.4, 0.4, 0.51);  // Vertex kanan
    glEnd();
}



// Fungsi untuk menggambar outline rectangular box
void drawOutline() {
    // Mengatur warna outline menjadi hitam
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Mengatur mode rendering ke wireframe

    glBegin(GL_QUADS);
    // Gambar outline pada setiap sisi rectangular box
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(-1.0, 0.5, 0.5);

    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);

    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, 0.5);

    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(1.0, 0.5, 0.5);

    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);

    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glEnd();



    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Kembali ke mode rendering solid
}

// Fungsi untuk menggambar scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Geser kamera ke belakang untuk melihat balok
    glTranslatef(0.0, 0.0, -5.0);

    // Putar balok
    static float angle = 0.0;
    glRotatef(angle, 1.0, 1.0, 1.0);
    angle += 1.0;

    // Gambar rectangular box
    drawRectangularBox();

    // Gambar outline rectangular box
    drawOutline();

    glutSwapBuffers();
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


// Fungsi untuk mengatur viewport dan perspektif
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 100.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kubus Solid OpenGL");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}
