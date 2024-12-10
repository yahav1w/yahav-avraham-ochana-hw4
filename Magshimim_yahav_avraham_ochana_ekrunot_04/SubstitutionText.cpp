#include "SubstitutionText.h"
#include <fstream>

SubstitutionText::SubstitutionText(const std::string text, const std::string dictionaryFileName):PlainText(text)
{
	_dictionaryFileName = dictionaryFileName;
	_text = encrypt(text, dictionaryFileName);
	_isEncrypted = true;
}

SubstitutionText::~SubstitutionText()
{
}

std::string SubstitutionText::encrypt(std::string text, std::string dictionaryFileName)
{
	std::string line;
	std::ifstream file;
	bool findLetter = false;
	int pos = 0;
	for (int i = 0;i < text.length();i++)
	{
		file.open(dictionaryFileName);
		if (file.is_open())
		{
			while (getline(file, line)&&!findLetter)
			{
				pos = line.find(',');
				if (text[i] == line[pos - 1])
				{
					text[i] = line[pos + 1];
					findLetter = true;
				}
			}
			findLetter = false;
			file.close();
		}
	}
	return text;
}

std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{
	std::string line;
	std::ifstream file;
	bool findLetter = false;
	int pos = 0;
	for (int i = 0;i < text.length();i++)
	{
		file.open(dictionaryFileName);
		if (file.is_open())
		{
			while (getline(file, line) && !findLetter)
			{
				pos = line.find(',');
				if (text[i] == line[pos + 1])
				{
					text[i] = line[pos - 1];
					findLetter = true;
				}
			}
			file.close();
			findLetter = false;
		}
	}
	return text;
}

std::string SubstitutionText::encrypt()
{
	if (!_isEncrypted)
	{
		_text = encrypt(_text, _dictionaryFileName);
	}
	_isEncrypted = true;
	return _text;
}

std::string SubstitutionText::decrypt()
{
	if (_isEncrypted)
	{
		_text = decrypt(_text, _dictionaryFileName);
	}
	_isEncrypted = false;
	return _text;
}


std::ostream& operator<<(std::ostream& a, const SubstitutionText& text)
{
	std::string kind = "Substitution\n\n";
	a << kind;
	if (!text.isEncrypted())
	{
		a << text.encrypt(text._text,text._dictionaryFileName);
	}
	else
	{
		a << text._text;
	}
	return a;
}
