#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int poket = nums.size()/2;
    
    unordered_set<int> kinds;
    
    for(int i = 0; i < nums.size(); i++)
    {
        kinds.insert(nums[i]);
    }
    
    return min((int)kinds.size(),poket);
    
}