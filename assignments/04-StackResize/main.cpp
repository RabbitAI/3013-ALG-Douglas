///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack
{
private:
  int *A;   // pointer to array of int's
  int size; // current max stack size
  int top;  // top of stack

public:
  /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack()
  {
    size = 10;
    A = new int[size];
    top = -1;
  }

  /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s)
  {
    size = s;
    A = new int[s];
    top = -1;
  }

  /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty()
  {
    return (top <= -1);
  }

  /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full()
  {
    return (top >= size - 1);
  }

  /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek()
  {
    if (!Empty())
    {
      return A[top];
    }

    return -99; // some sentinel value
                // not a good solution
  }

  /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop()
  {
    if (!Empty())
    {
      return A[top--];
    }

    return -99; // some sentinel value
                // not a good solution
  }

  /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print()
  {
    for (int i = 0; i <= top; i++)
    {
      cout << A[i] << " ";
    }
    cout << endl;
  }

  /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x)
  {
    if (Full())
    {
      Resize();
    }
    if (!Full())
    {
      A[++top] = x;
      return true;
    }

    return false;
  }

  /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by 1.75
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow()
  {
    int newSize = size * 1.75; // increased the size of original 1.75 times
    int *B = new int[newSize]; // allocate new memory

    for (int i = 0; i < size; i++)
    {                          // copy values to new array
      B[i] = A[i];
    }

    delete[] A;                // delete old array

    size = newSize;            // save new size

    A = B;                     // reset array pointer
  }

  /**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack by decreasing
  *      its capacity by half
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerShrink()
  {
    int newSize = size / .50;  //decreases size by half
    int *B = new int[newSize]; //allocate new memory

    for (int i = 0; i < top; i++)
    {                           //copy values to new array
      B[i] = A[i];
    }

    delete[] A;                 //delete old array         
    size = newSize;             //save new size
    A = B;                      //reset array pointer
  }

  /**
  * Public bool: CheckResize
  * 
  * Description:
  *     Calculates the ratios then calls the appropriate method to resize 
  *     the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool]: true if there is a change
  */
  bool CheckResize()
  {
    if(top == full)
    {
      ContainerGrow();
      return true;
    }
    else if(top == size/2)
    {
      ContainerShrink();
      return true;
    }
    return false;
  }

  /**
  * Public int: getSize
  * 
  * Description:
  *     returns the size of the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int]: returns the size
  */
  int getSize()
  {
    return size;
  }
};

void openFiles(ifstream& infile, ofstream& outfile);

int fillStack(ifstream& infile, ArrayStack stack, int changes);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
  ifstream infile;            //ifstream object
  ofstream outfile;           //ofstream object
  ArrayStack stack;           //ArrayStack object
  int changes = 0;            //accumlator for changes made to the stack
  
  openFiles(infile, outfile);
  outfile << "###############################################################"
          << "\n\t Assignment 4  - Resizing the Stack\n\t CMPS 3013 \n\t"
          << "Christian Douglas\n\n";
  outfile << "\tMax Stack Size: " << stack.getSize() << '\n';
  changes = fillstack(stack, changes);
  outfile << "\tEnd Stack Size: "<< stack.getSize() << '\n';
  outfile << "\tStack Resized: " << changes << "\n\n";
  outfile << "###############################################################"
          << '\n';
  
  infile.close();
  outfile.close();
  return 0;
}

/**
 * Public : openFiles
 * 
 * Description:
 *        Open the input file and the output file
 * 
 * Params:
 *      [ifstream&]   : infile
 *      [ofstream&]   : outfile
 * 
 * Returns:
 *      [void]
 */
void openFiles(ifstream& infile, ofstream& outfile)
{
  infile.open("nums.dat");
  outfile.open("output.txt");
}

/**
 * Public : fillStack
 * 
 * Description:
 *       Pushes even numbers onto the stack and pops numbers off the stack
 *       if an odd number apears.
 * 
 * Params:
 *      [ifstream&]   : infile
 *      [ArrayStack]  : stack
 *      [int]         : changes
 * 
 * Returns:
 *      [int] changes : returns an accumlator for number of changes to the
 *                      stack
 */
int fillStack(ifstream& infile, ArrayStack stack, int changes)
{
  int num = 0;
  infile >> num;
  while(infile >> num)
  {
    if(num%2 == 0)
    {
      stack.Push(num);
    }
    else
    {
      stack.Pop();
    }
    if(stack.CheckResize() == true)
    {
      changes++;
    }
    return changes;
  }
}