// Below is the brute force solution in O(n^3) I will going to design in O(n^2)

#include<vector>
#include<set>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        
        set<vector<int>> answer;

        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        answer.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> result(answer.begin(), answer.end());
        return result;
        
    }
};