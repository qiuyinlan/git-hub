/*6.编写一个函数接受 3 个参数：一个数组名（内含已排序的整数）、该
数组的元素个数和待查找的整数。如果待查找的整数在数组中，那么该函数
返回 1；如果该数不在数组中，该函数则返回 0。用二分查找法实现。*/
#include <stdio.h>
#define SIZE 10

int binary_search(const int sorted[], int size, int val);

int main(void)
{
    int num, found;
    int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Please enter a number for searching (q to quit): ");
    while (scanf("%d", &num) == 1)
    {
        found = binary_search(nums, SIZE, num);
        if (1 == found)
        {
            printf("%d exists in the array.\n", num);
        }
        else
        {
            printf("%d doesn't exist in the array.\n", num);
        }
        printf("You can enter again (q to quit): ");
    }
    puts("Done.");

    return 0;
}

int binary_search(const int sorted[], int size, int val)
{
    int mid;
    int min = 0;
    int max = size - 1;
    int found = 0;

    while (min < max)
    {
        mid = (min + max) / 2;
        if (val < sorted[mid])
        {
            max = mid - 1;
        }
        else if (val > sorted[mid])
        {
            min = mid + 1;
        }
        else
        {
            found = 1;
            break;
        }
    }
    if (sorted[min] == val)
    {
        found = 1;
    }
    return found;
}