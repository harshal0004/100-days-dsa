// excalic draw link : https://excalidraw.com/#json=YNLaMV1bb6PxVvLqkQgX5,wQyLAGDkKlB1nx_CmD_7Rw


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Below is Brute force solution with time complexity O(n^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // First brute force approach which will in O(n^2)
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

// Below is optimized solution, feeling very happy to solve this using hash map 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mp;
        int compliment;
        for(int i=0; i!=nums.size(); i++){
            compliment=target-nums[i];

            auto it = mp.find(compliment);
            if(it==mp.end()){
                mp.insert({nums[i],i});
            }
            if(it!=mp.end()){
                result.push_back(i);
                result.push_back(mp[compliment]);

            }
            
        }
        return result; 
    }
};