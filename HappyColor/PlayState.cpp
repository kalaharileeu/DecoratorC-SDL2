/*
inherit from GameState, public
*/
#include "PlayState.h"
#include "Game.h"
#include "TextureManager.h"
#include "Intruder.h"
#include "Shield.h"
#include "Vector2D.h"

const std::string PlayState::playid = "PLAY";

PlayState::~PlayState()
{
	if (playobjects.empty() == false)
	{
		for (int i = 0; i < playobjects.size(); i++)
		{
			//playobjects[i]->clean();
			delete playobjects[i];
		}
		playobjects.clear();
	}
}//delete the level pointer

/*
Bullet handler should be updated here, check for escape key, 
check if player lives are enough to continue
update level
*/
void PlayState::update()
{
	if (boolloadingcomplete && !boolexiting)
	{
		for (int i = 0; i < playobjects.size(); i++)
		{
			if(playobjects[i]->type() == "shield")
				if (!((dynamic_cast<Shield*>(playobjects[i]))->checkifwrappedinstance()))
				{
					dynamic_cast<Shield*>(playobjects[i])->loadwrapped(new Intruder(1, Vector2D(200, 200), 38, 36, "intruder", 1));
				}
			playobjects[i]->update();
		}
	}
}

void PlayState::draw()
{
	if (boolloadingcomplete)
	{
		//TheTextureManager::Instance()->draw("intruder", 60, 0, 38, 36, TheGame::Instance()->getdrawer(), SDL_FLIP_NONE);//test draw
		//TheTextureManager::Instance()->drawFrame("intruder", 200, 100, 38, 36, 0, 0, TheGame::Instance()->getdrawer(), 0.0, 255);//test draw
		//BulletHandler::Instance()->drawBullets();
		for (int i = 0; i < playobjects.size(); i++)
		{
			playobjects[i]->draw();
		}
	}
}
//On enter prepare some variables for the level
//player lives, load content get the level filesetc.
bool PlayState::onEnter()
{
	//Manualy load some content here like level etc.

	//Register the image with the TextureManager
	TextureManager::Instance()->load("Content/enemy2.png",
		"intruder", TheGame::Instance()->getdrawer());//load intruder
	TextureManager::Instance()->load("Content/shield.png", "shield", TheGame::Instance()->getdrawer());//load shield
	//load some play objects manually into PlayState
	playobjects.push_back(new Intruder(1, Vector2D(150, 150), 38, 36, "intruder", 1));
	playobjects.push_back(new Shield(1, Vector2D(200, 200), 60, 60, "shield", 1));
	//if the level did not load correctly set the id to 0/null
	std::cout << "entering PlayState\n";
	boolloadingcomplete = true;
	return true;
}
//Clear bullets here from BulletHandler and reset Inputhandler
bool PlayState::onExit()
{
	boolexiting = true;
	std::cout << "exiting PlayState\n";
	return true;
}