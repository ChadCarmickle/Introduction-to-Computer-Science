// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std; 


void printChar(char c,int x) { 
    for(int i=0;i<x;i++) { 
      cout << c;   
    } 
          cout << endl;   
}
void print(const string arr[], int arrSize) { 
    for(int i=0;i<arrSize;i++) { 
      cout << arr[i] << ", ";   
    } 
    cout << endl; 
}
void print(const int arr[], int arrSize) { 
    for(int i=0;i<arrSize;i++) { 
      cout << arr[i] << ", ";   
    } 
    cout << endl; 
    
} 

int partition(int arr[], int start, int end) {
    int pivot = arr[end]; 
    int i = start - 1; 
    
    for(int j = start; j < end; j++) { 
      if (arr[j] < pivot) { 
        i++; 
        swap(arr[i], arr[j]);
      } 
    }
    swap(arr[i+1], arr[end]); 
   return i + 1; 
}

void quickSort(int arr[], int start, int end) {

    if(end < start) return; // base case; 
    int pivot = partition(arr,start, end); 
    quickSort(arr,start,pivot - 1); 
    quickSort(arr,pivot + 1,end); 
}

//************************ String *********************************
int partition(std::string arr[], int start, int end) { 
    std::string pivot = arr[end];
    int i = start - 1; 
    
    for(int j = start; j < end; j++) { 
      if (arr[j] < pivot) { 
        i++; 
        std::swap(arr[i], arr[j]);
      } 
    }
    std::swap(arr[i + 1], arr[end]);
   return i + 1; 
}

void quickSort(std::string arr[], int start, int end) { 
    
        if(start >= end) return; // base case; 
        int pivot = partition(arr,start, end); 
        quickSort(arr,start,pivot - 1); 
        quickSort(arr,pivot + 1,end); 

    }








int main() {
string star[1] = {"*"}; 
string names[30] = {
        "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon",
        "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie",
        "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill",
        "Pidgey", "Pidgeotto", "Pidgeot", "Rattata", "Raticate",
        "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu",
        "Raichu", "Sandshrew", "Sandslash", "Nidoran", "Mew"
    };
int lvls[30] = {23, 7, 45, 12, 89, 33, 58, 4, 76, 19,
88, 2, 37, 61, 48, 14, 54, 93, 31, 17,
10, 65, 27, 41, 82, 6, 49, 74, 15, 34};

int names_size = sizeof(names) / sizeof(names[0]);
int lvls_size = sizeof(lvls) / sizeof(lvls[0]);

printChar('*',70); 
cout << "Before sort:" << endl;
printChar('*',70); 
print(names, names_size);
cout << endl;
print(lvls, lvls_size);


quickSort(names,0,names_size - 1); 
quickSort(lvls,0,lvls_size -1); 

printChar('*',70); 
cout <<  "After sort:" << endl;
printChar('*',70); 
print(names,names_size); 
print(lvls,lvls_size); // after. 

// before sort. 

 








    return 0;
}
