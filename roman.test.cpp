#include <iostream>
#include "Roman.h"

int main(int argc, const char * argv[]) {
    static_assert(1 == roman::to_int('I'), "roman number value");
    static_assert(5 == roman::to_int('V'), "roman number value");
    static_assert(10 == roman::to_int('X'), "roman number value");
    static_assert(50 == roman::to_int('L'), "roman number value");
    static_assert(100 == roman::to_int('C'), "roman number value");
    static_assert(500 == roman::to_int('D'), "roman number value");
    static_assert(1000 == roman::to_int('M'), "roman number value");
    static_assert(1324 == roman::to_int("MCCCXXIV"), "compile time computation");

    // runtime version
    std::string s = "XLII";
    std::cout << "Answer to The Ultimate Question of Life, the Universe, and Everything: " << roman::to_int(s);
    return 0;
}
