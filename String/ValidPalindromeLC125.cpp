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

// space optimized 

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0, j=n-1;
        while(i<j){

            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
                if(s[i]>=65 && s[i]<=90){
                    s[i]=s[i]+32;
                }
            }else{
                i++;
                continue;
            }

            if((s[j]>=65 && s[j]<=90) || (s[j]>=97 && s[j]<=122) || (s[j]>=48 && s[j]<=57)){
                if(s[j]>=65 && s[j]<=90){
                    s[j]=s[j]+32;
                }
            }else{
                j--;
                continue;
            }

            if(s[i]==s[j]){
                i++;
                j--;
            }else
                return false;
        
        }

        return true;
        
    }
};

// Most optimized and clean version of code 

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0, j=n-1;
        
        while(i<j){

            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i])!=tolower(s[j])) return false;
            i++; j--;

        }

        return true;
        
    }
};