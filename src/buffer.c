#include "buffer.h"
#include "tokens.h"
#include <stdlib.h>
#include <string.h>

void *create_buffer(char *str) {
  Buf buf;

  buf.buf_data = (char **) calloc(strlen(str), sizeof(char *));

  memcpy(buf.buf_data, &str, strlen(str) + sizeof(char *));

  buf.buf_ptr = *buf.buf_data;

  void *v_buf = (void *) &buf;

  return v_buf;
}
