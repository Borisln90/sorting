#include <iostream>
#include <time.h>
#include <algorithm>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;

void bubbleSort(int arr[], int length);
void insertionSort(int a[], int length);
void selectionSort(int a[], int length);
void quickSort(int a[], int p, int r);
int partition(int a[], int p, int r);
void mergeSort(int a[], int p, int r);
void merge(int a[], int p, int q, int r);
void swap(int& a, int& b);
void print(int arr[], int length);
int randomizedPartition(int a[], int p, int r);
int randomizedSelect(int a[], int p, int r, int i);
void median(int a[], int left, int right, int k);

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void print(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = length-1; j >= i+1; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}


void insertionSort(int a[], int length)
{
    int key, i;
    for (int j = 1; j < length; j++)
    {
        key = a[j];
        i = j-1;
        while (i >= 0 && a[i] >= key)
        {
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
}

void selectionSort(int a[], int length)
{
    int iMin;
    for (int j = 0; j < length-1; j++)
    {
        iMin = j;
        for (int i = j+1; i < length; i++)
        {
            if (a[i] < a[iMin])
            {
                iMin = i;
            }
        }
        if (iMin != j)
        {
            swap(a[j], a[iMin]);
        }
    }
}

int partition(int a[], int p, int r)
{
    int q, i;
    q = a[r];
    i = p-1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= q)
        {
            i = i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);

    return i+1;
}

void quickSort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}

void merge(int a[], int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int* L = new int[n1+1];
    int* R = new int[n2+1];
    for (i = 0; i < n1; i++)
    {
        L[i] = a[p+i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    i = 0, j = 0;
    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i = i + 1;
        }
        else
        {
            a[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}



int random(int a, int b){
    int range = (b - a);
    return a + int((range * rand()) / (RAND_MAX + 1.0));
}

int randomizedPartition(int a[], int p, int r){
    int i = random(p, r);
    swap(a[r], a[i]);
    return partition(a, p, r);
}

int randomizedSelect(int a[], int p, int r, int i){
    if (p == r)
    {
        return a[p];
    }
    int q = randomizedPartition(a, p, r);
    int k = q - p + 1;
    if (i == k)
    {
        return a[q];
    }
    else if (i < k)
    {
        return randomizedSelect(a, p, q - 1, i);
    }
    else
    {
        return randomizedSelect(a, q + 1, r, i - k);
    }
}

int main(int argc, char** argv) 
{   
    srand((unsigned)time(0));

    int size = 200;
    clock_t t1, t2;


    int * arrs = new int[size];
    for (int i = 0; i < size; i++)
    {
        arrs[i] = i;
    }
    


    //int arrs[21] = {9,7,4,6,3,1,2,20,8,0,44,2,3,44,5,6,7,4,332,7, 8};
    t1 = clock();
    int ran = randomizedSelect(arrs, 0, size-1, (size/2)+1);
    t2 = clock();
    float diff = ((float)t2 - (float)t1)/(CLOCKS_PER_SEC/1000);
    cout << diff << endl;

    delete[] arrs;
    cin.get();
    return 0;
}
