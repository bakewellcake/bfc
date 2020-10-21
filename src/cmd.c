#include "cmd.h"
#include "buffer.h"
#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>

void next() {
  ++data_ptr;

  if (data_ptr >= mem_buf + BUFFER_LENGTH) {
    printf("Index out of range\n");

    exit(1);
  }
}

void prev() {
  --data_ptr;

  if (data_ptr < mem_buf) {
    printf("Index out of range\n");

    exit(1);
  }
}

void add() {
  ++*data_ptr;

  if (data_ptr > max_ptr) {
    max_ptr = data_ptr;
  }
}

void sub() {
  // @TODO: Should this support negative loop around?
  --*data_ptr;
}

void out() {
  printf("%c\n", (char) *data_ptr);
  // putchar(*data_ptr);
}

void in() {
}

void loop_begin() {
}

void loop_end() {
}
