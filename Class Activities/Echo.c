#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 1000
#define RAISED 1
#define LOWERED 0
#define error(code, message) do{fprintf(stderr, "%s\n", message); return code;} while (0);
int number(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}
int main(int argc, char *argv[])
{
    int lowercase = LOWERED;
    int scientific = LOWERED;
    if (argc > 3)
        error(1, "echo: Fatal error! Too many arguments passed! Usage: echo [-l] [-e]\n");
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            error(2, "echo: Fatal error! Too many arguments passed! Usage:echo [-l] [-e]\n");
        int j = 1;
        while (argv[i][j])
        {
            if (argv[i][j] == 'l')
                lowercase = RAISED;
            else if (argv[i][j] == 'e')
                scientific = RAISED;
            else
                error(3, "echo: Fatal error! Too many arguments passed! Usage: echo [-l] [-e]\n");
            j++;
        }
    }
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, stdin))
    {
        if (scientific)
        {
            char *copy = malloc(MAX_LEN);
            char *temp = copy;
            char *token = strtok(line, " ");
            while (token)
            {
                if (number(token))
                {
                    sprintf(temp, "%10.2e ", 0.0 + atof(token));
                    temp += 11;
                }
                else
                {
                    sprintf(temp, "%s ", token);
                    temp += strlen(token) + 1;
                }
                token = strtok(NULL, " ");
            }
            strcpy(line, copy);
        }
        if (lowercase)
        {
            for (int i = 0; i < strlen(line); i++)
                line[i] = tolower(line[i]);
        }
        printf("%s", line);
    }
}