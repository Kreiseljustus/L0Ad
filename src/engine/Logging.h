#pragma once
#include <iostream>
#define print(str) do {std::cout << str << std::endl;} while(0)
#define printc(str, type, color) do {std::cout << "\033[" << type << ";" << color << "m" << str << "\033[0m" << std::endl;} while(0)
#define printcN(str, type, color) do {std::cout << "\033[" << type << ";" << color << "m" << str << "\033[0m";} while(0)

#define printError(str) do {printc(std::string("[ERROR] ") + str, 0, 31);} while(0)