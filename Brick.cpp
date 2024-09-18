#include "brick.h"

Brick::Brick()
{
}

Brick::Brick(Vector2 newPos, Vector2 newSize, Color newColor, Ball* newBall)
{
	mPos = newPos;
	mSize = newSize;
	mColor = newColor;
	mBall = newBall;
}

void Brick::Draw() const
{
    DrawRectangle((mPos.x - mSize.x / 2) + 1, (mPos.y - mSize.y / 2) + 1, mSize.x - 2, mSize.y - 2, mColor);
}

bool Brick::CheckCollision()
{
	if (mBall != nullptr) {
        if (mPos.x - (mSize.x / 2) < mBall->GetPos().x + (mBall->GetRadius() / 2) &&
            mPos.x + (mSize.x / 2) > mBall->GetPos().x - (mBall->GetRadius() / 2) &&
            mPos.y - (mSize.y / 2) < mBall->GetPos().y + (mBall->GetRadius() / 2) &&
            mPos.y + (mSize.y / 2) > mBall->GetPos().y - (mBall->GetRadius() / 2)) {

            // GAUCHE
            if (mBall->GetPos().x - (mBall->GetRadius() / 2) < mPos.x - (mSize.x / 2)) {
                mBall->SetVelocity({ -mBall->GetVelocity().x, mBall->GetVelocity().y });
                //mBall->SetPosition({ mPos.x - ((mSize.x + mBall->GetRadius()) / 2), mBall->GetPosition().y });

            }
            // DROITE
            else if (mBall->GetPosition().x + (mBall->GetRadius() / 2) > mSize.x + (mSize.x / 2)) {
                mBall->SetVelocity({ -mBall->GetVelocity().x, mBall->GetVelocity().y });
                //mBall->SetPosition({ mPos.x + ((mSize.x + mBall->GetRadius()) / 2), mBall->GetPosition().y });
            }
            // HAUT
            if (mBall->GetPosition().y - (mBall->GetRadius() / 2) < mSize.y - (mSize.y / 2)) {
                mBall->SetVelocity({ mBall->GetVelocity().x, -mBall->GetVelocity().y });
               // mBall->SetPosition({ mBall->GetPosition().x, mPos.y - ((mSize.y + mBall->GetRadius()) / 2) });
            }
            // BAS
            else if (mBall->GetPosition().y + (mBall->GetRadius() / 2) > mSize.y + (mSize.y / 2)) {
                mBall->SetVelocity({ mBall->GetVelocity().x, -mBall->GetVelocity().y });
             //   mBall->SetPosition({ mBall->GetPosition().x, mPos.y + ((mSize.y + mBall->GetRadius()) / 2) });
            }
            }
            return true;
        }
        else {
            return false;
        }
}

bool Brick::GetAlive()
{
	return mAlive;
}

Brick::~Brick()
{
}
