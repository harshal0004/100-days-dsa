#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// This solution is brute force yet it took me 2 days on average to solve, but I am happy I solved all by self
// with minimal help from chatgpt and now I will go for optimized solution as well.

class Solution {
public:

    bool isAlreadyGrouped(const string &word, vector<vector<string>> &result){
        for(auto &group:result){
            for(auto &w:group){
                if(w==word) return true;
            }
        }
        return false;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        vector<string> sortStrs = strs;
        for(int i=0; i<sortStrs.size(); i++){
            sort(sortStrs[i].begin(), sortStrs[i].end());
        }

        for(int i=0;i<sortStrs.size(); i++){
            if(isAlreadyGrouped(strs[i], result)){
                continue;
            }

            vector<string> group;
            group.push_back(strs[i]);

            for(int j=i+1; j<sortStrs.size(); j++){
                if(sortStrs[i]==sortStrs[j]){
                    group.push_back(strs[j]);
                }
            }
            result.push_back(group);
            
        }

        return result;
        
    }
};