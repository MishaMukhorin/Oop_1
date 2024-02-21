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
#include <optional>

const char EMPTY_CELL = ' ';
const char BORDER_CELL = '#';
const char START_CELL = 'O';
const char FILLED_CELL = '.';
const int MAX_SIZE = 100;

//done type Map
using Map = std::vector<std::vector<char>>;

std::optional<Map> ReadInputFile(const char *fileName, Map& image);
bool WriteOutputFile(const std::string& filename, const Map& image);

void FillImage(Map& image);
bool FillFiles(const char* inputFileName, const std::string& outputFileName);

#endif //OOP_1_FILL_H
