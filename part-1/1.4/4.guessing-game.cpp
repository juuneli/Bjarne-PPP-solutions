// Author: github.com/juuneli

// Write a program to play a numbers guessing game. The user thinks of a number
// between 1 and 100 and your program asks questions to figure out what the
// number is (e.g., “Is the number you are thinking of less than 50?”). Your
// program should be able to identify the number after asking no more than seven
// questions. Hint: Use the < and <= operators and the if-else construct.

#include <iostream>

int main()
{
    constexpr int max_tries = 7;

    int min = 1;
    int max = 100;

    for (int tries = 0; tries < max_tries; ++tries) {
        int mid_value = (min + max) / 2;
        std::cout << "Is the number you are thinking of less than " << mid_value
                  << " (y/n)? ";
        char input;
        std::cin >> input;

        switch (input) {
        case 'y':
        case 'Y': max = mid_value; break;
        case 'n':
        case 'N': min = mid_value; break;
        default:
            std::cerr << "error: bad input (enter only y/n)" << std::endl;
            return -1;
        }

        if (max == min || max - min == 1) {
            std::cout << "The number you are thinking of is: ";
            if (max == min) {
                std::cout << max << '\n';
            }
            else {
                std::cout << max - 1 << '\n';
            }
            return 0;
        }
    }
}
