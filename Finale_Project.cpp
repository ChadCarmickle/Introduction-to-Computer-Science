#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* ToDO:
Sort the data into a struct
Sort the Y cordinates in ascending order
Sort the X cordinates in ascending order
Implement a function to print coordinates */


void printCoordinates(int size, int coordinates[][2], string characters[]) {
    for (int i = 0; i < size; ++i) {
        cout << "X: " << coordinates[i][0] << ", Y: " << coordinates[i][1]
             << " | Char: " << characters[i] << endl;
    }
}

// Define struct to x, y and character values. 
struct DataCordinates {
    int x;
    int y;
    string character;
};

int main() {

    // Open file
    std::ifstream file("data.txt");
    
    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    }

    // Count lines
    int lineCount = 0;
    std::string line;
    while (getline(file, line)) {
        lineCount++;
    }

    // Adjust for the first two header lines
    lineCount -= 2;

    // Check if data is valid
    if (lineCount % 3 != 0 || lineCount <= 0) {
        cerr << "Invalid data format." << endl;
        return 1;
    }
    // set size based on number of data entries
    int size = lineCount / 3;

    // Arrays to store data
    int coordinates[size][2];
    std::vector<std::string> characters(size);

    // Reset file to start due to reading lines earlier and setting size of array. 
    file.clear();
    file.seekg(0);

    // Skip first two lines
    getline(file, line);
    getline(file, line);

    // Read data
    for (int i = 0; i < size; ++i) {
        string xStr, yStr; // strings for coordinates
        getline(file, xStr); // read x coordinate
        getline(file, characters[i]); // read character line 
        getline(file, yStr); // read y coordinate

        // Convert strings to int
        coordinates[i][0] = stoi(xStr);
        coordinates[i][1] = stoi(yStr);
    }
    // Close file
    file.close();


// TESTING: Print all coordinates
// printCoordinates(size, coordinates, characters);

// c++ demanded me to set it to a vector to avoid variable length array errors. 
std::vector<DataCordinates> dataArray(size);



for (int i = 0; i < size; ++i) {
    dataArray[i].x = coordinates[i][0];
    dataArray[i].y = coordinates[i][1];
    dataArray[i].character = characters[i];

    // Print data for each
    cout << "X = " << dataArray[i].x 
         << " | Y = " << dataArray[i].y 
         << " | Character = " << dataArray[i].character << endl;
        }
    return 0;
}
