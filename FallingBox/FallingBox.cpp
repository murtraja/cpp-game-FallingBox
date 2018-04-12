// FallingBox.cpp : Defines the entry point for the console application.
//
/*
Make a simple simulation of box falling and hitting the ground
*/
#include "stdafx.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	CGame game;
	if (game.Init())
	{
		game.Start();
	}
	game.Destroy();
	return 0;
}

/*
Geeth:
> Instead of game calling engine, engine can also call game
	- this will work like Engine.RunGame(gameObject);
	- so by changing the instance of gameObject, a new game will be run by engine
	- very portable

*/