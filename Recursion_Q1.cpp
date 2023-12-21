// Recursive program to insert a star between pair of identical characters
// Example input--"hello"
// Example output--"hel*lo"

#include <bits/stdc++.h>
using namespace std;

string ans = "";

void solution(string input, string& output, int i)
{
    // base case
    if (i >= input.length())
        return;
    ans += input[i];
    if (input[i] == input[i + 1])
    {
        ans += "*";
    }
    i++;
    solution(input,output,i);
}
int main()
{
    string str;
    cin >> str;
    solution(str, ans, 0);
    cout << ans << endl;

    return 0;
}