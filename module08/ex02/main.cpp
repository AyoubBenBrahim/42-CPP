#include "mutantstack.hpp"
#include <list>
#include <iomanip>

int main()
{
    std::cout << "******* MutantStack<int> ********\n\n";
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "size = " << mstack.size() << std::endl;
        std::cout << "elem on top = " << mstack.top() << std::endl;

        std::cout << "pop element " << mstack.top() << "\n\n";
        mstack.pop();
        std::cout << "size = " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "\nOutput of begin / end itr: \n\n";
        while (it != ite)
        {
            std::cout << std::setw(4) << std::left << *it << " ==> ";
            *it = 4;
            std::cout << *it << std::endl;
            ++it;
        }

        while (!mstack.empty())
            mstack.pop();

        for (int i = 1; i < 8; i++)
            mstack.push(i);

        std::cout << "\nOutput of const begin / const end itr: \n\n";

        MutantStack<int>::const_iterator itrConstBgin = mstack.cbegin();
        MutantStack<int>::const_iterator itrConstEnd = mstack.cend();

        for (; itrConstBgin != itrConstEnd; ++itrConstBgin)
            std::cout << *itrConstBgin << std::endl;

        std::cout << "\nOutput of reverse begin / reverse end itr: \n\n";

        MutantStack<int>::reverse_iterator itrBgin = mstack.rbegin();
        MutantStack<int>::reverse_iterator itrEnd = mstack.rend();

        for (; itrBgin != itrEnd; ++itrBgin)
            std::cout << *itrBgin << std::endl;

        std::stack<int> s(mstack);
    }

    std::cout << "\n******* std::list<int> ********\n\n";

    {
        std::list<int> mylist;
        mylist.push_back(5);
        mylist.push_back(17);
        std::cout << "top = " << mylist.back() << std::endl;

        std::cout << "pop ";
        mylist.pop_back();
        std::cout << "\n";
        std::cout << "size = " << mylist.size() << std::endl;
        mylist.push_back(3);
        mylist.push_back(5);
        mylist.push_back(737);
        //[...]
        mylist.push_back(0);
        std::list<int>::iterator it = mylist.begin();
        std::list<int>::iterator ite = mylist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mylist);
    }

    return 0;
}