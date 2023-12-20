#include<iostream>
#include<stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int mod(int a, int b){ //for calculating modulus
    int x=floor(a/b);
    int y=a-(x*b);
    if (y < 0) {
        y += b;
    }
  return y;
}


int modInverse(int a, int m)                              // function to calculate modulus a^-1 in inverse function 
{ 
    for (int x = 1; x < m; x++) {
        if (((a % m) * (x% m)) % m == 1) {
            return x;
        }  
    }
      return 0;       
} 

string numberstoletters(int n,string s){                // convert numbers that resulted numbers from inverse function of deciphering into characters 
    string charachters=s;
    string x;
    x=(char)charachters[n];
    return x;
}

string decipher(string s,int a,int b){              //function to convert given string to numbers according to its postion in the string characters 
    string capital=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //string if given string is all contains capital letters only
    string small=" abcdefghijklmnopqrstuvwxyz";   //string if given string contains smalll letters only 
    string mixed=" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:',.<>/?~"; //string if given string contains mixed characters 
    string output="";
    int z;
    bool has_upper = false;                       //flag to indicate if given string contains capital letter 
    bool has_lower = false;                       //flag to indicate if given string contains lower letter 
    bool has_digits = false;                      //flag to indicate if given string contains digits 
    bool has_punctuation = false;                 //flag to indicate if given string contains punctuation 

    for (char c : s) {                            //loop to check if string contains capital or small or digit or puncution letters 
        if (std::isupper(c)) {  
            has_upper = true;                     // and update flags that defined above
        } else if (std::islower(c)) {
            has_lower = true;
        } else if (std::isdigit(c)) {
            has_digits = true;
        } else if (std::ispunct(c)) {
            has_punctuation = true;
        }
    }
    if ((has_upper || has_lower) && (has_digits || has_punctuation)) {  // check flags if given string contain letters and digits or punction use mixed string
        z=modInverse(a,mixed.length()); 
        for(int i=0; i<s.length();i++){                                // we loop through all characters in passed string and give each one of them a number according to its 
            for(int j=0; j<mixed.length();j++){                       //postion in mixed string
               if(s[i]==mixed[j]){
                    int y=(z*(j-b));                                 // f=(a^-1)(y-b)
                    int x=mod(y,mixed.length());                    // do result mod 92 which is length of string included alphabets and digits and some special characters
                    output+=numberstoletters(x,mixed);
                    break;
            }
       }
    }
    return output;
  } 
     else if (has_upper) {                                                 //check flag if given string contains capital letters only use capital string
          z=modInverse(a,capital.length()); 
        for(int i=0; i<s.length();i++){                                  // we loop through all characters in passed string and give each one of them a number according to its 
            for(int j=0; j<capital.length();j++){                       //postion in charachters string
               if(s[i]==capital[j]){
                    int y=(z*(j-b));                                   // f=(a^-1)(y-b)
                    int x=mod(y,capital.length());                    // do result mod 92 which is length of string included alphabets and digits and some special characters
                    output+=numberstoletters(x,capital);
                    break;
            }
       }
    }
      return output;
        
    } 
      else if (has_lower) {                                    //check if given string contains only a small letters only use small string
        z=modInverse(a,small.length()); 
          for(int i=0; i<s.length();i++){                    // we loop through all characters in passed string and give each one of them a number according to its 
            for(int j=0; j<small.length();j++){             //postion in charachters string
               if(s[i]==small[j]){
                    int y=(z*(j-b));                       // f=(a^-1)(y-b)
                    int x=mod(y,small.length());          // do result mod 92 which is length of string included alphabets and digits and some special characters
                    output+=numberstoletters(x,small);
                    break;
            }
       }
    }
     return output;  
    }
     else {
        return "INVALID";                            // For an empty string or other invalid cases
    }
}



int main()
{   
    string given="ELYPCOGLIOGOXOQTGXDF";   // message given to be diciphered
    string small="elypcogliogoxoqtgxdf";
    string x,y;                           //string to store the deciphered message
    x=decipher(given,7,7);               //call the decipher function and pass to it given message and keys as a=7 ,b=7 
    y=decipher(small,7,7);
    cout<<x<<endl<<y;    
}