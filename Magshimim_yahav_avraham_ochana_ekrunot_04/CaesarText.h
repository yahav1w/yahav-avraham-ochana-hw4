#pragma once
#include "ShiftText.h"

class CaesarText :public ShiftText
{
public:
	CaesarText(std::string string);
	~CaesarText();
	static std::string encrypt(const std::string text);
	static std::string decrypt(const std::string text);
	std::string encrypt();
	std::string decrypt();
	friend std::ostream& operator<<(std::ostream& a, const CaesarText& text);
};

