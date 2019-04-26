#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

#include "PQType.h"
#include "tools.hpp"

typedef int ItemType;
char dataStructure;

using namespace std;

char typeSelection(void);
int menuSelection(char ds);

int main()
{
    banner(); // Call to banner

    ItemType item;
    ItemType *word =new ItemType[25];
    int elements = 0;

    char dataStructure;
    int select;
    string option;
    int qsize;
    int store = 0;

    ofstream outFile;      // file containing output
    string outFileName = "out";
    string outputLabel = "Heap";
    outFile.open(outFileName.c_str(), ios::out | ios::app);
    outFile << "\n[" << outputLabel << "]" << endl << endl;

    dataStructure = typeSelection();

    if (dataStructure == 'd')
    {
	vector<string> elements = {"introspective", "intelligent", "intellectual", "intimate",
                                "intensive", "interesting", "internal", "into", "in","intro"};
	int n = elements.size();
	int	i;
	cout<<"\n-> Priority Queue"<<endl;
	PQType<string> queue(n + 5);

	for(i = 0; i < n; i++)
        {
            queue.Enqueue(elements[i], dataStructure);
        }
	queue.PQPrintArray();
	queue.PQPrint();
	queue.Enqueue(string("interviewing"), dataStructure);
    cout<<"\n-> Insert Interviewing:"<<endl;
	queue.PQPrintArray();
	queue.PQPrint();
    }
    else
    {

    cout << "\nBefore we proceed, please set a [SIZE] for the queue: " << endl;
    cin >> qsize;
    PQType<ItemType> queue(qsize);

    do{
        select = menuSelection(dataStructure);
        switch(select)
        {
            case 1:
                {
                cout << "How many elements to be enqueued?" << endl;
                cin >> elements;

                for(int i=0; i<elements; i++)
                {
                    cout << "Enter the element to be enqueued: " << endl;
                    cin >> (item);

                    word[store++] = item;

                    try{
                        // Function call to enqueue
                        queue.Enqueue(item, dataStructure);
                        outFile << item << " is enqueued." << endl;
                        cout << item << " is enqueued." << endl;
                        }
                    catch (FullPQ)
                        {
                        cout << "\nQueue is full!" << endl;
                        break;
                        }
                }
                }
                break;
            case 2:
                cout << "How many elements to be dequeued?" << endl;
                cin >> elements;
                do{
                    try{
                        queue.Dequeue(item, dataStructure);
                    }
                    catch(EmptyPQ)
                    {
                        cout << "\nQueue is empty!" << endl;
                    }

                    elements--;

                    }while(elements > 0);
                break;
            case 3:
                {
                    queue.MakeEmpty();
                    break;
                }
            case 4:
                {
                    cout << "\nPrint Queue: " << endl;
                    queue.PrintQueue(dataStructure);
                    cout << "\nPrint elements:" << endl;

                    int words = 0;
                    while(words<store)
                    {
                        cout << word[words++] << endl;
                    }
                    break;
                }
            // Case to display a message and quit the program.
            case 5:
                {
                    cout<<"\nGood Bye!!!"<<endl;
                    break;
                }

            default:
                cout << "Error: Invalid selection. Please try again!" << endl;
        }
    }while(select !=5);

    outFile.close();

    bye();

    return 0;
}
}

char typeSelection(void)
{
    char dataStructure;

    // Data Structure Choices
    cout << " Data Structure Types: " << endl;
    cout << "a. Array List Data Structure." << endl;
    cout << "b. Linked List Data Structure." << endl;
    cout << "c. Binary Search Tree Data Structure." << endl;
    cout << "d. Heap (Priority Queue) Data Structure." << endl;
    cout << "Select (Input a or b or c or d):_";
    cin >> dataStructure;

    if (dataStructure == 'd')
    {
        cout << "\nPriority of the strings is dependent on the length of strings." << endl;
//        cout << "Enter the elements in following order:" << endl;
//        cout << "introspective intelligent intellectual intimate intensive interesting  internal into in intro" << endl;
    }

    return dataStructure;
}

int menuSelection(char ds)
// Function: Displays Preconditions for the program and the Switch case menu.
// Precondition: Initializes select.
// Postcondition: Return users choice.
{
    int select;

    if(ds == 'a')
        cout << "\t Array List Operations \n" << endl;
    else if (ds == 'b')
        cout << "\t Linked List Operations \n" << endl;
    else if (ds == 'c')
        cout << "\t Binary Search Tree Operations \n" << endl;
    else
        cout << "\t Heap Operations \n" << endl;

    // Menu choices
    cout << " MENU OPTIONS " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Reset Queue" << endl;
    cout << "4. Print Queue" << endl;
    cout << "5. Quit" << endl;
    cout << "Select:_";
    cin >> select;

    return select;
}
