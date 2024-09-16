#pragma once
#include "ball.h"
#include "pad.h"

class GameManager
{
public:


	void Load();
	void Update();
	void Draw();
	void Unload();

private:
	Ball mBall;
	Pad mPlayer;
};

