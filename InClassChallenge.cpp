***********************************************************************************************************************************************/ 
In CLass Assignment. 
12-2-25 
Intro to CS. 

Chad Carmickle -> Max & Input. 
Bryan - Average. 

Assigned Functions
  Each team must implement the following three functions:
  1.	Input Function-
        A function that receives an array and its size, and fills the array with values provided by the user.
  2.	Average Function-
        A function that receives the same array and its size, processes all values in the array, and returns the calculated average.
  3.	Maximum Value Function- 
        A function that receives the array and its size and returns the highest value stored in the array.

Team Instructions- 
  •	Assign one function to each group member.
  •	Each student writes only the function assigned to them.
  •	After all three functions are complete, combine them into one program that uses all functions together.
  •	The team should test the final program and make adjustments if needed.
Deliverable
        A completed program containing the three required functions working together with an array, with each function written by a different team member.

  
***********************************************************************************************************************************************/ 

#include <iostream>
using namespace std; 


void Input(int arr[], int ArrSize) { 
    cout << "Enter 3 numbers" << endl; 
    for (int i = 0; i<ArrSize; i++) { 
      cin >> arr[i];   
    }
     // Display the inputs for confirmation
    cout << "You entered:";
    for (int i = 0; i < ArrSize; i++) {
        cout << " " << arr[i];
    }
    cout << "." << endl; 
}

// Average Function
void averageFunction(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    cout << endl << " total: " << total << endl;
}
// Max function. 
void Max(int arr[], int ArrSize) { 
  int CurrMax = 0;   
    for (int i = 0; i < ArrSize; i++) { 
      if(arr[i] > CurrMax) { 
        CurrMax = arr[i]; 
      }
    }
    cout << endl << " Min value = " << CurrMax << endl; 
} 

int main() {
//Declare variables. 
const int ArraySize = 3; 
int userInput[ArraySize];
    
    // call the function: Input. 
    Input(userInput, ArraySize);
    
    // Obtain the Max value of the function. 
    Max(userInput, ArraySize);

    // Obtain the Average of the array. 
    averageFunction(userInput, ArraySize);

    return 0;
}
