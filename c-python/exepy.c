#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PYTHON "/usr/bin/python3"
#define SCRIPT "./test.py"

int
main(int argc, char *argv[])
{
    /* Reserve enough space for "python3", "script.py", argv[1..] copies
     * and a terminating NULL, 1 + 1 + (argc - 1) + 1 */
    int newargvsize = argc + 2;
    /* VLA could be used here as well. */
    char **newargv = malloc(newargvsize * sizeof(*newargv));
    char *newenv[] = { NULL };

    newargv[0] = PYTHON;
    newargv[1] = SCRIPT;
    /* execve requires a NULL terminated argv */
    newargv[newargvsize - 1] = NULL;
    /* Copy over argv[1..] */
    memcpy(&newargv[2], &argv[1], (argc - 1) * sizeof(*newargv));
    /* execve does not return on success */
    execve(PYTHON, newargv, newenv);
    perror("execve");
    exit(EXIT_FAILURE);
}
