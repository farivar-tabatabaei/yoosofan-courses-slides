#include<iostream>
using namespace std;
class complexCls{
  double re=0,img=0;
 public:
  complexCls(double r=0,double i=0):re(r), img(i){}
  double getRe(void){return re;}
  double getImg(void){return img;}
};
struct myClass2{
  double x;
  complexCls c;
  myClass2(double x, double g):c(x, g)
  { this->x = x; }
};
void f1(void){
  complexCls c1(12, 14);
  cout << c1.getRe() << endl;
}
int main(){f1();}
