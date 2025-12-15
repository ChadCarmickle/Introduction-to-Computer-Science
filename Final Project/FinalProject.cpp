#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* ToDO:
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

void SortStructuresByY(std::vector<DataCordinates>& dataArray) {
    int size = dataArray.size();
    // Simple bubble sort based on Y values
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (dataArray[j].y > dataArray[j + 1].y) {
                // Swap entire struct
                std::swap(dataArray[j], dataArray[j + 1]);
            }
        }
    }
}

void SortStructuresByX(std::vector<DataCordinates>& dataArray) {
    int size = dataArray.size();
    // Simple bubble sort based on X values
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (dataArray[j].x > dataArray[j + 1].x) {
                // Swap entire struct
                std::swap(dataArray[j], dataArray[j + 1]);
            }
        }
    }
}

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

    // Check if data is valid divisable by 3. 
    if (lineCount % 3 != 0 || lineCount <= 0) {
        cerr << "Invalid data format." << endl;
        return 1;
    }
    // set size based on number of data entries
    int size = lineCount / 3;

    // Arrays to store data
    int coordinates[size][2];
    std::vector<std::string> characters(size);

    // Reset file to start due to reading lines earlier.
    file.clear();
    file.seekg(0);

    // Skip first two lines again. 
    getline(file, line);
    getline(file, line);

    // Read x cord, y cord and character. 
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


// Set the data into struct array. 
for (int i = 0; i < size; ++i) {
    dataArray[i].x = coordinates[i][0];
    dataArray[i].y = coordinates[i][1];
    dataArray[i].character = characters[i];

    // Print data for each for testing. 
    /*
    cout << "X = " << dataArray[i].x 
         << " | Y = " << dataArray[i].y 
         << " | Character = " << dataArray[i].character << endl;
    }
    */ 
}

    // Use bubble sort to sort by Y values.
    SortStructuresByY(dataArray);
    SortStructuresByX(dataArray);

    /*
    // Print sorted data for testing. 
    
    for( int i = 0; i < size; ++i) {
    cout << "X = " << dataArray[i].x 
         << " | Y = " << dataArray[i].y 
         << " | Character = " << dataArray[i].character << endl;
    }
    */

    // Find max x value for width
    int maxX = dataArray[0].x;
    for (int i = 1; i < size; ++i) {
        if (dataArray[i].x > maxX) {
            maxX = dataArray[i].x;
        }

    }
        // Find max y value for height
    int maxY = dataArray[0].y;
    for (int i = 1; i < size; ++i) {
        if (dataArray[i].y > maxY) {
            maxY = dataArray[i].y;
        }

    }
    // Print max values for testing. 
       // cout << "Max X value (width): " << maxX << endl;
       // cout << "Max Y value (height): " << maxY << endl;


    for(int y = 0; y <= maxY; ++y) {
        for(int x = 0; x <= maxX; ++x) {
            bool found = false;
            for(int i = 0; i < size; ++i) {
                if(dataArray[i].x == x && dataArray[i].y == y) {
                    cout << dataArray[i].character;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << " "; // Print space if no character at this coordinate
            }
        }
        cout << endl; // New line after each row
    }
        return 0;
}

