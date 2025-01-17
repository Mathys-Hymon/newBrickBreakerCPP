#include "pad.h"


Pad::Pad()
{
}

Pad::Pad(Vector2 newPos, Vector2 newSize, float newMaxSpeed, Color newColor)
{
    mPos = newPos;
    mSize = newSize;
    mMaxSpeed = newMaxSpeed;
    mColor = newColor;
}

Vector2 Pad::GetPos()
{
    return mPos;
}

Vector2 Pad::GetSize()
{
    return mSize;
}

void Pad::Update()
{
    float mouseX = GetMouseX();
    if (mouseX < 0 + mSize.x / 2) {
        mouseX = 0 + mSize.x / 2;
    }
    if (mouseX > GetScreenWidth() - mSize.y / 2) {
        mouseX = GetScreenWidth() - mSize.y / 2;
    }
    mPos.x += (mouseX - mPos.x) * 3 * GetFrameTime();
}

void Pad::Draw()
{
	DrawRectangle(mPos.x - mSize.x/2, mPos.y - mSize.y/2, mSize.x, mSize.y, mColor);
}

void Pad::Unload()
{
}
