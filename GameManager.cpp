#include "gameManager.h"


GameManager::GameManager()
{
}

void GameManager::Load()
{
	mPlayer = Pad({ 100,(float)GetScreenHeight()-100}, {100,50}, 30, BLACK);
	mBall = Ball({ 500,500 }, 10, WHITE, &mPlayer);
	SpawnBricks(7);
}

void GameManager::Update()
{
	if (!mGameOver) {
		mPlayer.Update();
		if (!mGameStarted) {
			mBall.SetPosition({ mPlayer.GetPos().x, mPlayer.GetPos().y - 80 });
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				mGameStarted = true;
			}
		}
		else {
			mBall.Update();
			if (mBall.GetPos().y > GetScreenHeight()) {
				mGameStarted = false;
				mBall.ResetBall();
				mPlayerLife--;
			}
			int brickAlive = 0;
			for (int row = 0; row < bricks.size(); ++row) {
				for (int col = 0; col < bricks[row].size(); ++col) {
					if (bricks[row][col].GetAlive() == true) {
						brickAlive += 1;
						if (bricks[row][col].CheckCollision()) {
							mScore += 10;
						}
					}
				}
			}

			if (brickAlive == 0) {
				NewRound();
			}
		}
	}

}

void GameManager::Draw()
{
	mPlayer.Draw();
	mBall.Draw();
	
	for (int row = 0; row < bricks.size(); ++row) {
		for (int col = 0; col < bricks[row].size(); ++col) {
			bricks[row][col].Draw();
		}
	}
}

void GameManager::NewRound()
{
	mGameStarted = false;
	if (bricks.size() < 14) {
		SpawnBricks(bricks.size() + 3);
	}
	else {
		SpawnBricks(14);
	}
}

void GameManager::Unload()
{
	mBall.Unload();
	mPlayer.Unload();

	int numRows = bricks.size() - 1;
	for (int i = 0; i < numRows; ++i) {
		bricks[i].clear();
	}
	bricks.clear();
}

void GameManager::SpawnBricks(int bricksRow)
{
	const int numCols = 10;
	const float brickWidth = GetScreenWidth() / numCols;
	const float brickHeight = 24.0f;
	const float startX = 50;
	const float startY = 50.0f;

	bricks.clear();
	for (int i = 0; i < bricksRow; ++i) {
		std::vector<Brick> row;
		for (int j = 0; j < numCols; ++j) {
			float x = startX + j * (brickWidth);
			float y = startY + i * (brickHeight);
			row.push_back(Brick({ x, y }, { brickWidth, brickHeight }, RED, &mBall));
		}
		bricks.push_back(row);
	}
}
