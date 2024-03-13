#ifndef SET_GAME_
#define SET_GAME_
#include <string>
using std::string;

class Set
{
private:
    int num;
    int filling;
    string color;
    string shape;
public:
    Set(/* args */)=default;
    Set(int num1,int fill,string col,string sh):num(num1),filling(fill),color(col),shape(sh){}
    ~Set()=default;
    int getN()const;
    int getF()const;
    string getC()const;
    string getS()const;
};








#endif