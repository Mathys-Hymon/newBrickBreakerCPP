#pragma once
#include "raylib.h"
class Pad
{
public:
	Pad();
	Pad(Vector2 newPos, Vector2 newSize, float newMaxSpeed, Color newColor);
	Vector2 GetPos();
	Vector2 GetSize();
	void Update();
	void Draw();
	void Unload();

private:
	Vector2 mPos;
	Vector2 mSize;
	float mMaxSpeed;
	Color mColor;
};

