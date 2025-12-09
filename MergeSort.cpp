#include <iostream>
#include <vector>
using namespace std; 

void print(const vector<int>& arr) { 
  for(size_t j = 0; j < arr.size(); j++) { 
    cout << arr[j] << " ";   
  }
  cout << endl; 
} 


void merge(const vector<int>& leftArray, const vector<int>& rightArray, vector<int>& array, int& c) {
  
 
    int leftsize = array.size() / 2; 
    int rightsize = array.size() - leftsize; 
    int i = 0; // origional i 
    int l = 0; 
    int r = 0; 
    
    //Checking conditions for merge. 
    while(l < leftsize && r < rightsize) { 
      if (leftArray[l] < rightArray[r]) { 
          array[i] = leftArray[l]; 
          i++; 
          l++; 
          c++; // increment global comparrison variable. 
      } 
      else { 
        array[i] = rightArray[r]; 
        i++; 
        r++; 
        c++;
      }
    }
      
      while(l < leftsize) { 
        array[i] = leftArray[l]; 
        i++; 
        l++; 
      } 
    
        while(r < rightsize) { 
          array[i] = rightArray[r]; 
          i++; 
          r++; 
        } 
}
 
void mergesort(vector<int>& arr, int& c, int start = 0) {
    int size = arr.size();

    if (size <= 1) return;

    int middle = size / 2;

    // Print current segment indices

    // Creating subarrays
    vector<int> leftArray, rightArray;
    leftArray.resize(middle);
    rightArray.resize(size - middle);

    for (int i = 0; i < size; i++) {
        if (i < middle) {
            leftArray[i] = arr[i];
        } else {
            rightArray[i - middle] = arr[i];
        }
    }

    // Recursive calls with correct start
    mergesort(leftArray, c, start);
    mergesort(rightArray, c, start + middle);

    // Merge
    merge(leftArray, rightArray, arr, c);
    
}


int main() {
   int comparisons = 0; 

   cout << "enter size followed by the entries." << endl; 
   cout << "Example: 6 3 2 1 5 9 8" << endl; 
   int size;
   std::cin >> size;
   std::vector<int> num(size); 

   // Read numbers
   for (int i = 0; i < size; i++) {
       cin >> num[i];
   }


    cout << endl <<"unsorted: "; 
    print(num); 
    cout << endl; 
    
    
    mergesort(num,comparisons,0); 
    
    cout << "sorted:   "; 
    print(num); 
    cout << "comparisons: " << comparisons; 
    
    return 0;
}
