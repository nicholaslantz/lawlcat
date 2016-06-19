# LawlCat
## by Nicholas Lantz

A character-wise version of lolcat. It is not as fully featured as the original
(found [here](https://github.com/busyloop/lolcat)), but it does output pretty
colors! It doesn't even need the line to end, it will happily print out
characters before the newline character.

To show that it works, pipe the output into the movietype program provided. It
will print a single character at a time and wait a little bit to print the next
one. Pipe the output of lawlcat into movietype to see it in action

For example,
```
./lawlcat lawlcat.c | ./movietype
```

## Installation

Ensure gcc and bash are installed on your computer. Then, type ./build.sh and
this will build lawlcat.c and movietype.c.

Alternatively, just build the files manually. They do not require any
external libraries.
