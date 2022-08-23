# random
A command line tool for creating random numbers

It uses c++ [std::random_device](https://en.cppreference.com/w/cpp/numeric/random/random_device)
 and c++ [std::uniform_int_distribution](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)

By default it gives a random number from 1 to 10

```
Usage: random [options] 

Optional arguments:
-h --help      	shows help message and exits [default: false]
-v --version   	prints version information and exits [default: false]
-c --count     	Number of random numbers
-a --start     	start random from
-z --end       	largest random number
-s --separator 	The separator to use between numbers
```

example:

```
$ ./random -c 3 -a 4 
8 7 4
```

# Install

``` sh
mkdir build
cd build
cmake ..
make
sudo make install
```
