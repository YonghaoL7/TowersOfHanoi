#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> t[3]; //Three towers A,B,C represented as an array of 3 vectors
    //Move counts the move number
    //Candidate refers to the ring that is being moved
    int n, candidate, to, from, move = 0; 
    cout << "Please enter a number of rings to move: ";
    cin >> n;
    cout << endl;

    //Initialize the 3 towers
    for(int i = n + 1; i >= 1; i--)
    {
        t[0].push_back(i);
    }
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    //Initialize towers and candidate
    from = 0;
    if(n % 2 == 1) 
    {
        to = 1;
    } 
    else
    {
        to = 2;
    }
    candidate = 1;

    while(t[1].size() < n + 1){ //There are still rings to transfer to tower B = t[1]
        //Writing
        cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
        t[to].push_back(t[from].back());//Add the ring
        t[from].pop_back();//Remove the ring
        /*Moves the disks around
        1. Push the top of the "from" tower to the "to" tower
        2. Remove the ring from the "from" tower
        */
       //Get next "from tower" 
       if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) //Find which has the smallest ring at the top
       {
        from = (to + 1) % 3; 
       }
       else
       {
        from = (to + 2) % 3;
       }
       //Get next "to tower"
       if(n % 2 == 1)
       {
            if(t[from].back() < t[(from + 1) % 3].back()) //Compares the tower to the right
            {
                to = (from + 1) % 3;
            }
            else 
            {
                to = (from + 2) % 3;
            }
       }    
       else
       {
            if(t[from].back() < t[(from + 2) % 3].back()) //Compares the tower to the left
            {
                to = (from + 2) % 3;
            }
            else
            {
                to = (from + 1) % 3;
            }
       }
       //Candidate is on the top of the current "from tower"
       candidate = t[from].back();
    }
}