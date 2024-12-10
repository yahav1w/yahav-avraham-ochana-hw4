#pragma once
#include "PlainText.h"

class SubstitutionText :public PlainText
{
private:
	std::string _dictionaryFileName;//the file to use for the encrypt technic
public:
	SubstitutionText(const std::string text, const std::string dictionaryFileName);//constructor
	~SubstitutionText();//d'tor
	static std::string encrypt(std::string text, std::string dictionaryFileName);//encrypt some message using some file
	static std::string decrypt(std::string text, std::string dictionaryFileName);//encrypt some message using some file
	std::string encrypt();//encrypt the massage from the higher classes
	std::string decrypt();//encrypt the massage from the higher classes
	friend std::ostream& operator<<(std::ostream& a, const SubstitutionText& text);
};

