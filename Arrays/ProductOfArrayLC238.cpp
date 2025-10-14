// this is brute force solution solved just in 15 mins, now looking for optimized one
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result;
        int product=1;

        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i==j)
                    continue;
                
                product=product*nums[j];
            }
            result.push_back(product);
            product=1;
        }

        return result;
        
    }
};