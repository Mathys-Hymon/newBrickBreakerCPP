#include "gameManager.h"


GameManager::GameManager()
{
}

void GameManager::Load()
{
	mScore = 0;
	mGameStarted = false;
    mGameOver = false;
	mPlayerLife = 3;
	mPlayer = Pad({ 100,(float)GetScreenHeight()-100}, {150,30}, 30, BLACK);
	mBall = Ball({ 500,500 }, 15, WHITE, &mPlayer);
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
				if (mPlayerLife <= 0) {
					mGameOver = true;
				}
			}

			int brickAlive = 0;
			for (int row = 0; row < mBricks.size(); ++row) {
				for (int col = 0; col < mBricks[row].size(); ++col) {
					if (mBricks[row][col].GetAlive() == true) {
						brickAlive += 1;
						if (mBricks[row][col].CheckCollision()) {
							mScore += 10;
							if (GetRandomValue(0, 10) == 1) {

							}
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
	if (!mGameOver) {
		mPlayer.Draw();
		mBall.Draw();

		DrawText(TextFormat("Score : %i", mScore), 35, GetScreenHeight() - 50, 20, BLACK);
		DrawText(TextFormat("Life : %i", mPlayerLife), GetScreenWidth() - 150, GetScreenHeight() - 50, 20, BLACK);

		for (int row = 0; row < mBricks.size(); ++row) {
			for (int col = 0; col < mBricks[row].size(); ++col) {
				mBricks[row][col].Draw();
			}
		}
	}
	else {
		DrawText("GAME OVER", (GetScreenWidth() / 2) - (MeasureText("GAME OVER", 45)/2), 150, 45, BLACK);
		DrawText(TextFormat("final score : %i", mScore), (GetScreenWidth() / 2) - (MeasureText(TextFormat("final score : %i", mScore), 30) / 2), 220, 30, BLACK);
		if (CheckButton({ (float)GetScreenWidth() / 2, 400 }, "RETRY", 35, { 100,50 })) {
			Load();
		}
		if (CheckButton({ (float)GetScreenWidth() / 2, 550 }, "QUIT", 35, { 100,50 })) {
			mCloseGame = true;
		}
	}

}

void GameManager::NewRound()
{
	mGameStarted = false;
	if (mBricks.size() < 14) {
		SpawnBricks(mBricks.size() + 3);
	}
	else {
		SpawnBricks(14);
	}
}

void GameManager::Unload()
{
	mBall.Unload();
	mPlayer.Unload();

	int numRows = mBricks.size() - 1;
	for (int i = 0; i < numRows; ++i) {
		mBricks[i].clear();
	}
	mBricks.clear();
}

void GameManager::SpawnBricks(int bricksRow)
{
	const int numCols = 10;
	const float brickWidth = GetScreenWidth() / numCols;
	const float brickHeight = 24.0f;
	const float startX = 50;
	const float startY = 50.0f;

	mBricks.clear();
	for (int i = 0; i < bricksRow; ++i) {
		std::vector<Brick> row;
		for (int j = 0; j < numCols; ++j) {
			float x = startX + j * (brickWidth);
			float y = startY + i * (brickHeight);
			row.push_back(Brick({ x, y }, { brickWidth, brickHeight }, RED, &mBall));
		}
		mBricks.push_back(row);
	}
}

bool GameManager::CheckButton(Vector2 position, std::string text,float fontSize, Vector2 size)
{
	DrawRectangle(position.x - (MeasureText(text.c_str(), fontSize) + size.x) / 2, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), fontSize)), size.y, WHITE);
	DrawText(text.c_str(), position.x - (MeasureText(text.c_str(), fontSize)) / 2, position.y + size.y / 3, fontSize, BLUE);

	if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { position.x - (MeasureText(text.c_str(), fontSize) + size.x) / 2, position.y,size.x + static_cast<float>(MeasureText(text.c_str(), fontSize)), size.y })) {

		DrawRectangle(position.x - (MeasureText(text.c_str(), fontSize) + size.x) / 2, position.y, size.x + static_cast<float>(MeasureText(text.c_str(), fontSize)), size.y, GRAY);
		DrawText(text.c_str(), position.x - (MeasureText(text.c_str(), fontSize)) / 2, position.y + size.y / 3, fontSize, DARKBLUE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

bool GameManager::GameShouldClose()
{
	return mCloseGame;
}
