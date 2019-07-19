/*#include<iostream>

using namespace std;

void tranform_every_int(int * v, unsigned n, int (*fp)(int))
{
  for (unsigned i = 0; i < n; ++i)
  {
    v[i] = fp(v[i]);
  }
};

int double_int(int x) 
{ 
    return 2*x; 
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    tranform_every_int(&a[0], 5, double_int);
    for (int i=0; i<sizeof(a)-1; i++)
    {cout<<a[i]<<"\n";}
    return 0;
}
*/

#include <iostream>
#include<vector>

using namespace std;


//1 Idea one is to define a function here which will be called back into the julia.

string word() {
    string cpp_word="Hello";
    return cpp_word;
}

//2 The next idea is to call the word directly into Julia from the class but then Julia will call back C++ and then the same C++ file will be calling back the Julia function. I am unable to understand why do we want the same file to do the call back as well as be the library from which Julia is also calling.

class basetest
{
public:
    virtual void word()
    { cout<<"Prototype\n";}
};

class forJulia
{
public:
    void (basetest::*Wordptr)()=nullptr;
    set_julia_fn_ptr(void(*julia_fn_ptr)());
    juliaptr=julia_fn_ptr;
    
    julia_word();
    juliaptr();
    
};
    

/*using namespace std;
int main()
{
    string word;
    cout<<"Enter Word:";
    cin>>word;
    cout<<word<<"\n";
    return 0;
}*/
