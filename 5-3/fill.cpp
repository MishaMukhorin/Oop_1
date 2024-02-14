//
// Created by Misha on 13.02.2024.
//

#include "fill.h"

using namespace std;

bool ReadInputFile(const char *fileName, map& image)
{
    FILE *inputFile;
    int symbol;

    inputFile = fopen (fileName, "r");

    if (inputFile == nullptr)
    {
        return false;
    }
    int row = 0, col = 0;
    while (true)
    {
        symbol = fgetc(inputFile);
        if (symbol == EOF) break;
        if (symbol == '\n')
        {
            row++;
            col = 0;
            continue;
        }
        image[row][col] = char(symbol);
        col++;
    }
    fclose(inputFile);
    return true;
}

bool WriteOutputFile(const string& filename, const map& image)
{
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        for (const vector<char>& line : image)
        {
           for (const char& ch: line)
           {
               outputFile << ch;
           }
           outputFile << endl;
        }
        outputFile.close();
        return true;
    }
    return false;
}

void FillContour(map& image, int row, int col)
{
    queue<pair<int, int>> drawingQueue;

    if (row > 0) drawingQueue.emplace(row - 1, col);
    if (row < MAX_SIZE - 1) drawingQueue.emplace(row + 1, col);
    if (col > 0) drawingQueue.emplace(row, col - 1);
    if (col < MAX_SIZE - 1) drawingQueue.emplace(row, col + 1);

    while (!drawingQueue.empty())
    {
        auto [currRow, currCol] = drawingQueue.front();

        drawingQueue.pop();
        if (image[currRow][currCol] == EMPTY_CELL)
        {
            image[currRow][currCol] = FILLED_CELL;
            if (currRow > 0) drawingQueue.emplace(currRow - 1, currCol);
            if (currRow < MAX_SIZE - 1) drawingQueue.emplace(currRow + 1, currCol);
            if (currCol > 0) drawingQueue.emplace(currRow, currCol - 1);
            if (currCol < MAX_SIZE - 1) drawingQueue.emplace(currRow, currCol + 1);
        }
    }
}

void FillImage(map& image) {
    for (int row = 0; (row < image.size() and row < MAX_SIZE); row++)
    {
        for (int col = 0; (col < image[row].size() and col < MAX_SIZE); col++)
        {
            if (image[row][col] == START_CELL)
            {
                FillContour(image, row, col);
            }
        }
    }
}


bool ReadFillOut(const char* inputFileName, const std::string& outputFileName)
{
    map image (MAX_SIZE, std::vector<char>(MAX_SIZE));

    for (auto& row : image) {
        std::fill(row.begin(), row.end(), EMPTY_CELL);
    }

    if (!ReadInputFile(inputFileName, image))
    {
        cout << "Error opening input file - " << inputFileName <<  endl;
        return false;
    }

    FillImage(image);

    if (!WriteOutputFile(outputFileName, image))
    {
        cout << "Error opening output file - "  << outputFileName << endl;
        return false;
    }
    return true;
}
