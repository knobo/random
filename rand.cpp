#include "argparse.hpp"
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#include <cctype>
#include <random>

int main(int argc, char *argv[]) {

  argparse::ArgumentParser program("random");
  int i = 1;
  int start = 0;
  int stop = 10;

  program.add_argument("-c", "--count")
      .help("Number of random numbers")
      .action([=, &i](const std::string &value) { i = std::stoi(value); });

  program.add_argument("-a", "--start")
      .help("start random from")
      .action(
          [=, &start](const std::string &value) { start = std::stoi(value); });

  program.add_argument("-z", "--end")
      .help("largest random number")
      .action(
          [=, &stop](const std::string &value) { stop = std::stoi(value); });

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program << std::endl;
    std::exit(1);
  }

  std::uniform_int_distribution<int> d(start, stop);
  std::random_device rd1; // uses RDRND or /dev/urandom
  for (int n = 0; n < i; ++n)
    std::cout << d(rd1) << std::endl;
}
