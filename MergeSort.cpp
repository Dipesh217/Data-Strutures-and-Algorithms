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

vector<int> mergeSort(vector<int> arr, int low, int mid, int high)
{
    vector<int> a;
    int i = low;
    int j = mid + 1;

    while (i != mid + 1 and j != high)
    {
        if (arr[i] > arr[j])
        {
            a.push_back(arr[j]);
            j++;
        }
        else if (arr[i] < arr[j])
        {
            a.push_back(arr[i]);
            i++;
        }
        else
        {
            a.push_back(arr[i]);
            i++;
            a.push_back(arr[j]);
            j++;
        }
    }

    if (i == mid + 1)
    {
        while (j != high)
        {
            a.push_back(arr[j]);
            j++;
        }
    }

    if (j == high)
    {
        while (i != mid + 1)
        {
            a.push_back(arr[i]);
            i++;
        }
    }
    return a;
}

int main()
{
    vector<int> arr = {4, 5, 7, 8, 1, 3, 4, 5, 6};
    int high = arr.size();
    int low = 0;
    int mid = 3;
    display(arr);
    cout << endl;
    arr = mergeSort(arr, low, mid, high);
    display(arr);

    return 0;
}