#include "buffer.h"
#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

buffer_t mem_buf[BUFFER_LENGTH] = { 0 };
buffer_t *data_ptr = mem_buf;
buffer_t *max_ptr = 0;

char *read_file(char *file_path) {
  FILE *file = fopen(file_path, "r");

  fseek(file, 0, SEEK_END);

  long bytes = ftell(file);

  fseek(file, 0, SEEK_SET);

  char *contents = (char *) calloc(bytes, sizeof(char));

  fread(contents, sizeof(char), bytes, file);
  fclose(file);

  return contents;
}

int main(int argc, char **argv) {
  char *file_path = argv[1];

  if (file_path == NULL) {
    printf("Missing file path parameter\n");

    return 1;
  }

  printf("Input: ");

  size_t len = 0;
  int count = 0;
  char *file = read_file(file_path);
  char *tokens = get_tokens(file);
  char *input = fgetln(stdin, &len);

  Buf t_buf;
  Buf i_buf;

  t_buf.buf_data = (char **) calloc(strlen(tokens), sizeof(char));
  i_buf.buf_data = (char **) calloc(strlen(input), sizeof(char));

  memcpy(t_buf.buf_data, &tokens, strlen(tokens) + 1);
  memcpy(i_buf.buf_data, &input, strlen(input) + 1);

  t_buf.buf_ptr = *t_buf.buf_data;
  i_buf.buf_ptr = *i_buf.buf_data;

  run_tokens(&t_buf, &i_buf);

  free(file);
  free(input);

  printf("\nDiagnostics:\n");

  for (buffer_t *i = mem_buf; i <= max_ptr; i++) {
    printf("%d: %d\n", count++, (int) *i);
  }

  return 0;
}
