#pragma once
#include "brick.h"
#include <vector>
#include <string>

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
	bool CheckButton(Vector2 position, std::string text,float fontSize, Vector2 size);
	bool GameShouldClose();

private:
	Ball mBall;
	Pad mPlayer;
	bool mGameStarted = false;
	bool mGameOver = false;
	bool mCloseGame = false;

	int mPlayerLife = 3;
	int mScore = 0;
	std::vector<std::vector<Brick>> mBricks;
	std::vector<std::vector<Brick>> mBonus;
};

