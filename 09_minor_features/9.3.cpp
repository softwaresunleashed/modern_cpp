// 9.3.cpp - No need to escape special characters with "R" raw string literal

#include <iostream>
#include <string>

int main() {
    std::string str1 = "C:\\Path\\To\\File";
    std::string str2 = R"(C:\Path\To\File)";     /* New "R" literal in C++ */

    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    return 0;
}
