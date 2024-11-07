#include<stdio.h>
#include<math.h>

int main()
{
    int arr[8], i;
    for(i = 0; i < 8; i++)
    {
        arr[i] = (int)pow(2, i);
    }
    
    i = 0;
    do
    {
        printf("%d\n", arr[i]);
        i++;
    }
    while(i < 8);

    return 0;
}
