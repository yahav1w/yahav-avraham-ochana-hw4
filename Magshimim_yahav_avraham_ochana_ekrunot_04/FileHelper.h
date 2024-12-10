#pragma once
#include <string>

class FileHelper
{
public:
	static std::string readFileToString(const std::string fileName);
	static void writeWordsToFile(const std::string inputFileName,const std::string outputFileName);
	static void saveTextInFile(const std::string text,const std::string outputFileName);
};

