#pragma once

#include <vector>
#include <string>

namespace Program
{
    struct CombinationParameters final // Parameters for the
    {                                  // combinations generator
        std::size_t size { };
        std::string source { };
    };
    
    
    /*******
     * QUICK WARNING
     * This code isn't maximally optimised.
     * If you need something fast, you may wanna change 
     * a few things. I was too lazy and
     * went with a quick-and-dirty solution.
     *******/
    
    
    class Impl final
    {
    public:
        using Result_t = std::vector<std::string>;
        
        Impl() = default;
        Impl(CombinationParameters);
        
        auto SetParameters(CombinationParameters) -> void;
        auto GetParameters() const -> CombinationParameters;
        
        auto Result() -> Result_t;
        
    private:
        using ConstStringIter = std::string::const_iterator;
        using Iterators_t = std::vector<ConstStringIter>;
        using IteratorsIterator_t = Iterators_t::iterator;
        
        auto Prepare() const -> void;
        auto Calculate() const -> void;
        auto NextStep(const IteratorsIterator_t&) const -> void;
        auto CurrentString() const -> std::string;
        auto Done() const noexcept -> bool;
        auto Last(const ConstStringIter&) const noexcept -> bool;
        auto NoteCurrentString() const -> void;
        
        CombinationParameters m_cp { };
        mutable Iterators_t m_iterators { };
        mutable Result_t m_result { };
        mutable bool m_calculated { false };
    };
}

