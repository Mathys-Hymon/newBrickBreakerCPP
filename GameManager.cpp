#include "gameManager.h"

void GameManager::Load()
{
	mBall = Ball();
	mPlayer = Pad();
	mBall.Initialize({ 500,500 }, 10, WHITE, mPlayer);
	mPlayer.Initialize({ 200,500 }, { 150,50 }, 30, BLACK);
}

void GameManager::Update()
{
	mBall.Update();
	mPlayer.Update();
}

void GameManager::Draw()
{
	mBall.Draw();
	mPlayer.Draw();
}

void GameManager::Unload()
{
	mBall.Unload();
	mPlayer.Unload();
}
