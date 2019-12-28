#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void passgen(int size)
{
    char character = rand() % 127;

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        character = rand() % 127;
        if (character < 33 || character == '"') {
            character = character + 33;
        }
        printf("%c", character);
    }
    printf("\n");
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_atoi(const char *str)
{
    int size = my_strlen(str) - 1;
    int number = 0;
    int i = 1;

    while (size >= 0) {
        number = number + ((str[size] - 48) * i);
        i = i * 10;
        size--;
    }
    return (number);
}

int main (int ac, char **argv) {
    if (ac < 2) {
        printf("./passgen <password size>\n");
        return (84);
    } else {
        passgen(my_atoi(argv[1]));
        return (0);
    }
}