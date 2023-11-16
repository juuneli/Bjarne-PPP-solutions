// Author: github.com/juuneli

// Create a program to find all the prime numbers between 1 and 100. One way to
// do this is to write a function that will check if a number is prime (num.e.,
// see if the number can be divided by a prime number smaller than itself) using
// a vector of primes in order (so that if the vector is called primes,
// primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop that goes
// from 1 to 100, checks each number to see if it is a prime, and stores each
// prime found in a vector. Write another loop that lists the primes you found.
// You might check your result by comparing your vector of prime numbers with
// primes. Consider 2 the first prime. Modify the program described in the
// previous exercise to take an input value max and then find all prime numbers
// from 1 to max.

#include <vector>
#include <iostream>
#include <cstddef>

std::vector<std::size_t> primes_to_n(std::size_t n)
{
    std::vector<std::size_t> primes{2};

    for (std::size_t num = 3; num < n; ++num) {
        bool is_prime = true;
        for (const auto prime : primes) {
            if (num % prime == 0) {
                is_prime = false;
            }
        }

        if (is_prime) {
            primes.push_back(num);
        }
    }

    return primes;
}

int main()
{
    std::cout
        << "please enter the number upto which you want to find prime numbers: ";
    std::size_t max;
    std::cin >> max;

    std::cout << "primes to " << max << ":\n";
    for (const auto prime : primes_to_n(max)) {
        std::cout << prime << ' ';
    }

    std::cout << '\n';
}
