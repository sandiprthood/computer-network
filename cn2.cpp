#include <stdio.h>

int main()
{
    char data[100], stuffed[200];
    int i, j = 0, count = 0;

    printf("Enter String: ");
    scanf("%s", data);

    printf("\nSender Side\n");
    printf("input: %s\n", data);

    for (i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if (data[i] == '1')
        {
            count++;

            if (count == 5)
            {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    stuffed[j] = '\0';

    printf("output : %s\n", stuffed);

    return 0;
}