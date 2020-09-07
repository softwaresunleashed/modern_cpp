// 4.6.cpp

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

// Define a tuple with variable number of parameters
std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);

int main()
{
    int i = 0;                                          // Tuples members are zero indexed
    std::cout << tuple_index(t, i) << std::endl;        // output : 123

    i = 2;
    std::cout << tuple_index(t, i) << std::endl;        // output : 6.7
}
