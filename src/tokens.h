// typedef struct {
//   char token;
//   void (* command)();
// } Token;

char valid_tokens[] = { '>', '<', '+', '-', '.', ',', '[', ']' };

char *get_tokens(char *file);

void run_tokens(char *tokens);
