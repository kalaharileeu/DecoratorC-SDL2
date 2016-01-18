#pragma once
#include <iostream>
#include "MovingObject.h"
#include "GeneralParameters.h"

class Intruder : public MovingObject
{
public:
	/*movespeed, position, width, height, textureid, numframes;*/
	Intruder(int ms, Vector2D pos, int w, int h, std::string id, int nf) 
		: MovingObject(ms, pos, w, h, id, nf)
	{
		//this can all be done with dependency injection
		//movespeed = ms;
		velocity.setX(-movespeed);
		velocity.setY(movespeed * m);
	}

	~Intruder() { std::cout << "Intruder detroyed"; }

	void update()
	{
		MovingObject::update();
	}

	void draw()
	{
		MovingObject::draw();
	}

	std::string type()
	{
		return MovingObject::type();
	}

	//void load() {};
};

