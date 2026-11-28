#include <iostream>
#include <cstdlib>

using namespace std;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 2;
    int *arr = (int*)malloc(sizeof(int)*2);

    arr[0] = -1;
    arr[1] = -1;

    int min = 0;
    int max = numsSize - 1; 


    // first 
    while(min <= max)
    {
        int mid = min + (max - min) / 2;

        if (nums[mid] >= target)
        {
            if (nums[mid] == target)
                arr[0] = mid;

            max = mid - 1;
        }
        else 
        {
            min = mid + 1;
        }
    }

    min = 0;
    max = numsSize - 1; 

    while(min <= max)
    {
        int mid = min + (max - min) /2;
        if (nums[mid] <= target)
        {
            if (nums[mid] == target)
                arr[1] = mid;
            min = mid + 1;
        }

        else 
        {
            max = mid - 1;
        }
    }

    return arr;
}


int main()
{
    int nums1[] = {5, 7, 7, 8, 8, 10};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1 = 0;

    int* res1 = searchRange(nums1, size1, 8, &returnSize1);
    cout << "Test 1 (target 8): [" << res1[0] << ", " << res1[1] << "]" << endl;
    free(res1); // Free malloced memory

    // Test Case 2: Target not found
    int returnSize2 = 0;
    int* res2 = searchRange(nums1, size1, 6, &returnSize2);
    cout << "Test 2 (target 6): [" << res2[0] << ", " << res2[1] << "]" << endl;
    free(res2);

    // Test Case 3: Empty array
    int* nums3 = nullptr;
    int returnSize3 = 0;
    int* res3 = searchRange(nums3, 0, 0, &returnSize3);
    cout << "Test 3 (empty):    [" << res3[0] << ", " << res3[1] << "]" << endl;
    free(res3);

    return 0;
}