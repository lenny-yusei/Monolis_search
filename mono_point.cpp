#include <iostream>
#include <string>
#include "mono_point.hpp"

std::string MonoPoint::string() const {
    std::string str = "";
    str += std::to_string(y + 1);
    str += ", ";
    str += std::to_string(x + 1);
    str = '(' + str + ')';
    return str;
}

std::ostream& operator<<(std::ostream& stream, const MonoPoint& value) {
    std::string str = value.string();
    stream << str.c_str();
    return stream;
}