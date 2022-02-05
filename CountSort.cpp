#include <iostream>
#include <vector>
using namespace std;

vector<int> countSort(vector<int> arr)
{
    vector<int> temp(10,0);
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        temp[arr[i]]++;
    }
;

    int j = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] >= 1)
        {
            while (temp[i] != 0)
            {
                arr[j] = i;
                temp[i]--;
                j++;
            }
        }
        
    }
    return arr;
}

void display(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    vector<int> arr = {1, 8, 5, 7, 6, 9};
    display(arr);
    cout<<endl;
    arr = countSort(arr);
    display(arr);

    return 0;
}