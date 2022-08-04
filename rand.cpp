#include "argparse.hpp"
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */

#include <cctype>
#include <random>


std::string parse(const std::string& s)
{
  std::stringstream  ss{""};

  for(size_t i = 0; i < s.length(); i++)
  {
    if (s.at(i) == '\\')
    {
      switch(s.at(i + 1))
      {
        case 'n':  ss << "\n"; i++; break;
        case 'r':  ss << "\r"; i++; break;
        case '"':  ss << "\""; i++; break;
        case 't':  ss << "\t"; i++; break;
        default:   ss << "\\";      break;
      }
    }
    else
    {
      ss << s.at(i);
    }
  }

  return ss.str();
}

int main(int argc, char *argv[]) {

  argparse::ArgumentParser program("random");
  int i = 1;
  int start = 0;
  int stop = 10;
  std::string separator = " ";

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

  program.add_argument("-s", "--separator")
    .help("The separator to use between numbers")
    .action(
      [=, &separator](const std::string &value) {
        separator = parse(value);
      });

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program << std::endl;
    std::exit(1);
  }

  std::random_device rd; // uses RDRND or /dev/urandom
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(start, stop);
  for (int n = 0; n < i; ++n)
    if(n + 1 == i) std::cout << dist(rd);
    else std::cout << dist(rd) << separator;
}
