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
        std::sort(str.begin(), str.end());
        str.assign(str.begin(), std::unique(str.begin(), str.end()));
    }
}
