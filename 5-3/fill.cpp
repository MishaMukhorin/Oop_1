//
// Created by Misha on 13.02.2024.
//

#include "fill.h"

using namespace std;

optional<Map> ReadInputFile(const char *fileName)
{
    Map image (MAX_SIZE, std::vector<char>(MAX_SIZE, EMPTY_CELL));
    FILE *inputFile;
    int symbol;

    inputFile = fopen (fileName, "r");

    if (inputFile == nullptr)
    {
        return nullopt;
    }
    int row = 0, col = 0;
    while (true)
    {
        symbol = fgetc(inputFile);
        if (symbol == EOF or row >= MAX_SIZE - 1) break;
        if (symbol == '\n' or col >= MAX_SIZE - 1)
        {
            row++;
            col = 0;
            continue;
        }
        image[row][col] = char(symbol);
        col++;
    }
    fclose(inputFile);
    return image;
}

bool WriteOutputFile(const string& filename, const Map& image)
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


//done rename IsFillable
bool IsFillable(const Map& image, int row, int col)
{
    // fixed выход за границы
    if ((row >= 0) and (col >= 0) and (row < MAX_SIZE) and (col < MAX_SIZE))
    {
        return (image[row][col] == EMPTY_CELL);
    }
    else
    {
        return false;
    }
}

void FillCellsAround(const Map& image, stack<pair<int, int>>& drawingStack, int row, int col)
{
     auto enstackCell = [&image, &drawingStack](int r, int c)
             {
                 if (IsFillable(image, r, c)) drawingStack.emplace(r, c);
             };

     enstackCell(row - 1, col);
     enstackCell(row + 1, col);
     enstackCell(row, col - 1);
     enstackCell(row, col + 1);
}

void FillContour(Map& image, int row, int col)
{
    stack<pair<int, int>> drawingStack;

    //done устранить дублирование
    FillCellsAround(image, drawingStack, row, col);

    while (!drawingStack.empty())
    {
        auto [currRow, currCol] = drawingStack.top();
        drawingStack.pop();
        image[currRow][currCol] = FILLED_CELL;
        FillCellsAround(image, drawingStack, currRow, currCol);
    }
}

void FillImage(Map& image) {
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


//done FillFiles
bool FillFiles(const char* inputFileName, const std::string& outputFileName)
{
    //done optional or ex
    //done передать заполняемое значение
    optional<Map> optImage = ReadInputFile(inputFileName) ;

    if (!optImage)
    {
        cout << "Error opening input file - " << inputFileName <<  endl;
        return false;
    }

    Map image = optImage.value();
    FillImage(image);

    if (!WriteOutputFile(outputFileName, image))
    {
        cout << "Error opening output file - "  << outputFileName << endl;
        return false;
    }
    return true;
}
