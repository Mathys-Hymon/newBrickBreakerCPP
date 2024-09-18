#pragma once
#include "Pad.h"

class Ball
{
public:

	Ball();
	Ball(Vector2 newPosition, float newRadius, Color newColor, Pad* newPlayer);
	void SetPosition(Vector2 newPos);
	void SetVelocity(Vector2 newVelocity);
	Vector2 GetPos() const;
	Vector2 GetVelocity() const;
	float GetRadius() const;
	void Update();
	void Draw() const;
	void Unload();
	void CheckCollision();
	void ResetBall();

	Vector2 GetPosition() const; 


private:
	float mSpeed = 300;
	float mMaxVelocity = 1.3f;
	float mRadius;
	Vector2 mPos;
	Vector2 mVelocity = {1,-1};
	Color mColor = RED;
	Pad* mPlayer;
};