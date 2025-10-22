// https://excalidraw.com/#json=inm5GbvxXNX-SqcdEbZx0,XIdowO6t8FlnX6WueHKjXQ
// Just found a brute force solution for this 

#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximumArea=0,length,breath;
        int n = height.size();
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){

                if(height[i]<height[j]){
                    length=height[i];
                    breath=j-i;
                    maximumArea=max(maximumArea,(length*breath));
                }else if(height[i]>=height[j]){
                    length=height[j];
                    breath=j-i;
                    maximumArea=max(maximumArea,(length*breath));
                }
                
            }
        }

        return maximumArea;
    }
};


// finally I solve the optimal approach for this problem by my self hurray using two pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maximumArea=0,length, breath;
        int i=0, j=n-1;
        while(i<j){
            if(height[i]<height[j]){
                length=height[i];
                breath=j-i;
                maximumArea=max(maximumArea, length*breath);
                i++;
            }else if(height[i]>=height[j]){
                length=height[j];
                breath=j-i;
                maximumArea=max(maximumArea, length*breath);
                j--;
            }
        }

        return maximumArea;
        
    }
};