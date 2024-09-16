#pragma once
#include "raylib.h"
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
	float mSpeed = 3;
	Vector2 mPos;
	Vector2 mDirection = {1,-1};
	float mRadius;
	Color mColor = RED;
};