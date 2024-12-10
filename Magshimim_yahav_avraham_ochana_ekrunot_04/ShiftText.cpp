#include "ShiftText.h"

//constructor
ShiftText::ShiftText(std::string text, int key):PlainText(text)
{
	_key = key;
	_text = encrypt(text,key);
	_isEncrypted = true;
}

//d'tor
ShiftText::~ShiftText()
{
}

//the function encrypt some text
//text - to encrypt
//key - the key to encrypt with
//return the text encrypted
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

//the function decrypt some text
//text - to decrypt
//key - the key to decrypt with
//return the text decrypted
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


//the function encrypt the text of the higher classes
//return the text encrypted
std::string ShiftText::encrypt()
{
	if (!_isEncrypted)
	{
		_text = encrypt(_text, _key);
	}
	_isEncrypted = true;
	return _text;
}


//the function decrypt the text of the higher classes
//return the text decrypted
std::string ShiftText::decrypt()
{
	if (_isEncrypted)
	{
		_text = decrypt(_text, _key);
	}
	_isEncrypted = false;
	return _text;
}


//operator to print the class by using output standart methode
//a - the standart output stream
//text - the ShiftText class that contain text to return
//return an explanation about the kind of encrypt and the message
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
