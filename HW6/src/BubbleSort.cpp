

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void bubble_sort(vector<int>& a);

void bubble_sort(int num[]) 
{
    for (int i=0;i<sizeof(num);i++) 
    {
        for(int j=0;j<sizeof(num);j++)
        {
            if(num[j]>num[j+1])
            {
                int temp;
                temp=num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
            }
        }
    }
}

void bubble_sort(vector<int>& a)
{
    for (int i=0;i<sizeof(a);i++) 
    {
        for(int j=0;j<sizeof(a);j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}


bool validate(int arr[], vector<int>& vect) 
{
    int size = sizeof(arr);
    for (int i = 0; i<size; i++)
    {
        #cout << arr[i] << endl;
        if(arr[i] != vect.at(i))
            return false;
    }

    return true;
}

int main()
{
    int input;

    cout << "Enter value for n\n>";
    cin >> input;

    int* arr = new int[input];
    vector<int> vect;

     srand(time(nullptr));
    for(int i = 0; i<input; i++)
    {
        int random = rand();
        arr[i] = random;
        vect.push_back(random);
    }

    auto start = chrono::steady_clock::now();
    bubble_sort(arr);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> arr_elapsed_time = end - start;
    
    start = chrono::steady_clock::now();
    bubble_sort(vect);
    end = chrono::steady_clock::now();
    chrono::duration<double> vect_elapsed_time = end - start;
    cout<< "Time for array: " << arr_elapsed_time.count() << endl;
    cout<<"Time for vector: " << vect_elapsed_time.count() << endl;
    cout << "Match?: ";
    if(validate(arr, vect) == 0)
        cout << "False";
    else
        cout << "True";

}