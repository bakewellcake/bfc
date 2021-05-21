#include "tokens.h"
#include "cmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char valid_tokens[] = { '>', '<', '+', '-', '.', ',', '[', ']' };

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

int run_token(Buf *t_buf, Buf *i_buf) {
  switch (*t_buf->buf_ptr) {
  case '>':
    next();
    break;
  case '<':
    prev();
    break;
  case '+':
    add();
    break;
  case '-':
    sub();
    break;
  case '.':
    out();
    break;
  case ',':
    in(&i_buf->buf_ptr, **i_buf->buf_data + strlen(*i_buf->buf_data));
    break;
  case '[':
    loop_begin(&t_buf->buf_ptr);
    return 0;
  case ']':
    loop_end(&t_buf->buf_ptr);
    return 0;
  }

  return 1;
}

void run_tokens(Buf *t_buf, Buf *i_buf) {
  while (t_buf->buf_ptr < *t_buf->buf_data + strlen(*t_buf->buf_data)) {
    if (run_token(t_buf, i_buf)) {
      t_buf->buf_ptr++;
    }
  }
}
