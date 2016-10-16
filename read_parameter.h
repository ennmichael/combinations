#pragma once

#include "combinator.h"
#include <iostream>
#include <algorithm>

namespace Program
{
    auto ReadCombinationParameters(std::istream&)
        -> CombinationParameters;
    auto RemoveMultiples(std::string& str) -> void;
    
    template <class Ostream, class Container>
    Ostream& operator<<(Ostream& ostream, const Container& container)
    {
        std::for_each(container.cbegin(), container.cend(),
                      [&ostream](const auto& elem) noexcept
                      {
                          ostream << elem << std::endl;
                      });
        
        return ostream;
    }
}
