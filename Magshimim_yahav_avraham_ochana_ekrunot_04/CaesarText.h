#pragma once
#include "ShiftText.h"

class CaesarText :public ShiftText
{
public:
	CaesarText(std::string string);//constructor
	~CaesarText();//d'tor
	static std::string encrypt(const std::string text);//encrypt some message
	static std::string decrypt(const std::string text);//decrypt some massage
	std::string encrypt();//encrypt the massage from the higher classes
	std::string decrypt();//decrtpy the massage from the higher classes
	friend std::ostream& operator<<(std::ostream& a, const CaesarText& text);
};

