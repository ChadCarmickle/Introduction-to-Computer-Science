#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

/* 
Part 1: 
Requirements:
1. Declare an array of 3 StudyRecord named records.
2. Choose three real subjects you personally study.
3. Fill minutes with the exact number of minutes you studied on each of the past 5 days (yesterday = index 0).
4. Values must reflect your real study pattern.

Part 2: 
Write and use all of the following functions:
1. int totalMinutes(const StudyRecord& r);
2. double averageMinutes(const StudyRecord& r);
3. int totalAll(StudyRecord arr[], int size);
4. int indexOfMax(StudyRecord arr[], int size);
Restrictions:
- All calculations must use loops.
- No global variables except constants.
- No library shortcuts.

PART 3 – Program Output Requirements (10 points)
Your program must print:
1. Each subject’s name, total minutes, average minutes.
2. The subject with the highest total using indexOfMax.
3. The overall total across all subjects.
Output must be clear and labeled.

PART 4 – Manual Trace Table (10 points)
Submit a short document containing:
1. A 3×5 table of all minutes recorded.
2. A step-by-step trace of how totalAll computes the final total.
3. A snapshot of:
   - Each subject’s total
   - Each subject’s average
   - Result of indexOfMax
   - Overall total

PART 5 – Oral Defense (Required)
You must be able to explain without reading code:
- Why your data is realistic.
- How each function works.
- How loops operate over arrays.
- How totals/averages were computed.
- Why indexOfMax returns an index.
Failure to pass oral defense = 0 points.
*/ 

struct StudyRecord {
    string subjectName;
    int minutes[5];
};

int totalMinutes(const StudyRecord& r) { 
int total = 0; 
    
    for(int j=0; j< 5; j++) { 
        total += r.minutes[j]; 
    } 
    
    return total;
}

double averageMinutes(const StudyRecord& r) { 
    int total = totalMinutes(r); // Call total function. 
    return static_cast<double>(total) / 5; 
}

int totalAll(StudyRecord arr[], int size) { 
int total = 0; 
    for(int i = 0; i < size; i++) { 
      total += totalMinutes(arr[i]);   
    } 
    return total; 
}

int indexOfMax(StudyRecord arr[], int size) { 
int maxIndex = 0; 

    for(int i; i < size; i++) { 
     if(maxIndex < totalMinutes(arr[i])) { 
        maxIndex = totalMinutes(arr[i]); 
     } 
    }
    return maxIndex;
}


StudyRecord record[3] = { 
{"Intro to Computer Science", {45, 51, 47, 75, 67}}, 
{"Video Editing", {15, 61, 81, 45, 77}}, 
{"Resume Edits", {25, 55, 47, 25, 67}}, 
};  

/***************************************************************/

int main() {

// Outputs the subjects I studied. 
for(int i = 0; i < 3; i ++) { 
cout << "\nSubject " << i << ": \n " << record[i].subjectName 
<< ": \n Total Study Time " << totalMinutes(record[i]) 
<< " minutes (" 
<< static_cast<double>(totalMinutes(record[i]) / 60.0)
<< " Hours) \n"
<< " Average: " << averageMinutes(record[i]) << "." << endl;  
}

cout << endl << "indexOfMax function: \n "; 


const int size = sizeof(record) / sizeof(record[0]);
const int MaxSubjectTime = indexOfMax(record,size); 

cout << record[MaxSubjectTime].subjectName << ":\n total: " 
     << totalMinutes(record[MaxSubjectTime]) << " minutes.\n";


cout << "\nAcross All Subjects Total: \n " << totalAll(record,size) << " Minutes."; 

    return 0;
}
