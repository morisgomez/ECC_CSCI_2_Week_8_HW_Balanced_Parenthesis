/*
 Program Name: main.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/04/2024
 Version Control: 4.0
 About: Week 8, CSCI 2, HW.
 Description:
 A string of characters has balanced parentheses if each right
 parenthesis occurring in the string is matched with preceding
 left parentheses in the same way that each right brace in a C++
 program is matched with a preceding left brace. Write a program
 that uses a stack to determine whether a string entered at the
 keyboard has balanced parentheses.

 For example:
 ((5+6)*2)) is unbalanced.
 (((7+9)+12)) is balanced.
*/

#include <iostream>
#include <string>
using namespace std;

//create StringStack:
class StringStack
{
private:
    char *stackArray; //does stackArray point to the address of the first element?
    //would we need to derefrence each index to access value?
    long int size;
    long int top;
    
public:
    //CONSTRUCTOR:
    StringStack(long int sz)
    {
        //code for regular array: int name_array[sz];
        size = sz; //initializes the size of the stack array.
        stackArray = new char[sz]; //initializes stack array with a set size of 'size'.
        top = -1; //initializes the top of the stack array to -1.
        //-1 means empty stack array.
    } //end constructor.


//MEMBER FUNCTION #1: push():
    void push(char str)
    {
            top = top + 1; //top becomes new index.
            stackArray[top] = str; //set that new index to num.
   
    } //end push() function.
    
//MEMBER FUNCTION #2: pop():
    void pop()
    {
        top = top - 1;
   
    } //end pop() function.

//MEMBER FUNCTION #3: display():
    void display()
    {
        long int t = top; //last one in, first one out.
        //using while loop to traverse through stack array.
        while(t >= 0)
        {
            cout << "value: " << stackArray[t] << endl;
            t = t - 1;
        } //end while loop.
    } //end display() function.

//MEMBER FUNCTION #3: display():
    bool check()
    {
        //bottom['(', ')', '(', ')']top
        //start at top & go down.
        int closed = 0;
        int open = 0;
        
        long int t = top;
        //using while loop to traverse through stack array.
        while(t >= 0)
        {
            if(stackArray[t] == '(')
            {
                open++;
            }
            else if(stackArray[t] == ')')
            {
                closed++;
            }
            else
            {
                cout << "ERROR IN PROGRAM" << endl;
            }
            t = t - 1;
        } //end while loop.
        
        if(closed == open) //have to match.
        {
            return true;
        }
        else //no match.
        {
            return false;
        }
    } //end check() function.
}; //end StringStack class.
    
//DRIVER for classs StringStack via main function:
int main()
{
    //get string from user:
    string x;
    cout << "Enter string (without space b/w characters): ";
    cin >> x;
    
    //step 1: get size for stack.
    int s = 0;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] == '(' || x[i] == ')')
        {
            s++;
        }
    } //end for loop.
    cout << s << endl;
    
    //step 2: create empty stack with size from step 1.
    StringStack stackOne(s);
    
    //step 3: push all parenthesis to stack.
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] == '(' || x[i] == ')')
        {
            cout << x[i] << endl;
            stackOne.push(x[i]);
        }
    } //end for loop.
    
    //3.check if balanced or not:
    if(stackOne.check()) //if true.
    {
        cout << "Balanced" << endl;
    }
    else //if false.
    {
        cout << "Not Balanced" << endl;
    }
    
    /*
     case study 1: (((7+9)+12)) is balanced = PASSED.
     case study 2: ((5+6)*2)) is not balanced = PASSED.
     */
    
    return 0;
}
