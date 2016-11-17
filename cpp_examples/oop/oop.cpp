#include <iostream>
using namespace std;
#include <vector>

// static and virtual functions
// templates
// copy, constructors, destructors
// queue, stack, vector:iterators
//inheritance, polymorph friend
// 
class ClassA {
private:
	int i;
	int j;
public:
	static int counter;
	// copy constructor
	ClassA(const ClassA& x){
		cout<<"Copy constructor called"<< "\n";
		i=x.i;
		j=x.j;
	}

	ClassA(){
		cout<<"Construnctor 0"<<endl;
		i=0;
		j=0;
		counter++;
	}

	ClassA (int a) {
		cout<<"Construnctor 1"<<"\n";
		i=a;
		j=-22;
		counter++;
	}
	ClassA (int a,int b) : i(a), j(b) {
		cout<<"Construnctor 2"<<endl;
		counter++;
	}

	void setints(int a,int b){
		cout<<"setints"<<"\n";
		
		i=a;
		j=b;
	}
	int sum(){
		cout<<"sum"<<"\n";
		return i+j; 
	}
	ClassA operator+ (const ClassA & param){
		ClassA A;
		A.i=i+param.i;
		A.j=j+param.j;
		return A;

	}
};

int ClassA::counter=0;


//overloading
int first(int i){
	return i;
}
int first(int i,int j){
	return i+j;
}
double first(double i){
	return 2*i;
}


//template
template <class T, class U>
double tempsum(T a,U b){
	return (double)a+b; 
}

//namespace
namespace a1 {
	int x=1,y=2;
}

namespace a2{
	int x =3,y=3;
}

//astatic variables
void func1(void){
	static int i=0;
	i=i+1;
	cout<<"func1 i = "<<i<<endl;
}
void func2(void){
	static int i=0;
	i=i+1;
	cout<<"func2 i = "<<i<<endl;
}

//Inheritance constructors
class base{
	private:
		int i;
	public:
		base(){
			i=1;
			cout<<"base constructor"<<endl;
		}
		~base(){
			cout<<"base destructor"<<endl;
		}

};

class derived : public base{
private:
	int i;
public:
	derived(){
		i=2;
			cout<<"derived constructor"<<endl;

	}
	~derived(){
			cout<<"derived destructor"<<endl;

	}
};

// dynamic and static casting polymorphism
class AA {
	int i;
public:
	AA (){i=0;}
    virtual int m() {
    	cout<<"In virtual m A and i="<<i<<endl;
        return 1;
    }
    int h(){
    	cout<<"In h A and i="<<i<<endl;
        return 1;	
    }
    virtual int k(){
    	cout<<"In virtual k A and i="<<i<<endl;
        return 1;	
    }

};

class BB : public AA {
	int i;
public:
	BB (){i=1;}
    virtual int m() {
    	cout<<"In virtual m B and i="<<i<<endl;
        return 2;
    }
    int h(){
    	cout<<"In h B and i="<<i<<endl;
        return 1;	
    }
    int k(){
    	cout<<"In k B and i="<<i<<endl;
        return 1;	
    }


};

template<typename T>
int fun(T* obj) {
    return obj->m();
}

void Fa1(AA a){
	cout<<"Fa1 : ";
	a.m();
	a.h();
	a.k();
}
void Fa2(AA * a){
	cout<<"Fa2 : ";
	a->m();
	a->h();
	a->k();
}
void Fa3(AA & a){
	cout<<"Fa3 : ";
	a.m();
	a.h();
	a.k();
}

void Fb1(BB b){
	cout<<"Fb1 : ";
	b.m();
	b.h();
	b.k();
}
void Fb2(BB * b){
	cout<<"Fb2 : ";
	b->m();
	b->h();
	b->k();
}
void Fb3(BB & b){
	cout<<"Fb3 : ";
	b.m();
	b.h();
	b.k();
}

