/* 
Chad Carmickle 
12/4/25 
Challenge: 
Write a program that reads a list of integers and outputs those integers in reverse. The input begins with an integer indicating the number of integers that follow. For coding simplicity, follow each output integer by a comma, including the last one.
*/ 


#include <iostream>
#include <vector>   
using namespace std;

// Calling a function to reverse the order. 
void Reverse(const vector<int>& vec, int size) { // Pass by constant reference
    cout << "Reversed order: "; 
    for (int i = size-1; i >= 0; i--) { // start at the end of the vector.  
      cout << vec[i];   // Output
        
        // Prevents run on comma after last element printed. 
        if (i > 0) { 
            cout << ",";
        }    
    } 
    cout << endl; 
} 

int main() {
    int size = 5; // Default size of vecotor. 

    cout << "Enter number of integers: ";
    cin >> size;

    vector<int> userInts(size); // Create vector of required size

    cout << "Enter integer(s): "; 
    for (int i = 0; i < size; i++) {
        cin >> userInts[i]; // Store the input in the vector
    }

    // Call function to reverse & print vector. 
    Reverse(userInts, size); 
    
    cout << endl << "Thanks! have a wonderful day!" << endl; 
    return 0;
}
/**********************Output******************************
Enter number of integers: 5
Enter integer(s): 5 4 3 2 1
1,2,3,4,5

Thanks! have a wonderful day!
*/ 

