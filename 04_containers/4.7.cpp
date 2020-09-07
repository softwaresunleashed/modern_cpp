// 4.7.cpp

#include <variant>
#include <iostream>

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i) {
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range(" .");
    if (i == n)
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl)};

    return _tuple_index<(n < sizeof...(T)-1 ? n+1 : 0)>(tpl, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i) {
    return _tuple_index<0>(tpl, i);
}

template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) {
    std::visit([&](auto && x){ s << x;}, v);
    return s;
}

template <typename T>
auto tuple_len(T &tpl) {
    return std::tuple_size<T>::value;
}

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

// Define a tuple with variable number of parameters
std::tuple<double, char, std::string> tuple(4.5, 'E',"Paul");

int main()
{
    auto new_tuple = std::tuple_cat(get_student(0), std::move(tuple));

    auto tpl_len = tuple_len(new_tuple);
    for(int i = 0; i != tpl_len; ++i){
        // runtime indexing
        std::cout << tuple_index(new_tuple, i) << std::endl;
    }
}
