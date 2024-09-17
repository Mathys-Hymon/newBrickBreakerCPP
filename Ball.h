#pragma once
#include "Pad.h"

class Ball
{
public:
	void Initialize(Vector2 newPosition, float newRadius, Color newColor,Pad& pad);
	void Update();
	void Draw();
	void Unload();

	void FlipX();
	void FlipY();

	Vector2 GetPosition();


private:
	float mSpeed = 150;
	Vector2 mPos;
	Vector2 mDirection = {1,-1};
	float mRadius;
	Color mColor = RED;
};