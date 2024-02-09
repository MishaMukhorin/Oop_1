
#include "cryptFunctions.h"

using namespace std;

// done stoi

//done upper camel case
char Encrypt(char symbol, int key)
{
    char result;
    symbol ^= key;
    result = 0b00000000;
    result = result | ((0b10000000 & symbol) >> 2)
            | ((0b01100000 & symbol) >> 5)
            | ((0b00011000 & symbol) << 3)
            | ((0b00000111 & symbol) << 2);
    return result;
}
// done std::transform crypt è decrypt
char Decrypt(char symbol, int key)
{
    char result;
    result = 0b00000000;
    result = result
            | ((0b11000000 & symbol) >> 3)
            | ((0b00100000 & symbol) << 2)
            | ((0b00011100 & symbol) >> 2)
            | ((0b00000011 & symbol) << 5);
    result ^= key;
    return result;
}

bool HandleCommand(const string &mode, const string &inputFileName, const string &outputFileName, const string &keyStr)
{
    if (!stoi(keyStr))
    {
        cout << "Error reading key. Is must be an integer" << endl;
        return false;
    }
    int key = stoi(keyStr);
    if (key < 0 || key > 255)
    {
        cout << "Error reading key. An integer must be in range [0, 255]" << endl;
        return false;
    }
    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile)
    {
        cout << "Error opening input file - " << inputFileName << " . " <<  endl;
        return false;
    }
    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile)
    {
        cout << "Error opening output file."  << outputFileName << " . " << endl;
        return false;
    }

    if (mode == "crypt")
    {
        std::transform(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(),
                       std::ostreambuf_iterator<char>(outputFile),
                       [key](char c) { return Encrypt(c, key); });
    }
    else if (mode == "decrypt")
    {
        std::transform(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(),
                       std::ostreambuf_iterator<char>(outputFile),
                       [key](char c) { return Decrypt(c, key); });
    }
    else
    {
        cout << "Invalid mode." << endl;
        return false;
    }
    inputFile.close();
    outputFile.close();
    return true;
}


