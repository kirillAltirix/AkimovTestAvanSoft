#pragma once

#include <string>

enum class CColorTypes {
	UNDEF = -1,
	Black = 0,
	White = 1,
	Blue = 2,
	Red = 3,
	Yellow = 4,
	Green = 5
};

class CColor {
public:

	CColor(int color);
	~CColor() = default;

	CColorTypes getColor() const;
	std::wstring getColorName() const;

	static int getColorByName(std::wstring);

private:

	CColorTypes color;

};

class CCar {
public:
	CCar(int uniqueId, int price, int maxSpeed, int color);

	int getUniqueId();
	int getPrice();
	int getMaxSpeed();
	std::wstring getColor();
	CColorTypes getColorEnum();

	void setPrice(int price);

private:

	int uniqueId;
	int price;
	int maxSpeed;
	CColor color;
};
