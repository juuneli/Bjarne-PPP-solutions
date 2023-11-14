// Do exercise 6, but with three string values. So, if the user enters the
// values Steinbeck, Hemingway, Fitzgerald, the output should be Fitzgerald,
// Hemingway, Steinbeck.

// Author: github.com/juuneli

#include <iostream>
#include <string>

int main()
{
    std::string str1;
    std::string str2;
    std::string str3;

    std::cout << "enter three strings: ";
    std::cin >> str1 >> str2 >> str3;

    while (!(str1 <= str2 && str2 <= str3)) {
        if (str1 > str2) {
            std::swap(str1, str2);
        }
        if (str2 > str3) {
            std::swap(str2, str3);
        }
    }

    std::cout << str1 << ',' << str2 << ',' << str3 << '\n';
    return 0;
}
