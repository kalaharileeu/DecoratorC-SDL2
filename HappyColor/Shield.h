#pragma once
#include "MovingObject.h"
#include "Intruder.h"
#include <vector>

class Shield :	public MovingObject
{
private:
	//std::vector<GameObject*> shieldedintruders;
	GameObject* shieldedintruder;
public:
	/*movespeed, position, width, height, textureid, numframes;*/
	Shield(int ms, Vector2D pos, int w, int h, std::string id, int nf)
		: MovingObject(ms, pos, w, h, id, nf)
	{
		//this can all be done with dependency injection
		//movespeed = ms;
		velocity.setX(-movespeed);
		velocity.setY(movespeed * m);
		shieldedintruder = 0;
	}

	~Shield()
	{
		if (shieldedintruder != 0)
		{
			delete shieldedintruder;
		}
		std::cout << "Intruder detroyed";
	}

	void update()
	{
		MovingObject::update();
		//Wrapped object update
		if (shieldedintruder != 0)
		{
			shieldedintruder->update();
		}
	}

	void draw()
	{
		MovingObject::draw();
		//Wrapped object update
		if (shieldedintruder != 0)
		{
			shieldedintruder->draw();//Call the wrapped opject draw
		}
	}

	std::string type()
	{
		return MovingObject::type();
	}

	void loadwrapped(GameObject* wrapme_gameobject)
	{
		//The Gameobject reference are revceived and
		//can be "decorated" or "wrapped"
		shieldedintruder = wrapme_gameobject;
		//sets the position of the wrapper in perspectif to the wrapped
		position.setX((shieldedintruder->Getposition()).getX());
		position.setY((shieldedintruder->Getposition()).getY());
	}

	bool checkifwrappedinstance()
	{
		if (shieldedintruder != 0)
			return true;
		else
			return false;
	}
};

