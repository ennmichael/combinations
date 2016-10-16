#include "combinator.h"
#include <utility>

namespace Program
{
    Combinator::Combinator(CombinationParameters cp)
        : m_impl { cp }
    {
    }
    
    auto Combinator::SetParameters(CombinationParameters cp) -> void
    {
        m_impl.SetParameters(std::move(cp));
    }
    
    auto Combinator::GetParameters() const -> CombinationParameters
    {
        return m_impl.GetParameters();
    }
    
    auto Combinator::Result() const -> Impl::Result_t
    {
        return m_impl.Result();
    }
}
