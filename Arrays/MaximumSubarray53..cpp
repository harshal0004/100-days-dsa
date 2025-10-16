// uff this I direclty manage to solve in optimized way in O(n)

#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=nums[0];
        int maxSum=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            sum=max(nums[i],sum+nums[i]);
            maxSum=max(maxSum, sum);

        }
        
        return maxSum;
    }
};