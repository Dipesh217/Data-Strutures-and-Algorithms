#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> selectionSort(vector<int> arr)
{
    int size = arr.size();
    int minIndex;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
    return arr;
}

int main()
{
    vector<int> arr = {9, 1, 8, 4, 7, 2, 6, 3};
    arr = selectionSort(arr);
    display(arr);

    return 0;
}