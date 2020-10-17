#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 30000

char valid_tokens[] = { '>', '<', '+', '-', '.', ',', '[', ']' };
char buffer[BUFFER_LENGTH] = { 0 };

// int index = 0;

char *read_file (char *file_path) {
  FILE *file = fopen(file_path, "r");

  fseek(file, 0, SEEK_END);

  long bytes = ftell(file);

  fseek(file, 0, SEEK_SET);

  char *contents = (char *) calloc(bytes, sizeof(char));

  fread(contents, sizeof(char), bytes, file);
  fclose(file);

  return contents;
}

char *get_tokens (char *file) {
  int file_length = strlen(file);
  int token_count = 0;
  char *tokens = (char *) calloc(file_length, sizeof(char));

  for (int i = 0; i < file_length; i++) {
    char file_char = file[i];
    char *token = strchr(valid_tokens, file_char);

    if (token) {
      tokens[token_count++] = file_char;
    }
  }

  return tokens;
}

int main (int argc, char **argv)
{
  char *file_path = argv[1];

  if (file_path == NULL) {
    printf("Missing file path parameter\n");

    return 1;
  }

  char *file = read_file(file_path);
  char *tokens = get_tokens(file);

  printf("%s\n", tokens);

  free(file);
  free(tokens);

  return 0;
}
