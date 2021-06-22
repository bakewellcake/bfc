# BrainFuck compiler (bfc)

A [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) compiler in C, just for some fun.

Accepts a single file argument, which can be of any type really, but I've opted for `.bf` in [examples](/eg).

## Installing

```sh
make
```

## Running

```sh
./bfc [FILE_NAME]
```

## Bugs

- Certain letter combinations don't output properly with the [rot](/eg/rot.bf) example.
