//
//  Displays.h
//  TAREA5
//
//  Created by Luis Arias on 07/11/17.
//  Copyright © 2017 Omar Arias. All rights reserved.
//

#ifndef Displays_h
#define Displays_h
#include "Keyboards.h"

void renderBitMapString(float x, float y, char *string){
    int len = strlen(string);
    
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glRasterPos2i(x,y);
    
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    
    for (int i = 0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)string[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
}

void menu(){
    renderBitMapString(-295.0, 285.0, "Presione:");
    renderBitMapString(-295.0, 270.0, " 'x' -> positive x movement");
    renderBitMapString(-295.0, 255.0, " 'X' -> negative x movement");
    renderBitMapString(-295.0, 240.0, " 'y' -> positive y movement");
    renderBitMapString(-295.0, 225.0, " 'Y' -> negative y movement");
    renderBitMapString(-295.0, 210.0, " 'r' -> negative rotation");
    renderBitMapString(-295.0, 195.0, " 'R' -> positive rotation");
    renderBitMapString(-295.0, 180.0, " '+' -> Zoom in");
    renderBitMapString(-295.0, 165.0, " '-' -> Zoom out");
    renderBitMapString(-295.0, 150.0, " 'm' -> Enable mirror");
    renderBitMapString(-295.0, 135.0, " 'M' -> Disable mirror");
    renderBitMapString(-295.0, 120.0, " 'q' -> EXIT ...");
}

void display_poligon(){
    if (!lad) {
        cout << endl << "\tNumber of sides: "; cin >> lad;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    poligon_Points(lad);
    menu();
    glutSwapBuffers();
}

void display_arc(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    circle();
    menu();
    glutSwapBuffers();
    
}

void display_prisma(){
    if (!lad) {
        cout << endl << "\t1)Cubo\t2)Prisma rectangular\t3)Prisma Triangular " << endl;
        cout << "\t-Opción: "; cin >> lad;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    print_Prisma1(lad);
    menu();
    glutSwapBuffers();
}

void display_cone(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    print_Cone();
    menu();
    glutSwapBuffers();
}

#endif /* Displays_h */
