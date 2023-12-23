/*
We need to print all the subsets/subsequences of the given string
Note that subsequence means it need not be contiguous.
However, in subarray, it must be continguous part of the string.
Eg. input="abc"
    output="","a","b","c","ab","bc","ac","abc"

    Note that the order must be maintained ("cb is not allowed")
*/

#include <iostream>
using namespace std;

void print_sub(char *input, char* output, int i, int j)
{
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    
    //including the current alphabet
    output[j]=input[i];
    print_sub(input, output, i+1,j+1);

    //exclude the current alphabet
    //How are we excluding it?
    // Note that j pointer does not move here and so finally,
    //when we encounter '\0',
    //we make the out[j] as '\0'
    //ie, we actually end the character array there


    print_sub(input, output, i+1, j);

    
}

int main()
{
    char input[] = "abcd";
    
    char output[10];
    // testing for string "abc"

    int i=0;
    int j=0;

    print_sub(input, output, i, j);

    return 0;
}