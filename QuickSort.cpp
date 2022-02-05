#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i],arr[j]);
        }
    } while (i < j);

    // Swap A[low] and A[j]
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> arr, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{

    vector<int> arr = {9, 4, 4, 8, 7, 5, 6};
    int n = arr.size();
    printArray(arr, n);
    quickSort(arr,0,n-1);
    printArray(arr, n);

    return 0;
}
