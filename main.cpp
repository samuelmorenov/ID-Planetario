//============================================================================
// Name        : Cargador.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Modelo3D.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "Mundo.h"

using namespace std;

int window;
Mundo *mundo;


void onMouse(int button, int state, int x, int y){
    mundo->onMouse(button,state,x,y);
}

void onMotion(int x, int y) {
    mundo->onMotion(x,y);
    }

void menu(int identificador){
    look_type _look;
    switch(identificador){
    case 0:
        _look=WIRE;
        mundo->look=_look;
        break;
    case 1:
        _look =SOLID;
        mundo->look=_look;
       break;
    case 2:
        _look =FLAT;
        mundo->look=_look;;
        break;
    case 3:
        _look =SMOOTH;
        mundo->look=_look;
        break;
    case 4:
           exit(-1);
    }
}

void ControlTeclado (unsigned char key, int x, int y){
    switch(key){
        case '1':
            mundo->foco->switchFoco(0);
            break;
        case '2':
            mundo->foco->switchFoco(1);
            break;
        case '3':
            mundo->foco->switchFoco(2);
            break;
        case '4':
            mundo->foco->switchFoco(3);
            break;
        case '5':
            mundo->foco->switchFoco(4);
            break;
        case '6':
            mundo->foco->switchFoco(5);
            break;
        case '7':
            mundo->foco->switchFoco(6);
            break;
        case '8':
            mundo->foco->switchFoco(7);
            break;
        case '9':
            mundo->apagarFocos();
            break;
        case '0':
            mundo->switchCirculos();
            break;
        case 32:
            mundo->cambiarCamara();
            break;
        case 27:
            glutDestroyWindow(window);
            exit(0);
            break;
    }
}
void display(void) {
     mundo->DrawGLScene();
}

int main(int argc, char **argv) {
     glutInit(&argc, argv);
     mundo = new Mundo(argv);
     mundo->InitGL(1024, 768, 100, 100);
     glutCreateMenu(menu);
     glutAddMenuEntry("Alambre", 0);
     glutAddMenuEntry("Solido", 1);
     glutAddMenuEntry("Flat", 2);
     glutAddMenuEntry("Smooth", 3);
     glutAddMenuEntry("Salir", 4);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
     glutKeyboardFunc(ControlTeclado);

     glutDisplayFunc(display);

     glutIdleFunc(display); // pinta cuando no esté haciendo nada
     glutMouseFunc(onMouse);// puntero a la función de eventos de teclado
     glutMotionFunc(onMotion);
     glutMainLoop();
     return 0;
}
