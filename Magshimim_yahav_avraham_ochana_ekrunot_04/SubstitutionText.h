#pragma once
#include "PlainText.h"

class SubstitutionText :public PlainText
{
private:
	std::string _dictionaryFileName;
public:
	SubstitutionText(const std::string text, const std::string dictionaryFileName);
	~SubstitutionText();
	static std::string encrypt(std::string text, std::string dictionaryFileName);
	static std::string decrypt(std::string text, std::string dictionaryFileName);
	std::string encrypt();
	std::string decrypt();
	friend std::ostream& operator<<(std::ostream& a, const SubstitutionText& text);
};

