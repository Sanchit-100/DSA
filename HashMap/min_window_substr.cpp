/*
Q. Find the shortest substring that contains all the characters of another given pattern string
Eg. s="this is amazing"
    p="isa"
    ans="is a"

NOTE: We do this by sliding window technique

*/


#include <iostream>
#include <string>
#include <climits>
using namespace std;

string min_window(string s, string p)
{

    //corner case
    //If the length of pattern is greater than string
    //, then obviously nothing is possible.\

    if(s.length()<p.length()){
        return "None";
    }

    //We take 2 pointers i and min_start which will enclose the final substring
    //"cnt" is actually measuring how many chars of pattern have been covered in the q_string


    //min_window is the length of the min_valid_substring encountered so far

    int min_start=-1;
    int cnt = 0;
    int start = 0;
    int min_window = INT_MAX;


    //Two frequency arrays, holding the frequencies of each char in str and pat
    //Note that when we write arr['a']=13,
    //it actually means arr[97]=13

    //So, essentially we can index the arr with chars as well
    //This behaves as a map between char and an integer(frequency)

    int *freq_str = new int[256];
    int *freq_pat = new int[256];
    
    //initializing both the freq maps with all 0 frequencies

    for(int i=0;i<256;i++){
        freq_pat[i]=0;
    }

    for(int i=0;i<256;i++){
        freq_str[i]=0;
    }

    //putting the required frequencies in the freq map of pattern
    for (int i = 0; i < p.length(); i++)
    {
        freq_pat[p[i]]++;
    }


    //iterating the question string
    for (int i = 0; i < s.length(); i++)
    {   
        //checking if the character encountered is required or not
        //if required, cnt++

        if (freq_str[s[i]] < freq_pat[s[i]])
        {

            cnt++;
        }
        freq_str[s[i]]++;

        //checking if the covered string is a valid sub_string
        if (cnt == p.length())
        {

            // start contracting from left
            //we alreday have a valid one, just trying to make it shorter
            while ((freq_pat[s[start]] == 0) || (freq_pat[s[start]] < freq_str[s[start]]))
            {
                freq_str[s[start]]--;
                start++;
            }

            //updating the min_length of window
            int window_len = i - start + 1;

            if (min_window > window_len)
            {
                min_window = window_len;
                min_start=start;
            }
        }

    }

    if(min_start==-1){
        return "None";
    }
    
    //substr function accepts arguments- the start and its length
    //returns the substring
    string ans=s.substr(start,min_window);
    return ans;
}

int main()
{
    string p = "eelo";
    string s = "hello_werld";
    cout << min_window(s, p) << endl;

    return 0;
}