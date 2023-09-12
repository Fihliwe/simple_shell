#include <stdio.h>
#include <string.h>

int main() {
    const char *variable_name = "PATH";
    char *value; 
    value = _getenv(variable_name);

    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("%s not found in the environment.\n", variable_name);
    }

    return 0;
}
