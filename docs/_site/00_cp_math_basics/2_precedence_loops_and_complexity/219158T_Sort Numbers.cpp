#include<iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int x=A,y=B,z=C;
    if(A>B){
        swap(A,B);
    }
    if(B>C){
        swap(B,C);
        if(A>B){
            swap(A,B);
        }
    }
    cout<<A<<endl;
    cout<<B<<endl;
    cout<<C<<endl;
    cout<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    return 0;
}
