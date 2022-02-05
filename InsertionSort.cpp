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

vector<int> insertionSort(vector<int> arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and  arr[j] > key )
        {
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] =key;
    }
    return arr;
}

int main()
{
    vector<int> arr = {9,8,7};
    arr = insertionSort(arr);
    display(arr);

    return 0;
}