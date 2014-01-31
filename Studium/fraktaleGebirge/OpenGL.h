/* 
 * File:   OpenGL.h
 * Author: Manuel Bellersen
 *
 * Created on 1. Mai 2010, 14:01
 */

#ifndef _OPENGL_H
#define	_OPENGL_H

#include <string>
#include <queue>
#include <list>
#include <SDL.h>
#include <SDL_opengl.h>

#include "Drawable.h"
#include "RotTrans.h"
#include "Fractal.h"

class OpenGL{
public:
	static OpenGL& getInstance();
	static OpenGL& getInstance( unsigned short int X, unsigned short int Y, unsigned short int Depth);
	static void Quit();
	void handleEvents();
	void drawScreen();
	void addDrawable( Drawable* thing);
	void removeDrawable( Drawable* thing);
	bool gotQuit();
	void setFractal( Fractal* f);
private:
	static OpenGL* instance;
	static SDL_Event event;
	std::queue<SDL_KeyboardEvent> eventQKeyDown;
	std::queue<SDL_KeyboardEvent> eventQKeyUp;
	std::queue<SDL_MouseMotionEvent> eventQMouseMovement;
	std::queue<SDL_MouseButtonEvent> eventQMouseDown;
	std::queue<SDL_MouseButtonEvent> eventQMouseUp;
	std::list<Drawable*> drawableList;
	static bool quit;
	static unsigned short int windowX;
	static unsigned short int windowY;
	static unsigned short int windowDepth;
	int zoomFactor;
	enum AbortType{ APPNO_ERROR = 0, APP_REINITIALIZING, SDL_ERROR, OPENGL_ERROR};
	enum MouseActivity{ NOTHING = 0, TRANSLATION , ROTATION} mouseActivity;
    struct coordinates{
        int x;
        int y;
    } mouseCoordinates;
	Fractal* fractal;

	OpenGL();
	~OpenGL();
	void init();
	void initGL();
	void initSDL();
	void setupView();
	void zoomView( );
	static void Abort( AbortType error);
	static std::string getGLError( GLenum error);
	void handleMouseMovement();
	void handleMouseDown();
	void handleMouseUp();
	void handleKeyDown();
	void handleKeyUp();
	void setMouseActivity( enum MouseActivity mouseactivity);
	void updateMouse();
	void updateView();
	void setView();

};

#endif	/* _OPENGL_H */

