#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

#include "PmergeMe.hpp"

static long val;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char* _argv[], int _argc) : argv(_argv), argc(_argc)
{
    PmergeHandler(argv, argc);

    printContainer(this->veq_sequence, "Before");
   

    sortVector();
    sortDequeu();


    printContainer(this->veq_sequence, "After");
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
    *this = copy;
}

PmergeMe::~PmergeMe(void){}

// std::string PmergeMe::getExp() const {return this->exp;}
// double PmergeMe::getResult() const {return this->resultOperation;}
// void PmergeMe::setExp(std::string _exp){this->exp = _exp;}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this == &rhs)
        return *this;

    // this->setExp(rhs.getExp());
    return *this;
}

template<typename T>
void PmergeMe::printContainer(const T& container, std::string prefixMsg) 
{
    typename T::const_iterator it;
    std::cout << std::setw(8) << prefixMsg + ": ";
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

bool PmergeMe::is_integer(const std::string& str) 
{
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]) && !(i == 0 && (str[i] == '+' || str[i] == '-'))) {
            return false;
        }
    }
    char* endptr;
    val = std::strtol(str.c_str(), &endptr, 10);
    return (*endptr == '\0' && val >= 0);
}

void PmergeMe::PmergeHandler(char* argv[], int argc)
{

// std::vector<long> sequence;
    for (int i = 1; i < argc; i++) 
    {
        if (!is_integer(argv[i])) {
            std::cerr << "Error: Input contains non-numeric/negative elements." << std::endl;
            return ;
        }
        this->veq_sequence.push_back(val);
    }

// std::cout << "Before: ";

//     std::vector<long>::const_iterator it;
//     for (it = this->veq_sequence.begin(); it != this->veq_sequence.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// printContainer(this->veq_sequence, "Before");

// std::deque<long> deq;
std::copy(this->veq_sequence.begin(), this->veq_sequence.end(), std::back_inserter(this->deq_sequence));

// std::cout << "output deq" << std::endl;

// std::deque<long>::const_iterator itt;
// for (itt = deq_sequence.begin(); itt != deq_sequence.end(); ++itt)
//         std::cout << *itt << " ";
// std::cout << std::endl;

}

// void PmergeMe::mergeSort(std::vector<long>& array) 
// {
//     if (array.size() > 1) 
//     {
//         std::vector<long> left(array.begin(), array.begin() + array.size() / 2);
//         std::vector<long> right(array.begin() + array.size() / 2, array.end());
//         mergeSort(left);
//         mergeSort(right);
//         std::merge(left.begin(), left.end(), right.begin(), right.end(), array.begin());
//     }
// }



// long main() {
//     std::vector<std::string> input = {"123", "456", "abc", "789"};
//     for (long i = 0; i < input.size(); i++) {
//         if (!is_integer(input[i])) {
//             std::cout << "Error: Input contains non-numeric elements." << std::endl;
//             return 1;
//         }
//     }
//     return 0;
// }

// void PmergeMe::insertionSort(std::vector<long>& array) 
// {
//     for (size_t i = 1; i < array.size(); i++) 
//     {
//         long temp = array[i];
//         long j = i - 1;
//         while (j >= 0 && array[j] > temp) 
//         {
//             array[j + 1] = array[j];
//             j--;
//         }
//         array[j + 1] = temp;
//     }
// }

template <typename T>
void PmergeMe::insertionSort(T& container) 
{
    for (size_t i = 1; i < container.size(); i++) 
    {
        long temp = container[i];
        long j = i - 1;
        while (j >= 0 && container[j] > temp) 
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = temp;
    }
}

/* 
void PmergeMe::mergeInsertionSort(std::vector<long>& array) 
{
    clock_t start = clock();
    if (array.size() <= THRESHOLD)
        insertionSort(array);
    else 
    {
        std::vector<long> left(array.begin(), array.begin() + array.size() / 2);
        std::vector<long> right(array.begin() + array.size() / 2, array.end());
        mergeInsertionSort(left);
        mergeInsertionSort(right);
        merge(left.begin(), left.end(), right.begin(), right.end(), array.begin());
    }

    clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC / array.size();
    std::cout << "Time to process a range of " << array.size() << " elements with std::sort: "
              << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
}
*/

template <typename T>
void PmergeMe::mergeInsertionSort(T& container) 
{
    if (container.size() <= THRESHOLD)
        insertionSort(container);
    else 
    {
        T left(container.begin(), container.begin() + container.size() / 2);
        T right(container.begin() + container.size() / 2, container.end());
        mergeInsertionSort(left);
        mergeInsertionSort(right);
        merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
    }
}

void PmergeMe::sortVector()
{
clock_t start = clock();

 mergeInsertionSort(this->veq_sequence);

clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC / this->veq_sequence.size();
    std::cout << "Time to process a range of " << this->veq_sequence.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
}

void PmergeMe::sortDequeu()
{
clock_t start = clock();

 mergeInsertionSort(this->deq_sequence);

clock_t end = clock();

    double elapsed_time = 1000000 * (double)(end - start) / CLOCKS_PER_SEC / deq_sequence.size();
    std::cout << "Time to process a range of " << this->deq_sequence.size() << " elements with std::deque : "
              << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
}