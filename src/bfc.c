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

Buf create_buffer(char *str) {
  Buf buf;

  buf.buf_data = (char **) calloc(strlen(str), sizeof(char *));

  memcpy(buf.buf_data, &str, strlen(str) + sizeof(char *));

  buf.buf_ptr = *buf.buf_data;

  return buf;
}

int main(int argc, char **argv) {
  char *file_path = argv[1];

  if (file_path == NULL) {
    printf("Missing file path parameter\n");

    return 1;
  }

  printf("Input: ");

  size_t len = 0;
  char *file = read_file(file_path);
  char *tokens = get_tokens(file);
  char *input;

  getline(&input, &len, stdin);

  input[strcspn(input, "\n")] = 0;

  Buf t_buf = create_buffer(tokens);
  Buf i_buf = create_buffer(input);

  run_tokens(&t_buf, &i_buf);

  free(file);
  free(input);

  printf("\nDiagnostics:\n[");

  for (buffer_t *i = mem_buf; i <= max_ptr; i++) {
    char *term;

    if (i == max_ptr) {
      term = "]\n";
    } else {
      term = ", ";
    }

    printf("%d%s", (int) *i, term);
  }

  return 0;
}
