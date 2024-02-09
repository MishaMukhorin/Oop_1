//
// Created by Misha on 08.02.2024.
//
#include "cryptFunctions.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        cout << "Usage: crypt.exe <mode> <input file> <output file> <key>" << endl;
        return 1;
    }
    string mode = argv[1];
    string inputFileName = argv[2];
    string outputFileName = argv[3];
    string keyStr = argv[4];

    return HandleCommand(mode, inputFileName, outputFileName, keyStr);
}