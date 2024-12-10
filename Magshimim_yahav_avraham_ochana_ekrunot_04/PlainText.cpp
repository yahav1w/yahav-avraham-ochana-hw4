#include "PlainText.h"
#include <iostream>

int PlainText::numOfTexts = 0;

//constructor
PlainText::PlainText(std::string text)
{
	_text = text;
	_isEncrypted = false;
	numOfTexts++;
}
//d'tor
PlainText::~PlainText()
{
}

//return if the text encrypted of not
bool PlainText::isEncrypted() const
{
	return _isEncrypted;
}

//return the text
std::string PlainText::getText() const
{
	return _text;
}


//operator to print the class by using output standart methode
//a - the standart output stream
//text - the PlainText class that contain text to return
//return an explanation about the kind of encrypt and the message
std::ostream& operator<<(std::ostream& a, const PlainText& text)
{
	a << "Plain\n\n" << text._text;
	return a;

}
