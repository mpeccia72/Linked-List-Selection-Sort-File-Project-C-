#include <iostream>
#include <fstream>

// header file for the linked list class
#include "./linkedlist.h" 

using namespace std;

// Precondition: there is a file of integers and a linked list present
// Postcondition: inserts integers from the input file into a linked list
void insertData(ifstream&, List&);

// Precondition: there is an instance of ofstream and a linked list present
// Postcondition: inserts integers from the linked list into output file
void outputData(ofstream&, List);

int main()
{
    // input and output file objects
    ifstream input;
    ofstream output;
    
    // object of List
    List myList;
    
    // opens the file of data
    input.open("num.txt");
    
    // Checks if file fails to input
    if(input.fail()) {
        cout << "Failed to input file!\n";
        exit(0);
    }
    
    // inserts input file data into linked list
    insertData(input, myList);
    myList.selectionSort();
    
    // creates output file called "num_ascended.txt"
    output.open("num_ascended.txt");
    
    // Checks if output file fails
    if(output.fail()) {
        cout << "Failed to output file!\n";
        exit(1);
    }
    
    // outputs linked list
    outputData(output, myList);
    cout << "The data has been organized in ascending order via selection sort in 'num_ascended.txt'\n";
    
    // closes both files
    input.close();
    output.close();
    
    return 0;
}

void insertData(ifstream& input, List& list) {
    while(!input.eof()) {
        int num;
        input >> num;
        list.addNode(num);
    }
}

void outputData(ofstream& output, List list) {
    for(int i = 0; i < list.length; i++) {
        output << list.indexOf(i) << " ";
    }
}