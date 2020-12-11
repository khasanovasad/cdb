#include "common.h"

void check_alloc(void* ptr, char* message) {
    if (ptr == NULL) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}
