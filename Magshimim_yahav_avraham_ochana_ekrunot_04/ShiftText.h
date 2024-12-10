#pragma once
#include "PlainText.h"
class ShiftText:public PlainText
{
private:
	int _key;//the key to shift with
public:
	ShiftText(std::string text, int key);//constructor
	~ShiftText();//d'tor
	static std::string encrypt(std::string text, int key);//encrypt some message
	static std::string decrypt(std::string text, int key);//decrypt some message
	std::string encrypt();//encrypt the massage from the higher classes
	std::string decrypt();//decrypt the massage from the higher classes
	friend std::ostream& operator<<(std::ostream& a, const ShiftText& text);
};

