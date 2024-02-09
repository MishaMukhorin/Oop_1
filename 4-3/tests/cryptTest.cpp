//
// Created by Misha on 08.02.2024.
//
#include "../cryptFunctions.h"
#include <gtest/gtest.h>

using namespace std;

TEST (encrypt_function, crypt_a_string)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in1.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));


    std::ifstream template1("tests\\test_data\\out1.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}
TEST (decrypt_function, decrypt_a_string)
{
    string mode = "decrypt";
    string inputFileName = "tests\\test_data\\in2.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));


    std::ifstream template2("tests\\test_data\\out2.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template2)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}
TEST (encrypt_function, crypt_then_decrypt_a_string)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in3.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    mode = "decrypt";
    inputFileName = "tests\\test_data\\spare.txt";
    outputFileName = "tests\\test_data\\spare2.txt";
    keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));


    std::ifstream template3("tests\\test_data\\out3.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template3)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare2.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}
TEST (encrypt_function, crypt_then_decrypt_english_strings)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in4.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    mode = "decrypt";
    inputFileName = "tests\\test_data\\spare.txt";
    outputFileName = "tests\\test_data\\spare2.txt";
    keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    std::ifstream template1("tests\\test_data\\out4.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare2.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}
TEST (encrypt_function, crypt_then_decrypt_numbers)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in5.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    mode = "decrypt";
    inputFileName = "tests\\test_data\\spare.txt";
    outputFileName = "tests\\test_data\\spare2.txt";
    keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    std::ifstream template1("tests\\test_data\\out5.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare2.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}\

TEST (encrypt_function, crypt_then_decrypt_new_line_eof)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in6.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    mode = "decrypt";
    inputFileName = "tests\\test_data\\spare.txt";
    outputFileName = "tests\\test_data\\spare2.txt";
    keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));

    std::ifstream template1("tests\\test_data\\out6.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                        std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare2.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                        std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}


TEST (encrypt_function, test_empty_file)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in7.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "27";
    EXPECT_TRUE(HandleCommand(mode, inputFileName, outputFileName, keyStr));


    std::ifstream template1("tests\\test_data\\in7.txt");
    std::string expectedOutput((std::istreambuf_iterator<char>(template1)),
                               std::istreambuf_iterator<char>());
    std::ifstream spare("tests\\test_data\\spare.txt");
    std::string givenOutput((std::istreambuf_iterator<char>(spare)),
                            std::istreambuf_iterator<char>());

    EXPECT_EQ(givenOutput, expectedOutput);
}
TEST (encrypt_function, test_wrong_key)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in7.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "2831";
    EXPECT_FALSE(HandleCommand(mode, inputFileName, outputFileName, keyStr));
}

TEST (encrypt_function, test_wrong_key_2)
{
    string mode = "crypt";
    string inputFileName = "tests\\test_data\\in7.txt";
    string outputFileName = "tests\\test_data\\spare.txt";
    string keyStr = "-2";
    EXPECT_FALSE(HandleCommand(mode, inputFileName, outputFileName, keyStr));
}

GTEST_API_ int main (int argc, char **argv)
{
    cout << "Running tests /n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}