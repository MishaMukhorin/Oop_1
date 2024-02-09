#include <iostream>
#include <fstream>

using namespace std;

string ReplaceLine(const string& line, const string& searchString, const string& replaceString)
{
    if (searchString.empty())
    {
        return line;
    }

    string result;
    size_t pos = 0;
    while (pos < line.length())
    {
        size_t foundPos = line.find(searchString, pos);
        result.append(line, pos, foundPos - pos);
        if (foundPos != string::npos)
        {
            result.append(replaceString);
            pos = foundPos + searchString.length();
        }
        else
        {
            return result;
        }
    }
    return result;
}

bool CopyFileWithReplacement(const string& inputFileName, const string& outputFileName, const string& searchString, const string& replaceString)
{
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        cout << "Failed to open input file." << endl;
        return false;
    }

    ofstream outputFile(outputFileName);
    string line;
    while (getline(inputFile, line))
    {
        outputFile << ReplaceLine(line, searchString, replaceString) << endl;
    }

    return !!outputFile.flush();

}

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        cout << "Invalid number of arguments." << endl
             << "Usage: replace.exe <input file> <output file> <search string> <replace string>"
             << endl;
        return 1;
    }

    return !CopyFileWithReplacement(argv[1], argv[2], argv[3], argv[4]);
}


