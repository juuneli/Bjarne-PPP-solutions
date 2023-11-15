// Author: github.com/juuneli

// Write a program that plays the game “Rock, Paper, Scissors.” If you are not
// familiar with the game do some research (e.g., on the web using Google).
// Research is a common task for programmers. Use a switch-statement to solve
// this exercise. Also, the machine should give random answers (i.e., select the
// next rock, paper, or scissors randomly). Real randomness is too hard to
// provide just now, so just build a vector with a sequence of values to be used
// as “the next value.” If you build the vector into the program, it will always
// play the same game, so maybe you should let the user enter some values. Try
// variations to make it less easy for the user to guess which move the machine
// will make next.

#include <iostream>
#include <cstring>
#include <random>

enum class Symbol {
    Rock,
    Paper,
    Scissors,
};

static constexpr const char *symbol_strings[] = {"Rock", "Paper", "Scissors"};

constexpr const char *to_string(Symbol s)
{
    return symbol_strings[static_cast<int>(s)];
}

Symbol get_input()
{
    bool valid_input = false;
    char input;

    while (!valid_input) {
        std::cout << "(R)ock, (P)aper, (S)cissors, shoot! ";
        std::cin >> input;

        if (!std::isalpha(input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid Symbol (r/p/s) or (R/P/S)\n";
        }

        switch (std::toupper(input)) {
        case 'R': return Symbol::Rock;
        case 'P': return Symbol::Paper;
        case 'S': return Symbol::Scissors;
        default:
            std::cout << "Please enter a valid Symbol (r/p/s) or (R/P/S)\n";
        }
    }

    return Symbol{};  // just to suppress clang-tidy warning
}

Symbol generate_random_symbol()
{
    static std::random_device rd;
    static std::mt19937 mt{rd()};

    int result = std::uniform_int_distribution<int>{0, 2}(mt);
    return static_cast<Symbol>(result);
}

bool replay_choice()
{
    std::cout << "Keep playing? (Y): ";
    char choice;
    std::cin >> choice;

    switch (std::toupper(choice)) {
    case 'Y': return true;
    default: return false;
    }
}

enum class Result {
    Win,
    Lose,
    Draw
};

constexpr Result game_result(Symbol user_symbol, Symbol ai_symbol)
{
    if (user_symbol == ai_symbol) {
        return Result::Draw;
    }

    // handle edge cases here:
    if (user_symbol == Symbol::Rock && ai_symbol == Symbol::Scissors) {
        return Result::Win;
    }

    if (user_symbol == Symbol::Scissors && ai_symbol == Symbol::Rock) {
        return Result::Lose;
    }

    if (user_symbol > ai_symbol) {
        return Result::Win;
    }

    if (user_symbol < ai_symbol) {
        return Result::Lose;
    }

    return Result{};
}

void print_result(Result result)
{
    std::cout << "You ";
    switch (result) {
    case Result::Win: std::cout << "won!"; break;
    case Result::Lose: std::cout << "lost!"; break;
    case Result::Draw: std::cout << "drew!"; break;
    default: std::cout << "?!"; break;
    }

    std::cout << '\n';
}

int main()
{
    bool keep_playing = false;

    do {
        const Symbol user_symbol = get_input();

        const Symbol ai_symbol = generate_random_symbol();

        std::cout << "U: " << to_string(user_symbol) << '\n'
                  << "AI: " << to_string(ai_symbol) << '\n';

        print_result(game_result(user_symbol, ai_symbol));

        keep_playing = replay_choice();
    } while (keep_playing);
}

void test_rps()
{
    using enum Symbol;

    static_assert(game_result(Rock, Scissors) == Result::Win);
    static_assert(game_result(Rock, Paper) == Result::Lose);
    static_assert(game_result(Rock, Rock) == Result::Draw);
    static_assert(game_result(Paper, Rock) == Result::Win);
    static_assert(game_result(Paper, Scissors) == Result::Lose);
    static_assert(game_result(Paper, Paper) == Result::Draw);
    static_assert(game_result(Scissors, Paper) == Result::Win);
    static_assert(game_result(Scissors, Rock) == Result::Lose);
    static_assert(game_result(Scissors, Scissors) == Result::Draw);
}
