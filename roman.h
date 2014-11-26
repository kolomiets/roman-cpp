
#ifndef roman_h
#define roman_h

namespace roman
{
    // forward declaration
    constexpr int to_int(const char symbol);
    
    namespace _impl
    {
        constexpr int subtractive_value(const int value, const int nextValue)
        {
            return value < nextValue ? -value : value;
        }
        
        constexpr int roman_to_int(const char* const literal, const unsigned long N, const int index, const int value)
        {
            return (index == N)
            ? value
            : roman_to_int(literal, N, index + 1, value + ((index + 1) < N
                                                           ? subtractive_value(to_int(literal[index]), to_int(literal[index + 1]))
                                                           : to_int(literal[index])));
        }
    }
    
    /**
     * Compile time version - converts roman number (symbol) to integer value.
     */
    constexpr int to_int(const char symbol)
    {
        return (symbol == 'M') ? 1000
        : (symbol == 'D') ? 500
        : (symbol == 'C') ? 100
        : (symbol == 'L') ? 50
        : (symbol == 'X') ? 10
        : (symbol == 'V') ? 5
        : (symbol == 'I') ? 1
        : 0;
    }
    
    /**
     * Compile time version - allows to construct numeric value from roman number string literal.
     */
    template<unsigned int N>
    constexpr int to_int(const char(&literal)[N])
    {
        return _impl::roman_to_int(literal, N, 0, 0);
    }
    
    /**
     * Runtime version - allows to convert specified roman number string to numeric value.
     */
    int to_int(const std::string& s)
    {
        return _impl::roman_to_int(s.c_str(), s.size(), 0, 0);
    }
}

#endif // roman_h
