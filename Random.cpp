// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std; 

/* 
Random practice prior to taking final coding assignment test. 
Score: 46/50. 

6.22 LAB: Swapping variables        10 points
6.26 LAB: Fibonacci sequence        10 points
7.22 LAB: Word frequencies          10 points
7.23 LAB: Contains the character    10 points
8.14 LAB: Binary search             10 points
*/ 


void print(int array[], int size) { 
  for(int i = 0; i < size; i++) { 
    cout << array[i] << " ";  
  } 
  cout << endl; 
} 
void bubbleSort(int (&array)[], int size) { 
    for(int i =0;i<size;i++) { 
      for(int j = 0; j < size - 1; j++) { 
        if (array[i] < array[j]) { 
          swap(array[i], array[j]);   
        } 
      } 
    } 
} 

void Fibonacci(int size, bool display) { 


int array[size];     
array[0] = 0; 
array[1] = 1;

if(display) {
cout << "\nDisplay steps: True"; 
cout << "\nF(0) = " << array[0]; 
cout << "\nF(1) = " << array[1]; 

    for(int i = 2; i < size; i++ ) { 
    array[i] = array[i-1] + array[i-2];     
        cout << "\nF(" << i << ") = " 
             << array[i] << " (" << array[i-1] << "+" << array[i-2] << ")";  
    }
    cout << endl; 
}
else { 
    cout << "\nDisplay steps: False"; 
    cout << "\nFibonacci Method f(" << size << ") = " ;  
    for(int i = 2; i < size; i++ ) { 
    array[i] = array[i-1] + array[i-2];     
    cout << array[i] << ", "; 
    }
    cout << endl; 
}
} 

int countCharacterOccurrences(string sent, char target) { 
  int count = 0; 
  for(int i = 0; i < sent.length(); i++) { 
      if (sent.at(i) == target) { 
      count++; 
      } 
  } 
  
  return count;   
} 
int countWordOccurrences(string& sent, string target) { 
    int count = 0;
    size_t pos = 0;

    while ((pos = sent.find(target, pos)) != std::string::npos) {
        count++;
        pos += target.length(); // Move past the last found word
    }

    return count;
} 

int binarySearch(int* array, int size, int target) {
    int low = 0; 
    int high = size - 1;
    
    while(low <= high) { 
        int middle = low + (high - low) / 2; 
        int value = array[middle]; 
        
        if (value < target )  { 
          low = middle + 1;   
        }
        else if(value > target) { 
          high = middle - 1;   
        } 
        else { 
          return middle;   
       } 
    }
    return -1; 
}  


int main() {

// Basic declartion 
int numbers[9] = {5,2,4,9,1,6,7,8,3};
int size = sizeof(numbers) / sizeof(numbers[0]);

// Print before & after sorting data. 
print(numbers, size); 
bubbleSort(numbers,size); 
print(numbers, size); 

int Number_ToSearch = 5; 
int indexofSearch = binarySearch(numbers,size,Number_ToSearch); 

if(indexofSearch == -1) { 
  cout << "No results found";   
} 
else { 
  cout << "Number: " << Number_ToSearch 
       << ".\nLocated at index: " << indexofSearch << endl; 
} 

Fibonacci(15,true); 





string ChessPieces[6] = {"pawn","Rook","Bishop","Knight","Queen","King"};  
string black_move =  "\nWob moved his " + ChessPieces[0] + " to attack chad's white squared "                 + ChessPieces[2] + " forking chad's " + ChessPieces[3] + " with a discovery attack by his " + ChessPieces[1];  
string white_move = "\nWith a large " + ChessPieces[0] + " chain, Chad ignores the threat of wob's " + ChessPieces[0] + " moving his " + ChessPieces[4] + " to set up an attack on wob's " + ChessPieces[5];  

cout << black_move << endl; 
cout << white_move << endl; 

char chartoFind = 'o'; 
int findCharFreq = countCharacterOccurrences(black_move,chartoFind); 
cout << "\nThe character:" << chartoFind << " appears in wob's sentence " << findCharFreq << " times.\n";   

string WordToFind = ChessPieces[5]; 
int findWordFreq = countWordOccurrences(white_move,WordToFind); 
cout << "\nThe word: " << WordToFind << " appears in Chad's sentence " << findWordFreq << " times.\n"; 



    return 0;
}

