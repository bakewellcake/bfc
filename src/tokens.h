struct TokenBuf {
  char *token_ptr;
  char **tokens;
};

struct InputBuf {
  char *input_ptr;
  char **input;
};

char *get_tokens(char *file);

void run_tokens(struct TokenBuf *t_buf, struct InputBuf *i_buf);
