// https://excalidraw.com/#json=mDioabagSgk1pB89HQwoe,HPtdhOQJMQIYjJ2OhglXXA

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

// Finally i solve the problem myself after taking prefix product and suffix product calculation from chatgpt
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result, prefix, suffix; 
        int productPrefix, productSuffix, suffixIter=0;

        for(int i=0; i<nums.size(); i++){
            if(i==0)
                prefix.push_back(1);
            if(i>0){
                productPrefix=nums[i-1]*prefix[i-1];
                prefix.push_back(productPrefix);    
            }
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(i==nums.size()-1)
                suffix.push_back(1);
             
            if(i<nums.size()-1){
                productSuffix=nums[i+1]*suffix[suffixIter];
                suffix.push_back(productSuffix); 
                suffixIter++;
            }
            
        }

        reverse(suffix.begin(), suffix.end());

        for(int i=0; i<nums.size(); i++){
            result.push_back(prefix[i]*suffix[i]);
        }

        return result;
        
    }
};


// Finally I found this clean solution 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result;
        int suffix =1;
        // first loop to calculate prefix and store in result

        for(int i=0; i<nums.size(); i++){
            if(i==0)
                result.push_back(1);
            if(i>0){
                result.push_back(nums[i-1]*result[i-1]);
            }
        }

        // second for loop is for calculate suffix and then multiply with prefix store in result

        for(int i=nums.size()-1; i>=0; i--){
            result[i]=result[i]*suffix;
            suffix=suffix*nums[i];

        }


        return result;
        
    }
};