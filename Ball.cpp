#include "ball.h"

void Ball::Initialize(Vector2 newPosition, float newRadius, Color newColor, Pad& pad)
{
	mPos = newPosition;
	mRadius = newRadius;
	mColor = newColor;
}

void Ball::Update()
{
	if (mPos.x < GetScreenWidth() -mRadius) {
		mPos.x += mDirection.x * mSpeed;
	}
	else {
		mDirection.x = 1;
	}

	if (mPos.x > 0 + mRadius) {
		mDirection.x = -1;
	}

	if (mPos.y < GetScreenHeight() - mRadius && mPos.y > 0 + mRadius) {

	}
	else {

	}
	
}


void Ball::Draw()
{
	DrawCircle(mPos.x, mPos.y, mRadius, mColor);
}

Vector2 Ball::GetPosition()
{
	return Vector2();
}

void Ball::Unload()
{
}

void Ball::FlipX()
{
	mDirection.x *= -1;
}

void Ball::FlipY()
{
	mDirection.y *= -1;
}
