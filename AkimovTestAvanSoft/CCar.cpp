#include "CCar.h"

CColor::CColor(int color)
{
	if (color <= 5 && color >= 0)
		this->color = static_cast<CColorTypes>(color);
	else
		this->color = CColorTypes::UNDEF;

}

CColorTypes CColor::getColor() const
{
	return this->color;
}

std::wstring CColor::getColorName() const
{
	switch (this->color)
	{
	case CColorTypes::UNDEF:
		return L"no color";
	case CColorTypes::Black:
		return L"Black";
	case CColorTypes::White:
		return L"White";
	case CColorTypes::Blue:
		return L"Blue";
	case CColorTypes::Red:
		return L"Red";
	case CColorTypes::Yellow:
		return L"Yellow";
	case CColorTypes::Green:
		return L"Green";
	default:
		return L"unidentified color";
	}
}

int CColor::getColorByName(std::wstring color)
{
	if (color == L"Black")
		return static_cast<int>(CColorTypes::Black);
	if (color == L"White")
		return static_cast<int>(CColorTypes::White);
	if (color == L"Blue")
		return static_cast<int>(CColorTypes::Blue);
	if (color == L"Red")
		return static_cast<int>(CColorTypes::Red);
	if (color == L"Yellow")
		return static_cast<int>(CColorTypes::Yellow);
	if (color == L"Green")
		return static_cast<int>(CColorTypes::Green);

	return -1;
}

CCar::CCar(int uniqueId, int price, int maxSpeed, int color) :
	uniqueId(-1),
	price(INT_MAX),
	maxSpeed(-1),
	color(-1)
{
	if (uniqueId >= 0)
		this->uniqueId = uniqueId;

	if (price > 0)
		this->price = price;

	if (maxSpeed > 0)
		this->maxSpeed = maxSpeed;
	
	this->color = color;
}

int CCar::getUniqueId()
{
	return this->uniqueId;
}

int CCar::getPrice()
{
	return this->price;
}

int CCar::getMaxSpeed()
{
	return this->maxSpeed;
}

std::wstring CCar::getColor()
{
	return this->color.getColorName();
}

CColorTypes CCar::getColorEnum()
{
	return this->color.getColor();
}

void CCar::setPrice(int price)
{
	this->price = price;
}
