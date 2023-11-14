// Exercise 6:
// Write a program that prompts the user to enter three integer values, and then
// outputs the values in numerical sequence separated by commas. So, if the user
// enters the values 10 4 6, the output should be 4, 6, 10. If two values are
// the same, they should just be ordered together. So, the input 4 5 4 should
// give 4, 4, 5.

// Author: github.com/juuneli

#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x;
    int y;
    int z;

    std::cout << "enter three integer values: ";
    std::cin >> x >> y >> z;

    while (!(x <= y && y <= z)) {
        if (x > y) {
            swap(x, y);
        }
        if (y > z) {
            swap(y, z);
        }
    }

    std::cout << x << ',' << y << ',' << z << '\n';
    return 0;
}
