#include "read_parameter.h"
#include <algorithm>

namespace Program
{
    auto ReadCombinationParameters(std::istream& is)
        -> CombinationParameters
    {
        auto result = CombinationParameters { };
        
        std::cout << "Size: ";
        is >> result.size;
        
        std::cout << "Elements: ";
        is >> result.source;
        
        return result;
    }
    
    auto RemoveMultiples(std::string& str) -> void
    {
        str.assign(std::unique(str.begin(), str.end()), str.end());
    }
}
