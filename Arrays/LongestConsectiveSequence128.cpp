// Excalic link : https://excalidraw.com/#json=qjDsAOEqaTU8m3oYx2nCL,usNgmUpiXij8kj3x125YNA
// below is my version of writting code, I spent 3-4 hours to get this approach still it not optimal and code writting need to improve , Complexity O(nlogn)
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        vector<int> v = nums;
        sort(v.begin(), v.end());
        int counter=0, i=0, j=i+1;
        vector<int> result;


        for(i,j; j<v.size(); i++, j++){
            if(v[j]-v[i]==1)
                counter++;
            else if(v[j]-v[i]==0)
                continue;
            else if(j<v.size() && i>0 && v[j]-v[i]>1 && ((v[i]-v[i-1]==1 || v[i]-v[i-1]==0) || v[j]-v[i]==1)){
                result.push_back(counter+1);
                counter=0;
            }
        }

        if(counter>0){
            result.push_back(counter+1);
        }

        if(i>0 && v[i]-v[i-1]==1)
            result.push_back(counter+1);
        
        if(result.empty())
            return counter+1;
        
        return *max_element(result.begin(), result.end());
        
    }
};

// Clean readable chatgpt version based on my logic

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Sort the array
        sort(nums.begin(), nums.end());

        int max_length = 1;      // Tracks the longest consecutive sequence
        int current_length = 1;  // Tracks the current consecutive sequence

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                // Consecutive number found
                current_length++;
            } else {
                // Sequence broken, update max_length
                max_length = max(max_length, current_length);
                current_length = 1; // Reset for new sequence
            }
        }

        // Handle the last sequence
        max_length = max(max_length, current_length);

        return max_length;
    }
};


