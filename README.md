# Cracking the coding interview as a CLI

This repo contains my solutions for the interview questions posed in the 6th edition of McDowell's _Cracking the Coding Interview_. The solutions come packed as a CLI creatively named `ctci`. 

## Installation
Download the source code via git, cd into the repo and
``` bash
mkdir build
cd build
cmake ..
make -j8
```
Alternatively you can install it to your path with `make install`.


## Usage
Currently, the available options are:
``` bash
A command line tool for running the algorithms from Cracking the Coding Interview 6th Edition
Usage: ctci [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit

Subcommands:
  urlify                      urlifies a string (1.3)
  unique-characters           checks whether a string has all unique chars (1.2)
```
