void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortArray(int *arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int cSize = nums1Size + nums2Size;
    // printf("Total elements in merged array is %d\n",cSize);
    int *merged = (int *)calloc(cSize, sizeof(int));
    int index = 0;
    int median;

    //? Making a mergec array
    for (int i = 0; i < nums1Size; i++)
    {
        merged[index] = nums1[i];
        index++;
    }
    for (int j = 0; j < nums2Size; j++)
    {
        merged[index] = nums2[j];
        index++;
    }

    //? Sorting the merged array
    sortArray(merged, cSize);

    //? Returning the median
    if (cSize % 2 == 0)
    {
        // printf("Middle most value of merged array are : %d and %d\n",(cSize/2) - 1,cSize/2);
        float output = ((merged[(cSize / 2) - 1] + merged[cSize / 2]));
        return output/2;
    }
    else
    {
        // printf("Middle value of merged array is : %d\n",((cSize-1)/2));
        return (merged[(cSize - 1) / 2]);
    }
}