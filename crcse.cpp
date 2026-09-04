#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], divisor[30], temp[130];
    int i, j, dataLen, divLen;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divLen = strlen(divisor);

    strcpy(temp, data);

    /* Append zeros */
    for(i = 0; i < divLen - 1; i++)
        temp[dataLen + i] = '0';

    temp[dataLen + divLen - 1] = '\0';

    /* Modulo-2 division */
    for(i = 0; i < dataLen; i++)
    {
        if(temp[i] == '1')
        {
            for(j = 0; j < divLen; j++)
                temp[i + j] =
                (temp[i + j] == divisor[j]) ? '0' : '1';
        }
    }

    printf("\nCRC: ");
    for(i = dataLen; i < dataLen + divLen - 1; i++)
        printf("%c", temp[i]);

    printf("\nTransmitted Codeword: %s", data);

    for(i = dataLen; i < dataLen + divLen - 1; i++)
        printf("%c", temp[i]);

    return 0;
}