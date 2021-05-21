#include "cmd.h"
#include "buffer.h"
#include "tokens.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void jump(char **token_ptr, int mod) {
  int count = 1;
  char *order;

  if (mod == 1) {
    order = "[]";
  } else {
    order = "][";
  }

  while (count) {
    (*token_ptr) += mod;

    if (!**token_ptr) {
      break;
    }

    if (**token_ptr == order[0]) {
      count++;
    } else if (**token_ptr == order[1]) {
      count--;
    }
  }
}

void next() {
  ++data_ptr;

  if (data_ptr >= mem_buf + BUFFER_LENGTH) {
    printf("Index out of range positively: %d\n", *data_ptr);

    exit(1);
  }
}

void prev() {
  --data_ptr;

  if (data_ptr < mem_buf) {
    printf("Index out of range negatively: %d\n", *data_ptr);

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
  --*data_ptr;
}

void out() {
  putchar(*data_ptr);
}

void in(char **input_ptr, int len) {
  *data_ptr = **input_ptr;

  if (*data_ptr < len) {
    (*input_ptr)++;
  } else {
    **input_ptr = -1;
  }
}

void loop_begin(char **token_ptr) {
  if (*data_ptr) {
    (*token_ptr)++;
  } else {
    jump(token_ptr, 1);
  }
}

void loop_end(char **token_ptr) {
  if (*data_ptr) {
    jump(token_ptr, -1);
  } else {
    (*token_ptr)++;
  }
}
