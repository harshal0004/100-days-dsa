// somehow got the brute force approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int ans=0;
    
        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j]-'A']++;
                int maxFreq=*max_element(freq.begin(), freq.end());
                int len=j-i+1;
                int changes=len-maxFreq;

                if(changes<=k)
                    ans=max(ans,len);

                

            }
        }

        return ans;

        
    }
};