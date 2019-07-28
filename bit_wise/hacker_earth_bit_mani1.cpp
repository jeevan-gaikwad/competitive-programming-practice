/*
Problem statement:
He gave him a string of length N, more precisely a “binary string”, consisting of only 0’s and 1’s. He asked him to find all the strings generated from N left rotations one character at a time. For example if S is "101", then the strings generated from left rotations will be “011”, ”110” and ”101”. Out of the generated N strings, he asks the number of strings having even decimal value.
*/
//Following solution is a raw, first habd naive solution. 
//Efficient solution is: Just count the number of zeros in the input string
// Write your code here
#include<iostream>
#include<bits/stdc++.h>
#include<string>

int main(void)
{
    int noOfInputs;
    std::cin>>noOfInputs;
    for(int i=0; i< noOfInputs; i++) {
        int noOfBits;
        std::cin>>noOfBits;
        std::string binaryRepresentation;
        std::cin>>binaryRepresentation;
        unsigned long long number = std::stoull(binaryRepresentation,0,2); //base is 2
		std::cout<<"Scanned:"<<number<<std::endl;
        //std::bitset<10> number(binaryRepresentation);
        int noOfEvenNumbers = 0;
        for(int j=0; j<noOfBits ; j++) { //iterations would be noOfBits -1. i.e. No of strings
            number = ((number<<1)|(number >> (noOfBits - 1))); //left rotate by 1
            if(!(number&1)) {
                noOfEvenNumbers++;
            }
        }
        std::cout<<noOfEvenNumbers<<std::endl;
    }
    return 0;
}
