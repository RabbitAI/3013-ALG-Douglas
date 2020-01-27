/******************************************************************************
 * 
 * Author:            Christian Douglas
 * Email:             cedoug13@aol.com
 * Label:             A02
 * Title:             02-CommentedCode
 * Course:            CMPS 3013
 * Semester:          Spring 2020
 * 
 * Description: 
 *       The program creates a linked list that operates like an array. It
 *       overloads the square brackets to simulate the appearance of accessing
 *       an array, but it actually traverses the list using an index value to 
 *       find a specfic node. The plus sign is also overloaded to be able to 
 *       push new nodes onto the end of the list.  
 *              
 * Usage:
 *      -$ ./main filename
 *      - reads into our list the values from a file. 
 * Files:     
 *      main.cpp     : driver program
 *****************************************************************************/
#include <iostream>

using namespace std;

int A[100];         //Global array with size of 100

/**
 * Node
 * 
 * Description:
 *       Allows a node to be created for a linked list
 * 
 * Public Methods:
 *                  Node()
 *                  Node(int n)   
 */
struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description: 
 *        The class creates a linked list that acts like an array.
 * 
 * Private Methods:
 *      none
 * Public Methods:
 *                  List()
 *      void        Push(int val)
 *      void        Insert(int val)
 *      void        PrintTail()
 *      string      Print()
 *      int         Pop()
 *      List        operator+(const List &Rhs)
 *      int         operator[](int index)
 *      ostream     &operator<<(ostream &os, List L)
 */
class List {
private:
    Node *Head;         //Head pointer for beginning list
    Node *Tail;         //Tail pointer for end of list
    int Size;           //Holds the number of nodes in the list

public:
    /**
     * Public : List
     * 
     * Description:
     *      default constructor
     * 
     * Params: 
     *       none
     * Returns:
     *        void  :   returns nothing
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Adds a new node to the end of a list
     * 
     * Params: 
     *       int    :   val
     * Returns:
     *        void  :   returns nothing
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public : Insert
     * 
     * Description:
     *      Inserts a node
     * 
     * Params: 
     *       int    :   val
     * Returns:
     *        void  :   returns nothing
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public : PrintTail
     * 
     * Description:
     *      Prints the node at the end of the list
     * 
     * Params: 
     *       none
     * Returns:
     *        void  :   returns nothing
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public : Print
     * 
     * Description:
     *      Prints the entire list
     * 
     * Params: 
     *       none
     * Returns:
     *        string    :   returns each node as a string
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      decrements the Size variable
     * 
     * Params: 
     *       none
     * Returns:
     *        int   :   returns 0
     */
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * Public : operator+
     * 
     * Description:
     *      overloads the plus sign to push a value on the list
     * 
     * Params: 
     *       const List    :    List object
     * Returns:
     *        List         :    allows the plus sign to be overloaded
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public : operator[]
     * 
     * Description:
     *      overloads the square brackets to have the list simulate an array
     * 
     * Params: 
     *       int    :   indexes each node
     * Returns:
     *       int    :   allows the list to simulate an array and index each
     *                  node
     */
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * friend : operator<<
     * 
     * Description:
     *      overloads the double left angle brackets to print list
     * 
     * Params: 
     *       ostream    :   object of the output stream
     *       List       :   object of List class
     * Returns:
     *       ostream    :   gives the List class the ability to print nodes
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

/**
 * Public : main
 * 
 * Description:
 *       main function of the program 
 * 
 * Params: 
 *       int    :   number of arguments 
 *       char** :   contains the addresses of the arguments
 * Returns:
 *        int   :   returns whether the program executes successfully
 */
int main(int argc, char **argv) {
    List L1;            //List's first object
    List L2;            //List's second object

    //pushes values onto L1's list
    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }
    //pushes values onto L2's list
    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    //prints the last value of L1
    L1.PrintTail();
    //prints the last value of L2
    L2.PrintTail();

    //values the two list and puts it in a third list
    List L3 = L1 + L2;
    //prints L3
    cout << L3 << endl;
    //prints the fifth node in L3's list
    cout << L3[5] << endl;
    return 0;
}