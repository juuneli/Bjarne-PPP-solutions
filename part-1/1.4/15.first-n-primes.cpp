// Author: github.com/juuneli

// Write a program that takes an input value n and then finds the first n
// primes.

#include <iostream>
#include <vector>
#include <cstdlib>

bool is_prime(std::size_t n)
{
    for (std::size_t i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    std::size_t n;

    if (argc == 2) {
        n = std::strtoull(argv[1], nullptr, 10);
    }
    else if (argc == 1) {
        std::cout << "enter how many primes you want to generate: ";
        std::cin >> n;
    }
    else {
        std::cerr << "usage: " << argv[0] << " <number>\n";
        return -1;
    }

    std::vector<std::size_t> n_primes;
    n_primes.reserve(n);

    std::size_t count = 0;
    for (std::size_t i = 2; count < n; ++i) {
        if (is_prime(i)) {
            n_primes.push_back(i);
            ++count;
        }
    }

    for (const auto prime : n_primes) {
        std::cout << prime << ' ';
    }

    std::cout << '\n';

    return 0;
}
