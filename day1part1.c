#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *filePointer;

    filePointer = fopen("input.txt", "r");

    if (filePointer == NULL)
    {
        printf("Unable to open the file.\n");
        return 1;
    }
    int sum = 0;
    char buffer[200];
    char numbers[3];
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
    {
        numbers[0] = '0';
        numbers[1] = '0';
        numbers[2] = '\0';
        int flag = 0;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (isdigit(buffer[i]))
            {
                if (flag)
                {
                    numbers[1] = buffer[i];
                }
                else
                {
                    numbers[0] = buffer[i];
                    numbers[1] = buffer[i];
                    flag = 1;
                }
            }
        }
        int temp = atoi(numbers);
        sum += temp;
    }
    printf("%d \n", sum);
    fclose(filePointer);

    return 0;
}
