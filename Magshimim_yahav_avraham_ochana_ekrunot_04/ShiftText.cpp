#include "ShiftText.h"

ShiftText::ShiftText(std::string text, int key):PlainText(text)
{
	_key = key;
	_text = encrypt(text,key);
	_isEncrypted = true;
}

ShiftText::~ShiftText()
{
}

std::string ShiftText::encrypt(std::string text, int key)
{
	std::string temp = text;
	for (int i = 0;i < temp.length();i++)
	{
		if (!(temp[i] == ' ' || temp[i] == ',' || temp[i] == '.'))
		{
			temp[i] = char((temp[i]-'a'+key)%26 + 'a');
		}
	}
	return temp;
}

std::string ShiftText::decrypt(std::string text, int key)
{
	std::string temp = text;
	for (int i = 0;i < temp.length();i++)
	{
		if (!(temp[i] == ' ' || temp[i] == ',' || temp[i] == '.'))
		{
			temp[i] = char((temp[i] - 'a' - key + 26) % 26 + 'a');
		}
	}
	return temp;
}

std::string ShiftText::encrypt()
{
	if (!_isEncrypted)
	{
		_text = encrypt(_text, _key);
	}
	_isEncrypted = true;
	return _text;
}

std::string ShiftText::decrypt()
{
	if (_isEncrypted)
	{
		_text = decrypt(_text, _key);
	}
	_isEncrypted = false;
	return _text;
}


std::ostream& operator<<(std::ostream& a, const ShiftText& text)
{
	std::string kind = "Shift\n\n";
	a << kind;
	if (!text.isEncrypted())
	{
		a << text.encrypt(text._text, text._key);
	}
	else
	{
		a << text._text;
	}
	return a;
}
