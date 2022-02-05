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

vector<int> bubbleSort(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {9, 1, 8, 4, 7, 2, 6, 3};
    display(arr);
    cout << endl;
    arr = bubbleSort(arr);
    display(arr);

    return 0;
}