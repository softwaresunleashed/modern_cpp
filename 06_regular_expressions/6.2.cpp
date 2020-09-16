// 6.2.cpp

#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};

    // In C++, `\` will be used as an escape character in the string.
    // In order for `\.` to be passed
    std::regex txt_regex("[a-z]+\\.txt");
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;

    for (const auto &fname: fnames)
        std::cout << fname << ": " << (std::regex_match(fname, txt_regex) ? "true" : "false") << std::endl;

    std::cout << std::endl;

    for(const auto &fname: fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // the first element of std::smatch matches the entire string
            // the second element of std::smatch matches the first expression with brackets
            if (base_match.size() == 2) {
                std::string base = base_match[1].str();
                std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
                std::cout << fname << " sub-match[1]: " << base << std::endl;
            }
        }
    }

}
