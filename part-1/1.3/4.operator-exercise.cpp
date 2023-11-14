// Exercise 4:
// Write a program that prompts the user to enter two integer values. Store
// these values in int variables named val1 and val2. Write your program to
// determine the smaller, larger, sum, difference, product, and ratio of these
// values and report them to the user.

// Author: github.com/juuneli

#include <iostream>

int main()
{
    int val1;
    int val2;

    std::cout << "enter two integer values: ";
    std::cin >> val1 >> val2;

    bool equal = val1 == val2;

    int smaller = val1 < val2 ? val1 : val2;
    int larger = val1 > val2 ? val1 : val2;

    int sum = val1 + val2;
    int difference = larger - smaller;
    int product = val1 * val2;
    auto ratio = val1 / static_cast<double>(val2);

    std::cout << "val1: " << val1 << ", val2: " << val2 << "\nsum: " << sum
              << ", difference: " << difference << ", product: " << product
              << ", ratio: " << ratio << '\n';
    if (equal) {
        std::cout << val1 << " == " << val2 << '\n';
        return 0;
    }

    std::cout << "smaller: " << smaller << ", larger: " << larger << '\n';
    return 0;
}
