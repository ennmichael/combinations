#include "impl.h"
#include <algorithm>

namespace Program
{
    Impl::Impl(CombinationParameters cp)
    {
        SetParameters(cp);
    }
    
    auto Impl::SetParameters(CombinationParameters cp) -> void
    {
        m_cp = std::move(cp);
        m_calculated = false;
    }
    
    auto Impl::GetParameters() const -> CombinationParameters
    {
        return m_cp;
    }
    
    auto Impl::Result() -> Result_t
    {
        if (!m_calculated)
        {
            m_calculated = true;
            
            Prepare();
            Calculate();
        }
        
        return m_result;
    }
    
    auto Impl::Prepare() const -> void
    {
        m_result.clear();
        m_iterators.clear();
        m_iterators.resize(m_cp.size);
        
        std::fill(m_iterators.begin(), m_iterators.end(), 
                  m_cp.source.cbegin());
    }
    
    auto Impl::Calculate() const -> void
    {
        do
        {
            NoteCurrentString();
            NextStep(m_iterators.begin());
        } while (!Done());
    }
    
    auto Impl::NextStep(const IteratorsIterator_t& pos) const 
        -> void
    {
        if (Last(*pos))
        {
            *pos = m_cp.source.cbegin();
            NextStep(pos + 1);
            
            return;
        }
        
        ++ *pos;
    }
    
    auto Impl::CurrentString() const -> std::string
    {
        auto result = std::string { };
        
        std::for_each(m_iterators.cbegin(),
                      m_iterators.cend(),
                      [&result](const auto& letter)
                      {
                          result.push_back(*letter);
                      });
        
        return result;
    }
    
    auto Impl::Done() const noexcept -> bool
    {
        return 
            Last(m_iterators.front()) and Last(m_iterators.back());
        // This is guaranteed to be true when the algorithm is done,
        // because the algorithm gets executed left to right
    }
    
    auto Impl::Last(const ConstStringIter& iter) const noexcept 
        -> bool
    {
        return iter == m_cp.source.cend();
    }
    
    auto Impl::NoteCurrentString() const -> void
    {
        if (std::find_if(m_iterators.cbegin(), m_iterators.cend(),
            [this](const auto& elem) noexcept
            {
                return elem == m_cp.source.cend();
            }) == m_iterators.cend())
        {
            m_result.emplace_back(CurrentString());
        } 
    }
}
