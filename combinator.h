#pragma once 

#include "impl.h"
#include <string>
#include <vector>
#include <cstddef>

namespace Program
{
    class Combinator final
    {
    public:
        Combinator() = default;
        Combinator(CombinationParameters); // Not a reference
                                           // Gets moved
        
        auto SetParameters(CombinationParameters) -> void; // Ditto
        auto GetParameters() const -> CombinationParameters;
        
        auto Result() const -> Impl::Result_t;
        
    private:
        mutable Impl m_impl { }; // Does the complex stuff
    };
}
