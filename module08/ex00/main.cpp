#include <vector>
#include <list>
#include <set>
#include <deque>

#include "easyfind.hpp"

int main(void)
{
    std::cout << "\n** Test Vector **\n" << std::endl;

    std::list<int>      intList;
    std::vector<int>    intVector;
    std::set<int>       intSet;
    std::deque<int>     intDeque;
    std::multiset<int>  intMultiset;


    for (int i = 0; i <= 10; i++)
        intVector.push_back(i);

    easyfind(intVector, 1);
    easyfind(intVector, 9);
    easyfind(intVector, 10000);

    std::cout << "\n** Test List **\n" << std::endl;

    for (int i = 0; i <= 10; i++)
        intList.push_back(i);

    easyfind(intList, 5);
    easyfind(intList, 7);
    easyfind(intList, 40000);

    std::cout << "\n** Test Set **\n" << std::endl;

    for (int i = 0; i <= 10; i++)
        intSet.insert(i);

    easyfind(intSet, 3);
    easyfind(intSet, 4);
    easyfind(intSet, 8000);

    std::cout << "\n** Test Multiset **\n" << std::endl;

    for (int i = 0; i <= 10; i++)
        intMultiset.insert(i);

    easyfind(intMultiset, 3);
    easyfind(intMultiset, 4);
    easyfind(intMultiset, 8000);

    std::cout << "\n** Test Deque **\n" << std::endl;

    for (int i = 0; i <= 10; i++)
        intDeque.push_back(i);

    easyfind(intDeque, 9);
    easyfind(intDeque, 4);
    easyfind(intDeque, 1000);

    return 0;
}