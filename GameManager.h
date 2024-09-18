#pragma once
#include "brick.h"
#include <vector>

class GameManager
{
public:
	GameManager();

	void Load();
	void Update();
	void Draw();
	void NewRound();
	void Unload();
	void SpawnBricks(int bricksRow);

private:
	Ball mBall;
	Pad mPlayer;
	bool mGameStarted = false;
	bool mGameOver = false;

	int mPlayerLife;
	int mScore;
	std::vector<std::vector<Brick>> bricks;
};

