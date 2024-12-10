#pragma once
#include <string>
class PlainText
{
protected:
	std::string _text;//the text encrypt/decrypt
	bool _isEncrypted;//if the text is encrypt or not
public:
	static int numOfTexts;//how many times does a text that can be decryped or encrypt created
	PlainText(std::string text);//constractor
	~PlainText();//d'tor
	bool isEncrypted() const;//return if the text is encrypted
	std::string getText() const;//return the text itself
	friend std::ostream& operator<<(std::ostream& a, const PlainText& text);
};

