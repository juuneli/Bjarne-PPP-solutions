// Exercise 2: Write a program in C++ that converts from miles to kilometers.
// Your program should have a reasonable prompt for the user to enter a number
// of miles. Hint: There are 1.609 kilometers to the mile.

// Author: github.com/juuneli

#include <ios>
#include <iostream>
#include <cstring>
#include <limits>

double miles_to_km(double miles)
{
    return 1.609 * miles;
}

int main(int argc, char *argv[])
{
    enum Error {
        TOO_MANY_ARGUMENTS = 1,
        INVALID_ARGUMENT,
    };

    if (argc > 2) {
        std::cerr << "usage: " << argv[0] << " <distance-in-miles>"
                  << std::endl;
        return Error::TOO_MANY_ARGUMENTS;
    }

    if (argc == 2) {
        std::string miles_str = argv[1];
        if (std::isalpha(miles_str.front())) {
            std::cerr << "usage: " << argv[0] << " <distance-in-miles>"
                      << std::endl;
            return Error::INVALID_ARGUMENT;
        }

        const auto miles = std::stod(miles_str);
        std::cout << miles << " miles = " << miles_to_km(miles) << " km\n";
        return 0;
    }

    double miles{};
    while (true) {
        std::cout << "please enter a number of miles: ";
        if (!(std::cin >> miles)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "invalid input: try entering numeric value"
                      << std::endl;
        }
        else {
            break;
        }
    }

    std::cout << miles << " miles = " << miles_to_km(miles) << " km\n";
    return 0;
}
