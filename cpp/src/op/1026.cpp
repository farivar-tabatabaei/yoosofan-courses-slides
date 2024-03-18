#include <iostream>
#include <cmath>
using namespace std;
class complexCls{ 
  double r,i;
 public:
  complexCls(int m=0,int n=0)
  {r=m;i=n;}
  void Show(void) const
  {cout<<r<<"+ i "<<i<<endl;}
  double Magnitude(void) const
  {return sqrt(r*r+i*i);}
  void input(void){
    cout<<"Enter real:"; cin>>r;
    cout<<"Enter imaginary:"; cin>>i;
  }
  complexCls operator+(complexCls b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
  }
  friend complexCls add(
      complexCls a, complexCls b);
};
complexCls add(complexCls a,
    complexCls b){
  complexCls c = a;
  c.r += b.r;
  c.i += b.i;
  return c;
}
void f1(void){
  complexCls a(2, 3), b(2, 1), c(a);
  c = a + b; c.Show();
  c = add(a, b); c.Show();
  c = a.operator+(b); c.Show();
  c = a + b + c; c.Show();
  c = a.operator+(b.operator+(c)); 
  c.Show();
}
int main(){f1();}
