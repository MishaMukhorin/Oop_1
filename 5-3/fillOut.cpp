//
// Created by Misha on 13.02.2024.
//

#include "fill.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: FillContour.exe <input file> <output file>" << endl;
        return 1;
    }

    return !ReadFillOut(argv[1], argv[2]);
}