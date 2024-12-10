#include "CaesarText.h"

#define KEY 3

CaesarText::CaesarText(const std::string string):ShiftText(string,KEY)
{
//does not need to be write anything in here because it all being done at the ShiftText constructor
}

CaesarText::~CaesarText()
{
}

std::string CaesarText::encrypt(const std::string text)
{
	return ShiftText::encrypt(text, 3);
}

std::string CaesarText::decrypt(const std::string text)
{
	return ShiftText::decrypt(text,3);
}

std::string CaesarText::encrypt()
{
	return ShiftText::encrypt();
}

std::string CaesarText::decrypt()
{
	return ShiftText::decrypt();
}

std::ostream& operator<<(std::ostream& a, const CaesarText& text)
{
	std::string kind = "Caesar\n\n";
	a << kind;
	if (!text.isEncrypted())
	{
		a << text.encrypt(text._text);
	}
	else
	{
		a << text._text;
	}
	return a;
}
