#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char valid_tokens[] = { '>', '<', '+', '-', '.', ',', '[', ']' };

char *get_tokens (char *file) {
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

void parse_tokens (char *tokens) {
  for (int i = 0; i < strlen(tokens); i++) {
    switch (tokens[i]) {
    case '>':
      // next();
      break;
    // case valid_tokens[1]:
    //   prev();
    //   break;
    // case valid_tokens[2]:
    //   add();
    //   break;
    // case valid_tokens[3]:
    //   sub();
    //   break;
    // case valid_tokens[4]:
    //   out();
    //   break;
    // case valid_tokens[5]:
    //   in();
    //   break;
    // case valid_tokens[6]:
    //   loop_begin();
    //   break;
    // case valid_tokens[7]:
    //   loop_end();
    //   break;
    }
  }
}
