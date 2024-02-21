//
// Created by Misha on 13.02.2024.
//


#include "../fill.h"
#include <gtest/gtest.h>

using namespace std;

TEST (fill_function, fill_an_image)
{
    const char *inputFileName = "tests\\test_data\\input1.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    EXPECT_TRUE(FillFiles(inputFileName, outputFileName));

    std::ifstream template1("tests\\test_data\\output1.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                               std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                            std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}


TEST (fill_function, fill_all)
{
    const char *inputFileName = "tests\\test_data\\input2.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    EXPECT_TRUE(FillFiles(inputFileName, outputFileName));

    std::ifstream template1("tests\\test_data\\output2.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                               std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                            std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}


TEST (fill_function, empty_test)
{
    const char *inputFileName = "tests\\test_data\\input3.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    EXPECT_TRUE(FillFiles(inputFileName, outputFileName));

    std::ifstream template1("tests\\test_data\\output3.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                               std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                            std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}



GTEST_API_ int main (int argc, char **argv)
{
    cout << "Running tests /n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}