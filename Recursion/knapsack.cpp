#include<iostream>
using namespace std;

//Recurrence relation
// profit(n,c) = max{pr[n]+profit(n-1,c-wt[n]),
//                             profit(n-1,c)}


int profit(int n, int c, int wt[], int pr[]){

    //base case
    if(n==-1 || c==0) return 0;

    int op1=0;
    int op2=0;

    //One option is to include the nth item
    //Can do so only if capacity permits it.

    if(wt[n]<=c){
        op1=pr[n]+profit(n-1,c-wt[n],wt,pr);
    }

    //Another option is to simply exclude the nth item
    // and move on with the remaining options

    op2=profit(n-1,c,wt,pr);

    //finally, we try to maximise from both thee options

    return max(op1,op2); 
}

int main(){
    int weights[]={1,2,3,5};
    int prices[]={40,20,30,100};

    cout<<profit(3,7,weights,prices)<<endl;
    //testing for the test case with capacity=7



    return 0;
}