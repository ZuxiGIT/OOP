#include "error.h"

void error (const char* str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}