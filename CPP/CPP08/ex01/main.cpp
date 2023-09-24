#include "Span.hpp"

int main()
{
    {
        std::cout << "\033[36m---- Example given in the subject ----\033[0m" << std::endl;
        Span sp = Span(5);

        std::vector<int> elementsToAdd;
        for (int i = 1; i <= 5; ++i) 
        {
            elementsToAdd.push_back(i);
        }

        try 
        {
            sp.addRange(elementsToAdd.begin(), elementsToAdd.end());
            /*sp.addRange(1,10);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);*/
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return (0);
    }

    
}