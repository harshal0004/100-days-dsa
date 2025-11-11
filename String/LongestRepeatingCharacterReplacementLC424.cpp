// https://excalidraw.com/#json=RweNU7Df7Fl02zGAf0Tt6,tQShVDMs9hecNskRtkX5uw
// somehow got the brute force approach
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

// somehow solve using optimal approach of sliding window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26,0);
        int l=0, r=0, maxFreq=0,changes,maxLen=0;

        while(r<n){
            freq[s[r]-'A']++;
            // maxFreq=*max_element(freq.begin(), freq.end()); my approach but little costly
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            int len=r-l+1;
            changes=len-maxFreq;

            if(changes<=k){
                maxLen=max(maxLen,len);
                r++;
            }else{
                freq[s[l]-'A']--;
                l++;
                r++;
            }
                
        }

        return maxLen;

        
    }
};