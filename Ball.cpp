#include "ball.h"

void Ball::Initialize(Vector2 newPosition, float newRadius, Color newColor, Pad& pad)
{
	mPos = newPosition;
	mRadius = newRadius;
	mColor = newColor;
}

void Ball::Update()
{
    mPos.x += mDirection.x * mSpeed * GetFrameTime();
    mPos.y += mDirection.y * mSpeed * GetFrameTime();

    if (mPos.x - mRadius / 2 < 0) {
        mPos.x = 0 + mRadius / 2;
        mDirection.x *= -1;
    }
    if (mPos.x + mRadius / 2 > GetScreenWidth()) {
        mPos.x = GetScreenWidth() - mRadius / 2;
        mDirection.x *= -1;
    }
    if (mPos.y - mRadius / 2 < 0) {
        mPos.y = 0 + mRadius / 2;
        mDirection.y *= -1;
    }
    if (mPos.y + mRadius / 2 > GetScreenHeight()) {
        mPos.y = GetScreenHeight() - mRadius / 2;
        mDirection.y *= -1;
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
