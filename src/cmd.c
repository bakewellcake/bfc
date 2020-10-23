#include "cmd.h"
#include "buffer.h"
#include "tokens.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int loop_count = 0;

void jump_forward(char **token_ptr) {
  int begin_count = 1;

  while (begin_count) {
    (*token_ptr)++;

    if (**token_ptr == '[') {
      begin_count++;

      continue;
    }

    if (**token_ptr == ']') {
      begin_count--;
    }
  }
}

void jump_backward(char **token_ptr) {
  int end_count = 1;

  while (end_count) {
    (*token_ptr)--;

    if (**token_ptr == ']') {
      end_count++;

      continue;
    }

    if (**token_ptr == '[') {
      end_count--;
    }
  }
}

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
  // printf("%c\n", (char) *data_ptr);
  putchar(*data_ptr);
}

void in() {
}

void loop_begin(char **token_ptr) {
  if (*data_ptr) {
    (*token_ptr)++;
  } else {
    jump_forward(token_ptr);
  }
}

void loop_end(char **token_ptr) {
  if (*data_ptr) {
    jump_backward(token_ptr);
  } else {
    (*token_ptr)++;
  }
}
