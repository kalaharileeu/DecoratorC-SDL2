#include "MovingObject.h"
/*
Because I'm not using dependence injection here, I have to pass the
parameter in through the constructor when I initaize the class
*/
MovingObject::MovingObject(int ms, Vector2D pos, int w, int h, std::string id, int nf) : GameObject()
{    // get position
	movespeed = ms;
	position = Vector2D(pos.getX(), pos.getY());
	// get drawing variables
	width = w;
	height = h;
	textureid = id;
	numframes = nf;
}

MovingObject::~MovingObject() 
{}

void MovingObject::draw()
{
	TextureManager::Instance()->drawFrame(textureid, (Uint32)position.getX(), (Uint32)position.getY(),
		width, height, currentrow, currentframe, TheGame::Instance()->getdrawer(), angle, alpha);
}

// apply velocity to current position
void MovingObject::update()
{
	position += velocity;
	currentframe = int(((SDL_GetTicks() / (1000 / 3)) % numframes));
}
