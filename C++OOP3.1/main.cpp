#include <iostream>
using namespace std;
class Overcoat{
    string type;
    int size;
    int price;
public:
    Overcoat(){
        type = "object";
        size = 0;
        price = 0;
    }
Overcoat(string type,int size,int price) : type(type),size(size),price(price){}


    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            size = other.size;
        }
        return *this;
    }




friend ostream & operator << (  ostream&out,const Overcoat & p1);

friend bool operator==(const Overcoat&p1,const Overcoat &p2);
friend bool operator > (const Overcoat& p1,const Overcoat&p2);
};

bool operator > (const Overcoat& p1,const Overcoat&p2){
    if(p1.type == p2.type){
        return p1.price > p2.price;
    } else{
        return 0;
    }

}
bool operator==(const Overcoat&p1,const Overcoat &p2){
    return p1.type == p2.type;
}

ostream & operator << (  ostream&out,const Overcoat & p1){

    out << "size : " << p1.size << endl;

    return out;
}

//===============================================================================================



class Flat{

    int area;
    int price;

public:

    Flat(){


        area = 0;
        price = 0;
    }


    Flat(int area,int price) :area(area),price(price){}


    Flat& operator=(const Flat& other) {
        if (this != &other) {

            area = other.area;
        }
        return *this;
    }
    void setShow (){
        cout << "PRICE :" << price << endl;
        cout << "Area : " << area << endl;

    }



    friend ostream & operator << (  ostream&out,const Flat & p1);

    friend bool operator==(const Flat&p1,const Flat &p2);
    friend bool operator > (const Flat& p1,const Flat&p2);


};



bool operator > (const Flat& p1,const Flat&p2){

        return p1.price > p2.price;


}

bool operator==(const Flat&p1,const Flat &p2){
    return p1.area == p2.area;
}



ostream & operator << (  ostream&out,const Flat & p1){

    out << "area : " << p1.area << endl;

    return out;
}

int main() {
    cout << "-------Overcoat------- " << endl;

    Overcoat p1("Shorts",10,200);
    Overcoat p2("gince",10,400);
    Overcoat p3("Shorts" ,40,566);

    bool p4 = p3 > p1;
    cout << p4 << endl;

    p1 = p3;
    cout << p1;



    bool TrueFalse = p1 == p3;
    cout << TrueFalse << endl;

//=================================================================
cout << "-------FLAT------- " << endl;
    Flat f1(45,500);
    Flat f2(45,300);
    bool a = f1==f2;
    cout << a << endl;
    f1 = f2;
    cout << f1 << endl;
    bool b = f1>f2;
    cout << b << endl;

}
