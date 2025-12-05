#include <iostream>
using namespace std;

/* 
Chad Carmickle 
12-5-25 
Challenge: 
Write a void function SelectionSortDescendTrace() that takes an integer array and sorts the array into descending order. The function should use nested loops and output the array after each iteration of the outer loop, thus outputting the array N-1 times (where N is the size). Complete main() to read in a list of up to 10 positive integers (ending in -1) and then call the SelectionSortDescendTrace() function. For coding simplicity, output a space after every integer, including the last one on each row.

If the input is:

20 10 30 40 -1
then the output is:

40 10 30 20 
40 30 10 20 
40 30 20 10 

*/ 


void SelectionSortDescendTrace(int numbers[], int numElements) {
  for(int i = 0; i < numElements - 1; i++) { // We start at numEle - 1 for optimization. 
    int maxIndex = i; 
    // innerLoop j equals 
    for(int j=i + 1; j < numElements; j++) { 
	   if(numbers[j] > numbers[maxIndex]){
              maxIndex = j; 	   
	   }
        }
        int temp = numbers[i]; 
	numbers[i] = numbers[maxIndex]; 
	numbers[maxIndex] = temp; 
    
    for (int i = 0; i < numElements; i++) { 
       cout << numbers[i] << " " ;
       }
       cout << endl; 
  }

} //end of function. 



int main() {
   int input = 0;
   int count = 0; 
   int numElements = 0;
   int numbers[10];


    for (int j = 0; j < 10; j++) { 
        cin >> input; 
        if (input < 0) { 
            break; // Stop input on negative number
        }
        numbers[count++] = input; // Store valid inputs
    }   
 


// Set the size of the array. 
   int size = count; 

   SelectionSortDescendTrace(numbers, size);


  return 0;
}
