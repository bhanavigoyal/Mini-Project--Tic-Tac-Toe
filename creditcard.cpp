//Luhn Algorithm
//sum of odd placed digits + 2*sum of even placed digits should be divisible
//by 10

#include<iostream>

int main(){

    long cardNum;
    std::cout<<"Enter the card number: "<<std::endl;
    std::cin>>cardNum;

    int sumOdd=0;
    int sumEven=0;

    long temp=cardNum;

    while(temp>0){
        int lastDigit = temp%10;
        sumOdd+=lastDigit;
        temp/=100;
    }

    cardNum/=10;
    while(cardNum>0){
        int lastDigit=cardNum%10;
        int doubleDigit = lastDigit*2;
        int last=doubleDigit%10;
        int first = doubleDigit/10;
        int sum = last+first;
        sumEven+=sum;
        cardNum/=100;
    }

    int sumDigits = sumOdd+sumEven;
    if(sumDigits%10==0){
        std::cout<<"The card is valid"<<std::endl;
    }
    else{
        std::cout<<"Invalid Card Number. Please try again"<<std::endl;
    }
    return 0;
}