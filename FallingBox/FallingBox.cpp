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

