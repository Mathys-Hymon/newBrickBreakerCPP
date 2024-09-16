#include "gameManager.h"

void GameManager::Load()
{
	mBall = Ball();
	mPlayer = Pad();
	mBall.Initialize({ 500,500 }, 10, WHITE, mPlayer);
}

void GameManager::Update()
{
	mBall.Update();
}

void GameManager::Draw()
{
	mBall.Draw();
}

void GameManager::Unload()
{
}
