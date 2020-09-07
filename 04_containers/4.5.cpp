// 4.5.cpp

#include <iostream>
#include <tuple>


auto get_student(int id) {
    if (id == 0)
        return std::make_tuple(3.8, 'A', "John");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "Jack");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "Ive");

    // it is not allowed to return 0 directly
    // return type is std::tuple<double, char, std::string>
    return std::make_tuple(0.0, 'D', "null");
}

int main() {
    auto student = get_student(0);

    std::cout << "ID: 0, "
            << "GPA: "   << std::get<0>(student) << ", "
            << "Grade: " << std::get<1>(student) << ", "
            << "Name: "  << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // unpack tuples
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
                << "GPA: " << gpa << ","
                << "Grade: " << grade << ", "
                << "Name: " << name << '\n';


    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
 
    // tuple value being extracted as type - std::string
    std::cout << std::get<std::string>(t) << std::endl;

    // error: static_assert failed due to requirement 'value != __ambiguous' "type occurs more than once in type list"
    // std::cout << std::get<double>(t) << std::endl;                   // illegal, runtime error
    
    // tuple value being extracted as index in tuple set
    std::cout << std::get<3>(t) << std::endl;

    return 0;
}
