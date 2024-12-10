#include "FileHelper.h"
#include <iostream>
#include <fstream>
#include <string>

//the function read from file and put it into string
//fileName - the name of the file
//return the text in the file
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

//the function write from one file to another
//inputfileName - the name of the file to take the input from
//outputFileName - the name of the file to put the input in
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

//the function save some text into a file
//text - the text to put in the file
//ouputFileName - the name of the file to put in the text
void FileHelper::saveTextInFile(const std::string text, const std::string outputFileName)
{
    std::ofstream outputFile(outputFileName);
    if (outputFile.is_open())
    {
        outputFile << text;
        outputFile.close();
    }
}
