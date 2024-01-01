#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 1;
    while (nums.size() >= i)
    {
        if (nums[i] == nums[i - 1])
        {
            nums.erase(nums.begin() + i);
        }
        else
            i++;
    }

    return nums.size();
}

    int main()
    {

        vector<int> nums = {0, 0, 1, 1, 1, 2, 2};
        removeDuplicates(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
    }
