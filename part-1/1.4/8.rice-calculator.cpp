// Author: github.com/juuneli

// There is an old story that the emperor wanted to thank the inventor of the
// game of chess and asked the inventor to name his reward. The inventor asked
// for one grain of rice for the first square, 2 for the second, 4 for the
// third, and so on, doubling for each of the 64 squares. That may sound modest,
// but there wasn’t that much rice in the empire! Write a program to calculate
// how many squares are required to give the inventor at least 1000 grains of
// rice, at least 1,000,000 grains, and at least 1,000,000,000 grains. You’ll
// need a loop, of course, and probably an int to keep track of which square you
// are at, an int to keep the number of grains on the current square, and an int
// to keep track of the grains on all previous squares. We suggest that you
// write out the value of all your variables for each iteration of the loop so
// that you can see what’s going on.

#include <iostream>

int calculate_squares_for(int no_of_rice)
{
    std::cout << "calculate_squares_for(" << no_of_rice << ")\n";
    for (int square = 1, total_rice = 1; square <= 64; ++square) {
        std::cout << "square: " << square << ", total_rice: " << total_rice
                  << '\n';
        if (total_rice >= no_of_rice) {
            std::cout << '\n';
            return square;
        }
        total_rice *= 2;
    }
    return 0;
}

int main()
{
    int sq_thousand_grains = calculate_squares_for(1000);
    int sq_million_grains = calculate_squares_for(1000000);
    int sq_billion_grains = calculate_squares_for(1000000000);

    std::cout << "the squares required:\n";

    std::cout << "for at least a thousand grains: " << sq_thousand_grains
              << '\n';
    std::cout << "for at least a million grains: " << sq_million_grains << '\n';
    std::cout << "for at least a billion grains: " << sq_billion_grains << '\n';

    return 0;
}
