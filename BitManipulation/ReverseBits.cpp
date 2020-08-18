#include<bits/stdc++.h>

using namespace std;

void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

unsigned int reverseBits(unsigned int num) 
{ 
    unsigned int count = sizeof(num) * 8 - 1; 
    unsigned int reverse_num = num; 
      
    num >>= 1;  
    while(num) 
    { 
       decToBinary(reverse_num);
       cout<<" ";
       decToBinary(num);
       cout<<endl;
       reverse_num <<= 1;        
       reverse_num |= num & 1; 
       num >>= 1; 
       count--; 
    } 
    reverse_num <<= count; 
    decToBinary(reverse_num);
    cout<<endl;
    return reverse_num; 
} 
  
int main() 
{ 
    unsigned int x = 50; 
    cout<<"50 in binary is ";
    decToBinary(50);
    cout<<endl;
    printf("%u", reverseBits(x)); 
    //getchar(); 
} 