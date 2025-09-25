#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Below is brute force approach - time complexity O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false; 
        
    }
};

// Below solution I implemented without looking at solution 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            auto itr = um.find(nums[i]);
            
            if(itr==um.end())
                um.insert({nums[i],i});
            
            if(itr!=um.end())
                return true;
        }
        return false;  
    }
};

// Below solution I got to know while exploring different solution using sets