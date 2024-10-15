#include<iostream>

using namespace std;

class ComplexNumbers {
    public:
    int real;
    int img;
    ComplexNumbers(int real=0,int img=0){
        this->real=real;
        this->img=img;
    }
    void plus(ComplexNumbers c2){
        int val1=this->real+real;
        int val2=this->img+img;
        cout<<real<<endl;
        cout<<this->real<<endl;
        this->real=val1;
        this->img=val2;
    }
    void multiply(ComplexNumbers c2){
        int val1=this->real*real-this->img*img;
        int val2=this->img*real+this->real*img;
        this->real=val1;
        this->img=val2;
    }
    void print(){
        cout<<this->real<<" + i"<<this->img<<endl;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }
    cout<<c1.real<<endl;
    cout<<c1.img;

}
