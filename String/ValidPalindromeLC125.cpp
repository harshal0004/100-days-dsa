#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string inter="";
        char converter;
        int n = s.length();
        for(int i=0; i<n; i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){

               if(s[i]>=65 && s[i]<=90){
                inter.push_back(s[i]+32);
               }else{
                inter.push_back(s[i]);
               } 
            }

        }

        for(int i=0, j=inter.length()-1; i<j; i++, j--){
            if(inter[i]!=inter[j])
                return false;
        }

        return true;
        
    }
};