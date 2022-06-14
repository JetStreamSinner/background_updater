#pragma once

#include <string>
#include <sstream>

// Implementation details
namespace details {
    template<typename Arg>
    void put_argument(std::ostream &os, const Arg &arg) {
        os << arg << " ";
    }

    template<typename Arg, typename... Args>
    void put_argument(std::ostream &os, const Arg &arg, Args... args) {
        put_argument(os, arg);
        put_argument(os, args...);
    }
}

template<typename... Args>
std::string error_formatter(Args... args) {
    std::stringstream ss;
    details::put_argument(ss, args...);
    return ss.str();
}
