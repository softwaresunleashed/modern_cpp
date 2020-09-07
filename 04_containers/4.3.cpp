// 4.3.cpp

#include <iostream>
#include <array>

void foo(int *p, int len) {
    return;
}

int main() {

    // array size must be constexpr
    constexpr int len = 4;
    std::array<int, len>arr = {1, 4, 2, 3};

    // illegal, different than C-style array, std::array will not deduce to T*
    // int *arr_p = arr;

    if(!arr.empty()) {                                              // check if container is empty
        std::cout << "array size = " << arr.size() << std::endl;    // return the size of the container
    }

    std::cout << "arr elements (before sorting) : ";
    // iterator support for std::array
    for (auto &i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // use lambda expression for sort
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return b < a;
    });

    std::cout << "arr elements (after sorting) : ";
    // iterator support for std::array
    for (auto &i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
