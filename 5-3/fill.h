//
// Created by Misha on 13.02.2024.
//

#ifndef OOP_1_FILL_H
#define OOP_1_FILL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <chrono>

const char EMPTY_CELL = ' ';
const char BORDER_CELL = '#';
const char START_CELL = '0';
const char FILLED_CELL = '.';
const int MAX_SIZE = 100;

using map = std::vector<std::vector<char>>;

bool ReadInputFile(const char *fileName, map& image);
bool WriteOutputFile(const std::string& filename, const map& image);

void FillImage(map& image);
bool ReadFillOut(const char* inputFileName, const std::string& outputFileName);

#endif //OOP_1_FILL_H
