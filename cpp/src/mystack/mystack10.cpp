#include<iostream>
using namespace std;
class myStack{
  int *a = nullptr, top=-1, n=0;
 public:
  myStack(){
    top=-1;
    a=new int[n=100];
  }
  void push(int b){
    if(this->isFull()) 
      throw  1; 
    a[++top]=b;
  }
  int pop(){
    if(isEmpty()) 
      throw 2; 
    return a[top--];
  }
  bool isFull()
  {return top==n-1;}
  bool isEmpty()
  {return top==-1;}
  int Top(){
    if(isEmpty()) 
      throw 2; 
    return a[top];
  }
  ~myStack()
  {delete[] a;a=nullptr;n=0;}
  void printAll(){
    cout<<"print all"<<endl;
    for(int i=0;i<=top;i++)
      cout<<a[i]<<endl;
  }
};
void f1(){myStack st1;
  st1.push(2);st1.push(3); 
  st1.push(4);st1.printAll();
  cout<<st1.pop()<<endl;
  cout<<st1.pop()<<endl;
  cout<<st1.Top()<<endl;
  cout<<st1.Top()<<endl;
  st1.printAll();
}
void errorMessage(int errorNumber){
  switch(errorNumber){
    case 1:
      cout<<"Stack is full"<<endl;
    break;
    case 2:
      cout<<"Stack is empty"<<endl;
    break;
    default:
      cout<<"Another error"<<endl;
    break;
  }
}
int main(){
  try{
    f1();
  }catch(int &exc){
    cout<<"Exception ";
    errorMessage(exc);
  }
}
