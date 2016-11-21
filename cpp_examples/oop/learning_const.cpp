#include <iostream>
using namespace std;
#include <vector>

// http://stackoverflow.com/questions/15999123/const-before-parameter-vs-const-after-function-name-c

struct ConstLearn_struct
{
    void foo() const // <== The implicit "this" pointer is const-qualified!
    {
        _x = 42; // ERROR! The "this" pointer is implicitly const
        _y = 42; // OK (_y is mutable)
    }

    void bar(ConstLearn_struct& obj) const // <== The implicit "this" pointer is const-qualified!
    {
        obj._x = 42; // OK! obj is a reference to non-const
        _x = 42; // ERROR! The "this" pointer is implicitly const
    }

    void zoo(ConstLearn_struct const& obj) // <== The implicit "this" pointer is NOT const-qualified!
    {
        obj._x = 42; // ERROR! obj is a reference to const
        obj._y = 42; // OK! obj is a reference to const, but _y is mutable
        _x = 42; // OK! The "this" pointer is implicitly non-const
    }

    int _x;
    mutable int _y;
};

//  Another explanantion 
// ----------------------------
// class C {
//   void f(int x);
//   };
// is the same as :
// void f(C* this, int x);
// ----------------------------
// Now, if you declare it this way:
// void f(int x) const;
// It's as if you wrote this:
// void f(const C* this, int x);  

// ****  This is implicit in c++

//---------------------------------------------------------
//ANother
//1. int const f() is equivilent to const int f(), which means the return type is const
// class A
// {
// public:
//   void Const_No();   // nonconst member function
//   void Const_Yes() const; // const member function
// };


// //-----------

// A  obj_nonconst;  // nonconst object
// obj_nonconst.Const_No();  // works fine
// obj_nonconst.Const_Yes(); // works fine

// const A obj_const = A(); // const object
// obj_const.Const_Yes(); // works fine (const object can call const function)
// obj_const.Const_No();  // ERROR (const object cannot call nonconst function)
//---------------------------------------------------------

//---------------------------------------------------------
// These 2 are teh same
// const char * getString()
// {
//  const char *x = "abcstring";
//  return x;
// }

// const char * getString()
// {
//  return  "abcstring";  // rememeber it is returned as a pointer to the string
//  
// }
// Careful, string literals are const - A literal is like "abcd"
// Why is const used: So later on it is not altered: always return string as a constant
//---------------------------------------------------------

// ----------------------------------------------------
// Assume method3 to be memeber of class 
// Then what does this mean:
// const int*const Method3(const int*const&)const; 
// == where the 5 uses ‘const’ respectively mean that the variable pointed to by the returned 
// pointer & the returned pointer itself won’t be alterable and that the method does 
// not alter the variable pointed to by the given pointer, the given pointer
//  itself & the object of which it is a method!.


int main(){
	ConstLearn_struct X,Y;
	X.foo();
	X.bar(Y);
	X.zoo(Y);


	return 0;
}