//  TOWER OF HANOI USING RECURSIONS
/*The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
No disk may be placed on top of a smaller disk. */

#include <iostream>
using namespace std;
void towers(int, char, char, char);

int main()
{
    int num;

    cout<<"Enter the number of disks : ";
    cin>>num;
    cout<<"The sequence of moves involved in the Tower of Hanoi are :n";
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char from, char to, char aux)
{
    if (num == 1)
    {
        cout<<"n Move disk 1 from peg "<<from<<" to peg "<<to;
        return;
    }
    towers(num - 1, from, aux, top);
    cout<<"n Move disk "<<num<<" from peg "<<from<<" to peg "<<top;
    towers(num - 1, aux, top, from);
}
