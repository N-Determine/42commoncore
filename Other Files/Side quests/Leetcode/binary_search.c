int search(int* nums, int numsSize, int target) 
{
    int index = (numsSize - 1) / 2;
    int upper = numsSize - 1;
    int lower = 0;
    while (lower <= upper && index < numsSize)
    {
        if (nums[index] == target)
            return (index);
        if (nums[index] < target)
        {
            if (lower == index)
                return (-1);
            lower = index;
            index += (upper - lower) / 2;
        }
        else if (nums[index] > target)
        {
            if (upper == index)
                return (-1);
            upper = index;
            index -= (upper - lower) / 2;
        }
    }
    return (-1);
}

#include <stdio.h>

#define SIZE 2

int main(void)
{
	int arr[SIZE] = {2, 5};
	int target = 5;
	printf("The index is at: %i\n", search(arr, SIZE, target));
}