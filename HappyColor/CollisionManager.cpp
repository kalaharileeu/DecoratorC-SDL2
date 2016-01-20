#include "CollisionManager.h"
#include "Shield.h"


void CollisionManager::checkWrapperWrappedCollision(const std::vector<GameObject*> &objects)
{
	//pointer used to point at "intruders"
	GameObject* pointerobjectintruder;
	for (int i = 0; i < objects.size(); i++)
	{
		//pointer used to point at "Shield"
		GameObject* pointerobjectshield = objects[i];
		//create two collsion rectangles
		SDL_Rect* rectshield = new SDL_Rect();
		SDL_Rect* rectsintruder = new SDL_Rect();
		//perform search for Shield gameobjects
		if (pointerobjectshield->type() == std::string("Shield") 
			&& !pointerobjectshield->Getcollision())
		{
			//Populate collision rectangle
			rectshield->x = pointerobjectshield->Getposition().getX();
			rectshield->y = pointerobjectshield->Getposition().getY();
			rectshield->w = pointerobjectshield->Getwidth();
			rectshield->h = pointerobjectshield->Getheight();
			//Search th
			for(int j = 0; j < objects.size(); j++)
			{
				pointerobjectintruder = objects[j];
				//if it  is a intruder and it has not collided yet
				if (pointerobjectintruder->type() == std::string("Intruder")
					&& !pointerobjectintruder->Getcollision())
				{
					//Populate collision rectangle
					rectsintruder->x = pointerobjectintruder->Getposition().getX();
					rectsintruder->y = pointerobjectintruder->Getposition().getY();
					rectsintruder->w = pointerobjectintruder->Getwidth();
					rectsintruder->h = pointerobjectintruder->Getheight();
					//Check for collision
					if (RectRect(rectsintruder, rectshield))
					{
						//If it already collided then skip it
						if (!pointerobjectintruder->Getcollision()
							&& !pointerobjectshield->Getcollision())
						{
							pointerobjectintruder->collision();
							pointerobjectshield->collision();
							//upcast to shield to use shield specific functions
							dynamic_cast<Shield*>(pointerobjectshield)->loadwrapped(pointerobjectintruder);
							//below hoe to load a brand new gameobject into the wrapper
							//dynamic_cast<Shield*>(playobjects[i])->
							//	loadwrapped(new Intruder(1, Vector2D(200, 200), 60, 60, "intruder", 1));
						}
					}
				}
			}
		}
		delete rectsintruder;
		delete rectshield;
	}
}