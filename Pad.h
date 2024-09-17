#pragma once
#include "raylib.h"
class Pad
{
public:
	void Initialize(Vector2 newPos, Vector2 newSize, float newMaxSpeed, Color newColor);
	void Update();
	void Draw();
	void Unload();

private:
	Vector2 mPos;
	Vector2 mSize;
	float mMaxSpeed;
	Color mColor;
};