struct X{
	X() {cout<<"a";}
	X(const X &x){cout<<"a";}
	const X& operator=(const X& x){
		cout<<"c";
		return *this;
	}
};

int main(){
	vector<int> vec; 
	cout<<"vec size = "<<vec.size()<<endl;
	int i;
	for(i = 0; i < 5; i++){
      vec.push_back(i);
   	}
	cout<<"vec size = "<<vec.size()<<endl;

   // use iterator to access the values
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }

	ClassA A;

	cout<<"counter "<< ClassA::counter<<" instance counter = "<< A.counter<<"\n";	
	ClassA B(1);
	ClassA C(4,5);
	ClassA H;
	H=C;
	cout<<"H is copy C "<< H.sum()<<"\n";

	ClassA *D;
	ClassA *E[2];
	ClassA *F;
	cout<<"counter "<< ClassA::counter<<"\n";	

	D= new ClassA(-1,-2);
	cout<<"counter "<< ClassA::counter<<" instance counter = "<< D->counter<<"\n";	
	
	E[0]= new ClassA(-10,-2);
	E[1]= new ClassA(-1,-20);
	cout<<"counter "<< ClassA::counter<<" instance counter = "<< E[1]->counter<<"\n";	

	F=new ClassA[2] {{4,1},{1,4}};
	cout<<"counter "<< ClassA::counter<<" instance counter = "<< F[1].counter<<"\n";	


	A.setints(3,4);
	cout<<"A "<< A.sum()<<"\n";
	cout<<"B "<< B.sum()<<"\n";
	cout<<"C "<< C.sum()<<"\n";
	cout<<"D "<< D->sum()<<"\n";
	cout<<"E0 "<< E[0]->sum()<<"\n";
	cout<<"E1 "<< E[1]->sum()<<"\n";
	cout<<"F1 "<< F[0].sum()<<"\n";
	cout<<"F2 "<< F[1].sum()<<"\n";
	
	ClassA G;
	G=A+B;
	cout<<"G "<< G.sum()<<"\n";

	cout << " template = "<<tempsum(1,2)<<endl;


	cout<< "overloading = "<<first(2.0)<<endl;
	
	cout<< "namespace a1 = "<<a1::x<<endl;
	cout<< "namespace a2 = "<<a2::x<<endl;


	delete D;
	delete E[0];
	delete E[1];
	delete [] F;

	func1();
	func2();
	func1();
	func1();
	func1();
	func2();


	// base b;
	derived d;

	cout<<"---------------------------"<<endl<<endl;

	// AA* a = new AA();
	// BB* b = new BB();

	// dynamic polymorphism
	// std::cout << a->m(); // ok
	// std::cout << dynamic_cast<A*>(b)->m(); // ok - B instance conforms A interface
	// std::cout << b->m(); fails to compile due to overriden visibility - expected since technically does not violate IS-A relationship

	// static polymorphism
	// std::cout << fun(a); // ok
	//std::cout << fun(b); // fails to compile - B instance does not conform A interface at compile time

	cout<<"----------Learning polymorph-----------------"<<endl<<endl;

	AA aa;
	BB bb;
	AA * ap=new AA();
	BB * bp=new BB();
	AA * ap2b=new BB();
	// BB * bp2a=new AA(); not valid

	// Fb1(aa);// does not compile 
	// aa=bb; ok as aa is subset of bb 
	// bb=aa; not ok  as bb can contain new fields and thus cannot be initialized

	// Fb3(aa); // not ok ... does not work
	// Fb3()

	// Fb2(dynamic_cast<BB*>(ap2b));


	cout<<"************Done Learning polymorph-----------------"<<endl<<endl;

	cout<<"************Struct-----------------"<<endl<<endl;
	X x;
	X y(x);
	X z=y;
	z=x;

	cout<<endl<<"************Done Struct-----------------"<<endl<<endl;
	return 0;

}