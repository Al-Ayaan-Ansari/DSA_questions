#include<iostream>
#include <bits/stdc++.h> 
using namespace std;


class Polynomial {
    public:
    int count;
    int * degCoeff=new int {0};

    // Complete the class
    void setCoefficient(int degree,int coeff){
        degCoeff[degree]=coeff;
    }
    Polynomial operator +(Polynomial second){
        for(int i=0;i<sizeof(degCoeff)/sizeof(int)||i<sizeof(second.degCoeff)/sizeof(int);i++){
            second.degCoeff[i]=degCoeff[i]+second.degCoeff[i];

        }
        return second;
    }
    void print(){
        for(int i=0;i<sizeof(degCoeff)/sizeof(int);i++){
            cout<<degCoeff[i]<<' ';
        }
        cout<<endl;
        cout<<degCoeff[1];
    }

};


int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    // case 2:
    //     result = first - second;
    //     result.print();
    //     break;
    //     // Multiply
    // case 3:
    //     result = first * second;
    //     result.print();
    //     break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

}