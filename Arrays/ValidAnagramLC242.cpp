#include <iostream>
#include <unordered_map>
using namespace std;


// Below is the solution which I initally thought and implement quickly but it not pass all the test cases 
// only 43/50 is being passed below is the bad solution 
/*
class Solution {
public:
    bool isAnagram(string s, string t) {

        int inputSum=0, targetSum=0;

        for(int i=0; i<s.length(); i++){
            inputSum=inputSum+s[i];
        }

        for(int i=0; i<t.length(); i++){
            targetSum=targetSum+t[i];
        }

        if(inputSum==targetSum)
            return true;
        return false;
        
    }
};
*/

// Below is the solution which I build by myself without taking any help

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um1,um2;

        for(int i=0; i<s.length(); i++){
            if(um1.find(s[i])!=um1.end()){
                um1[s[i]]++;
            }else
                um1.insert({s[i],1});
        }

        for(int i=0; i<t.length(); i++){
            if(um2.find(t[i])!=um2.end()){
                um2[t[i]]++;
            }else 
                um2.insert({t[i],1});
        }

        if(um1==um2)
            return true;
        else 
            return false;
        
    }
};

// Below is the solution seek out by taking help 

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> um1,um2;

        for(char c:s){
            um1[c]++;
        }
        for(char c:t){
            um2[c]++;
        }

        if(um1==um2)
            return true;
        else
            return false;
        
    }
};