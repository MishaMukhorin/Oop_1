//
// Created by Misha on 08.02.2024.
//

#ifndef OOP_1_CRYPTFUNCTIONS_H
#define OOP_1_CRYPTFUNCTIONS_H

#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>


 //done не использовать namespase std в заголовочных файлах


bool HandleCommand(
        const std::string &mode,
        const std::string &inputFileName,
        const std::string &outputFileName,
        const std::string &keyStr
        );

char Encrypt(char symbol, int key);
char Decrypt(char symbol, int key);


#endif //OOP_1_CRYPTFUNCTIONS_H
