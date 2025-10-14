
// https://excalidraw.com/#json=CiYxLc12InHZ2v9fCl--J,ucVNnpJ0MCNwdWRAn7xtVQ
// This is brute force solution, giving me error memory exceed
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1)
            return 0;

        vector<int> profits;
        int diff, max=0;

        for(int i=0; i<prices.size()-1; i++){
            for(int j=i+1; j<prices.size(); j++){
                diff=prices[j]-prices[i];
                profits.push_back(diff);
            }
        }

        if(profits.size()>0)
            max = *(max_element(profits.begin(), profits.end()));

        if(max>0)
            return max;
        
        return 0;
        
    }
};

// this is also brute force but refined solution but now giving time limit exceed 

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int diff, max=0;

        for(int i=0; i<prices.size()-1; i++){
            for(int j=i+1; j<prices.size(); j++){
                diff=prices[j]-prices[i];
                if(diff>max)
                    max=diff;
            }
        }

        if(max>0)
            return max;

        return 0;
        
    }
};

// Tried so many approaches then i came to below code to solve in O(n) but it failing for few testcases
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty() || prices.size()==1)
            return 0;

        pair<int,int> minContainer;
        int j, max=0, diff;
        minContainer.first=0;
        minContainer.second=prices[0];
        int min=prices[0], index;

        for(int i=1; i<prices.size(); i++){
            if(prices[i]<min){
                minContainer.first = i;
                minContainer.second = prices[i];
                min=prices[i];
            }
               
        }

        j=minContainer.first+1;

        while(j<prices.size()){
            diff=prices[j]-minContainer.second;
            if(diff>max)
                max=diff;
            j++;
        }

        if(max>0)
            return max;
        
        return 0;
        
    }
};


// Finally after so many tries I got to the below solution by taking hints from chatgpt uff

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty() || prices.size()==1)
            return 0;
            
        int min_price=prices[0];
        int max_profit=0,diff;

        for(int i=1; i<prices.size(); i++){
            if(prices[i]<min_price){
                min_price=prices[i];
                continue;
            }

            diff=prices[i]-min_price;
            
            if(diff>max_profit)
                max_profit=diff;
                   
        }

        return max_profit;
        
    }
};