#include "combinator.h"
#include "read_parameter.h"
#include <iostream>

int main()
{
    using namespace Program;
    
    auto combinationParameters = ReadCombinationParameters(std::cin);
    RemoveMultiples(combinationParameters.source);
    
    std::cout << "\n\n";
    
    auto comb = Combinator { combinationParameters };
    
    std::cout << comb.Result() << std::endl;
    
    std::cin.get();
}
