#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

template <typename T>
void swap (T *a, T *b) {
  T t = *a; 
  *a = *b; 
  *b = t;
}
template <typename T>
void printArray(vector<T> arr) 
{ 
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

template <typename T>
T partition (vector<T>& arr, int low, int high) 
{   
    T pivot = arr[high]; // pivot 
    T i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    
    return (i + 1); 
} 

template <typename T>
void quickSort(vector<T>& arr, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */

        T pi = partition(arr, low, high); 
      
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

template <typename T>
void quickSort(vector<T>& arr) {quickSort(arr, 0, arr.size() -1);}




int main()
{ 
  vector<int> test={4, 3,2,1, 7, -1, 0};
 
  quickSort(test);
  printArray(test);
  return 0;
}