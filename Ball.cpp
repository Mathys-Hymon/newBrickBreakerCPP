#include "ball.h"
#include <iostream>

Ball::Ball()
{
}

Ball::Ball(Vector2 newPosition, float newRadius, Color newColor, Pad* newPlayer)
{
    mPos = newPosition;
    mRadius = newRadius;
    mColor = newColor;
    mPlayer = newPlayer;
}

void Ball::SetPosition(Vector2 newPos)
{
    mPos = newPos;
}

void Ball::SetVelocity(Vector2 newVelocity)
{
    mVelocity = newVelocity;
}

Vector2 Ball::GetPos() const
{
    return mPos;
}

Vector2 Ball::GetVelocity() const
{
    return mVelocity;
}

float Ball::GetRadius() const
{
    return mRadius;
}

void Ball::Update()
{
    mPos.x += mVelocity.x * mSpeed * GetFrameTime();
    mPos.y += mVelocity.y * mSpeed * GetFrameTime();
    CheckCollision();
}


void Ball::Draw() const
{
	DrawCircle(mPos.x, mPos.y, mRadius, mColor);
}

Vector2 Ball::GetPosition() const
{
	return Vector2();
}

void Ball::Unload()
{
}

void Ball::CheckCollision()
{
    if (mPos.x - mRadius / 2 < 0) {
        mPos.x = 0 + mRadius / 2;
        mVelocity.x *= -1;
    }
    if (mPos.x + mRadius / 2 > GetScreenWidth()) {
        mPos.x = GetScreenWidth() - mRadius / 2;
        mVelocity.x *= -1;
    }
    if (mPos.y - mRadius / 2 < 0) {
        mPos.y = 0 + mRadius / 2;
        mVelocity.y *= -1;
    }

    if (mPos.x - (mRadius / 2) < mPlayer->GetPos().x + (mPlayer->GetSize().x / 2) &&
        mPos.x + (mRadius / 2) > mPlayer->GetPos().x - (mPlayer->GetSize().x / 2) &&
        mPos.y - (mRadius / 2) < mPlayer->GetPos().y + (mPlayer->GetSize().y / 2) &&
        mPos.y + (mRadius / 2) > mPlayer->GetPos().y - (mPlayer->GetSize().y / 2)) {

        mVelocity.y *= -1;

        if (mPos.x < mPlayer->GetPos().x) {
            mVelocity.x = -mMaxVelocity * (fabsf(mPlayer->GetPos().x - mPos.x) / (mPlayer->GetSize().x / 2));
        }
        else {
            mVelocity.x = mMaxVelocity * (fabsf(mPlayer->GetPos().x - mPos.x) / (mPlayer->GetSize().x / 2));
        }

        mMaxVelocity += 0.1f;
    }
}

void Ball::ResetBall()
{
    mVelocity = { 1, -1 };
}
