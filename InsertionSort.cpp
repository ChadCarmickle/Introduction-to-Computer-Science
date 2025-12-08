// Online C++ compiler to run C++ program online
/* 
Chad Carmickle 
12/8/25 

Ex: When the input is:
Make an Insertion Sort that takes the first 
number as the size of the Vector then outputs. 

Display each itteration of the sort and the number of comparirisons & swaps at the end. 
***************************************************
6 3 2 1 5 9 8
the output is:

 3 2 1 5 9 8

 2 3 1 5 9 8
 1 2 3 5 9 8
 1 2 3 5 9 8
 1 2 3 5 9 8
 1 2 3 5 8 9

comparisons: 7
swaps: 4

*/ 




#include <iostream>
#include <string> 
#include <vector>
using namespace std; 

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void SelectionSort(vector<int>& arr) {
    int arrSize = arr.size();
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
        print(arr);
    }
}




void InsertionSort(vector<int>& arr, int &comparisons, int &swaps) {
    int arrSize = arr.size();
    for (int i = 1; i < arrSize; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        print(arr);
    }
}



int main() {
   int comparisons = 0; 
   int swaps = 0; 

   int size;
   std::cin >> size;
   std::vector<int> numbers(size); 

   // Read numbers
   for (int i = 0; i < size; i++) {
       cin >> numbers[i];
   }

   print(numbers);
   cout << endl; 

   InsertionSort(numbers, comparisons, swaps); 

   cout << "comparisons: " << comparisons << endl; 
   cout << "swaps: " << swaps << endl; 

   return 0;
}
   
