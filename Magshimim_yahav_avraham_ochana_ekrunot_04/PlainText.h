#pragma once
#include <string>
class PlainText
{
protected:
	std::string _text;
	bool _isEncrypted;
public:
	static int numOfTexts;
	PlainText(std::string text);
	~PlainText();
	bool isEncrypted() const;
	std::string getText() const;
	friend std::ostream& operator<<(std::ostream& a, const PlainText& text);
};

