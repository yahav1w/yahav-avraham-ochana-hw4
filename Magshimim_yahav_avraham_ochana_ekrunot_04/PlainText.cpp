#include "PlainText.h"
#include <iostream>

int PlainText::numOfTexts = 0;

PlainText::PlainText(std::string text)
{
	_text = text;
	_isEncrypted = false;
	numOfTexts++;
}

PlainText::~PlainText()
{
}

bool PlainText::isEncrypted() const
{
	return _isEncrypted;
}

std::string PlainText::getText() const
{
	return _text;
}

std::ostream& operator<<(std::ostream& a, const PlainText& text)
{
	a << "Plain\n\n" << text._text;
	return a;

}
