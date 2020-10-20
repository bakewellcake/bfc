struct TokenBuf {
  char *token_ptr;
  char **tokens;
};

char *get_tokens(char *file);

void run_tokens(struct TokenBuf *t_buf);
