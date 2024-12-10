#include "FileHelper.h"
#include <iostream>
#include <fstream>
#include <string>

std::string FileHelper::readFileToString(const std::string fileName)
{
    std::ifstream file;
    std::string line = "";
    std::string text = "";
    file.open(fileName);
    if (file.is_open())
    {
        while(getline(file, line))
        {
            text += line;
            if (!file.eof()) 
            {
                text += "\n";
            }
        }
        file.close();
    }
    return text;
}

void FileHelper::writeWordsToFile(const std::string inputFileName, const std::string outputFileName)
{
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);
    
    if (inputFile.is_open() && outputFile.is_open())
    {
        std::string text;
        while (inputFile>>text)
        { 
            outputFile << text ; 
            if (!(inputFile.eof()))
            {
                outputFile << "\n";
            }
        }

        inputFile.close();
        outputFile.close();
    }
}

void FileHelper::saveTextInFile(const std::string text, const std::string outputFileName)
{
    std::ofstream outputFile(outputFileName);
    if (outputFile.is_open())
    {
        outputFile << text;
        outputFile.close();
    }
}
