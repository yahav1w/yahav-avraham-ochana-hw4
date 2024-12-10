#pragma once
#include <string>

class FileHelper
{
public:
	static std::string readFileToString(const std::string fileName);//read from file to string 
	static void writeWordsToFile(const std::string inputFileName,const std::string outputFileName);//write fro, string to file
	static void saveTextInFile(const std::string text,const std::string outputFileName);// save the text in a file
};

