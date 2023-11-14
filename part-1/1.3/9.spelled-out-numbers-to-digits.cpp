// Write a program that converts spelled-out numbers such as “zero” and “two”
// into digits, such as 0 and 2. When the user inputs a number, the program
// should print out the corresponding digit. Do it for the values 0, 1, 2, 3,
// and 4 and write out not a number I know if the user enters something that
// doesn’t correspond, such as stupid computer!.

// Author: github.com/juuneli

#include <iostream>
#include <string>
#include <string_view>

static constexpr std::string_view number_strs[] = {"zero",
                                                   "one",
                                                   "two",
                                                   "three",
                                                   "four",
                                                   "five",
                                                   "six",
                                                   "seven",
                                                   "eight",
                                                   "nine"};

int main()
{
    std::cout << "enter a spelled out number or a numeric value: ";
    std::string input;
    std::cin >> input;

    if (std::isalpha(input.front())) {
        for (int num = 0; const auto num_str : number_strs) {
            if (input == num_str) {
                std::cout << num_str << " = " << num << '\n';
                return 0;
            }
            num++;
        }

        std::cerr << "not a number I know" << std::endl;
        return 1;
    }

    for (const char ch : input) {
        if (std::isdigit(ch)) {
            std::cout << ch << " = "
                      << number_strs[static_cast<std::size_t>(ch - '0')]
                      << ", ";
        }
    }
    std::cout << '\n';

    return 0;
}
