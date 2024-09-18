#pragma once
#include "Ball.h"

class Brick
{
public:
	Brick();
	Brick(Vector2 newPos, Vector2 newSize, Color newColor, Ball* newBall);
	void Draw() const;
	bool CheckCollision();
	bool GetAlive();
	~Brick();



private:
	Vector2 mPos;
	Vector2 mSize;
	Color mColor;
	Ball* mBall;
	bool mAlive = true;
};

