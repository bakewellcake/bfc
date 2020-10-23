typedef struct {
  char *buf_ptr;
  char **buf_data;
} Buf;

char *get_tokens(char *file);

void run_tokens(Buf *t_buf, Buf *i_buf);
