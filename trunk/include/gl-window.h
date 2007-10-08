#ifndef GL_WINDOW_H
#define GL_WINDOW_H

/* Fonctions generales */

extern void initOpenGl(int argc, char ** argv);

extern void initOpenGlEvents(void);

extern void initOpenGlWindow(void);

/* Fonctions perso */

extern void initOpenGlEnv(void);

extern void handleKey(unsigned char key, int x, int y);

extern void handleSpecialKey(int key, int x, int y);

extern void display(void);

extern void reshape(int width, int height);

#endif

