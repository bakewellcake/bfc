#define BUFFER_LENGTH 30000

typedef unsigned char buffer_t;

extern buffer_t mem_buf[BUFFER_LENGTH];

extern buffer_t *data_ptr;

extern buffer_t *max_ptr;

// This is a rubbish solution to sharing the Buf type
// between headers. I should definitely find a better
// way of doing this.
void *create_buffer(char *str);
