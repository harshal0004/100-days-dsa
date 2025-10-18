// https://excalidraw.com/#json=YAFQO2Rm294PGHpTJ8DZZ,bL8EBd_G1JMUYnSrnzyE6w

#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int minProduct = nums[0];        // min product ending at current index
        int maxProduct = nums[0];        // max product ending at current index
        int maxProductSoFar = nums[0];   // global maximum product

        for(int i = 1; i < nums.size(); i++) {
            int curr = nums[i]; //3 -4

            // store previous maxProduct before updating
            int tempMax = maxProduct; //-2 3 

            // update maxProduct and minProduct considering current number
            maxProduct = max(curr, max(curr * maxProduct, curr * minProduct)); //3 24
            minProduct = min(curr, min(curr * tempMax, curr * minProduct)); //-6 -12

            // update global max
            maxProductSoFar = max(maxProductSoFar, maxProduct); // 3 24
        }

        return maxProductSoFar;
    }
};
