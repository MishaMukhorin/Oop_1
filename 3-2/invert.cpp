#include <iostream>
#include <fstream>
#include <iomanip>
#include <optional>

using namespace std;

const int N = 3;

using matrix2 = std::array<std::array<double, 2>, 2>;

using matrix3 = std::array<std::array<double, 3>, 3>;               //done make array

double FindDet2(const matrix2 a)
{
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

matrix2 TakeMinor(const matrix3 a, int i, int j)     //done function
{
    matrix2 minor;
    for (int majorX = 0, minorX = 0; majorX < N; ++majorX)
    {
        if (majorX == i) continue;
        for (int majorY = 0, minorY = 0; majorY < N; ++majorY)
        {
            if (majorY == j) continue;
            minor[minorX][minorY] = a[majorX][majorY];
            ++minorY;
        }
        ++minorX;
    }
    return minor;
}

double FindDet3(matrix3 a)
{
    double det = 0;
    matrix2 b;
    for (int i = 0; i < 3; ++i)
    {
        b = TakeMinor(a, i, 0);
        det += (i & 1 ? -1 : 1) * a[i][0] * FindDet2(b);
    }
    return det;
}

std::optional<matrix3> InvertMatrix(const matrix3& matrix)
{
    double det = FindDet3(matrix);
    if (det == 0)
        return std::nullopt;

    matrix3 invertedMatrix{};
    matrix2 minor{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            minor = TakeMinor(matrix, i, j);
            invertedMatrix[j][i] = ((i + j) & 1 ? -1 : 1) * FindDet2(minor) / det;
            if (invertedMatrix[j][i] == 0.0)   //Avoiding negative zero
                invertedMatrix[j][i] = 0.0;
        }
    return invertedMatrix;
}

//return optional
bool ReadMatrix(const string& inputFileName, matrix3& a)
{
    ifstream input(inputFileName);
    if (!input.is_open())
    {
        cout << "Unable to open input file" << endl;
        return false;
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (input.eof())
            {
                cout << "Invalid data format in input file" << endl;
                return false;
            }
            input >> a[i][j];//check result
        }
    return true;
}

//empty optional\//in main
bool ReverseMatrixCalculation(int argc, const string& inputFileName, std::optional<matrix3> invertedMatrix)
{
    if (argc != 2)
    {
        cout << "Usage: invert.exe <matrix3 file1>" << endl;
        return false;
    }

    matrix3 matrix{};
    if (!ReadMatrix(inputFileName, matrix))
        return false;

    invertedMatrix = InvertMatrix(matrix);
    if (!invertedMatrix)
    {
        cout << "No inverse exists" << endl;
        return false;
    }

    //function
    cout << fixed << setprecision(3);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cout << (*invertedMatrix)[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main(int argc, char *argv[])
{
    std::optional<matrix3> invertedMatrix{};
    return !ReverseMatrixCalculation(argc, argv[1], invertedMatrix);
}


