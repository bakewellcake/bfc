#include "tokens.h"
#include "cmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_tokens(char *file) {
  int file_length = strlen(file);
  int token_count = 0;
  char *token_data = (char *) calloc(file_length, sizeof(char));

  for (int i = 0; i < file_length; i++) {
    char file_char = file[i];
    char *token = strchr(valid_tokens, file_char);

    if (token) {
      token_data[token_count++] = file_char;
    }
  }

  char *tokens = (char *) realloc(token_data, token_count + 1);

  return tokens;
}

void run_tokens(char *tokens) {
  for (int i = 0; i < strlen(tokens); i++) {
    char token = tokens[i];

    switch (token) {
    case '>':
      next(token);
      break;
    case '<':
      prev(token);
      break;
    case '+':
      add(token);
      break;
    case '-':
      sub(token);
      break;
    case '.':
      out(token);
      break;
    case ',':
      in(token);
    case '[':
      loop_begin(token);
      break;
    case ']':
      loop_end(token);
      break;
    }
  }
}
