#pragma once
enum class BonusType
{
	SpeedUp,
	BonusBall,
	BiggerPad,
	SmallerPad,
	SpeedDown,
};

class Bonus
{
public:
	Bonus(BonusType type);
	~Bonus();

	void Update();
	void Draw();

private:
	BonusType mType;

};

