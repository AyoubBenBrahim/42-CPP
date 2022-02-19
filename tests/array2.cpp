#include <algorithm> // for std::sort
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> myArray = { 7, 3, 1, 9, 5 };
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
//  std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards


	for (int i = 0;i < myArray.size(); i++)
		std::cout << myArray[i] << " ";

    std::cout << '\n';

    return 0;
}
