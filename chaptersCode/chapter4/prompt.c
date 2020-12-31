#include <stdio.h>
#include <stdlib.h>

/* If we are compilling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

/* Declare a buffer for user input of size 2048 */
static char buffer[2048];

/* Fake readline function */
char *readline(char *prompt)
{
    fputs(promt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char *unused)
{
}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
// #include <editline/history.h>
#endif

int main(int argc, char **argv)
{

    /* Print Version and Exit Information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit \n");

    /* In a never ending loop */
    while (1)
    {

        /* Output for our prompt */
        // fputs("lispy> ", stdout);
        char *input = readline("lispy> ");

        /* Add input to history */
        add_history(input);

        /* Read a line of user input of maximum size 2048 */
        // fgets(input, 2048, stdin);

        /* Echo input back to user */
        printf("No you're a %s \n", input);

        /* Free retrieved input */
        free(input);
    }

    return 0;
}