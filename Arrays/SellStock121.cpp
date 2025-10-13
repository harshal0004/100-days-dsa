
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