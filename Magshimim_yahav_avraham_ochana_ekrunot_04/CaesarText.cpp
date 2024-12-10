#include "CaesarText.h"

#define KEY 3
//constroctor
CaesarText::CaesarText(const std::string string):ShiftText(string,KEY)
{
//does not need to be write anything in here because it all being done at the ShiftText constructor
}
//d'tor
CaesarText::~CaesarText()
{
}
//encrypt some message
// text - the message to encrypt
//return the encrypted massege
std::string CaesarText::encrypt(const std::string text)
{
	return ShiftText::encrypt(text, 3);
}

//encrypt some message 
// text - the message to decrypt
//return the encrypted massege
std::string CaesarText::decrypt(const std::string text)
{
	return ShiftText::decrypt(text,3);
}

//encrypt the message from higger calses
//return the encrypted massege
std::string CaesarText::encrypt()
{
	return ShiftText::encrypt();
}
//decrypt the message from higger calses
//return the decrypted massege
std::string CaesarText::decrypt()
{
	return ShiftText::decrypt();
}

//operator to print the class by using output standart methode
//a - the standart output stream
//text - the CeaserText class that contain text to return
//return an explanation about the kind of encrypt and the message
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
