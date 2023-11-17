// Author: github.com/juuneli

// Create a program to find all the prime numbers between 1 and 100. There is a
// classic method or doing this, called the “Sieve of Eratosthenes.” If you
// don’t know that method, get on the web and look it up. Write your program
// using this method.

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

std::vector<bool> primes_to_n(std::size_t n)
{
    std::vector<bool> primes(n, true);  // 'max' sized vector of bools

    for (std::size_t i = 2; i < std::sqrt(n); ++i) {
        if (primes[i] == true) {
            for (std::size_t j = i * i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

int main(int argc, char *argv[])
{
    std::size_t max;
    if (argc == 2) {
        // no checking types and stuff as this is educational
        max = std::strtoull(argv[1], nullptr, 10);
    }
    else {
        std::cout
            << "enter the number upto which you'd like to generate prime numbers: ";
        std::cin >> max;
    }

    const auto primes = primes_to_n(max);

    std::cout << "primes upto " << max << ":\n";

    for (std::size_t i = 2; i < max; ++i) {
        if (primes[i] == true) {
            std::cout << i << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}
