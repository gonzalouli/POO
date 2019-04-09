#include <iostream>

class C{
	public: 
		C();
		C(int a,int b,int c, int d);
		int f1(int i) ;
		int f2(int i);
		static void f3() {m=1;}
		static int n; //3
	private:
		mutable int i;
		const int j;
		mutable int k;
		int l;
		static int m;
};


int C ::f1(int i) {l=i; k=i; return 0; }
C::C(): i{0}, j{0}, k{0},l{0} {}

C::C(int a,int b,int c,int d) : i(a),j(b),k(c),l(d)
{}

int C::f2(int i){
 k=i;l=i;return 0;
}
int main(){
	C c;
	///C::n =3;
	c.n=4;
	std::cout << /*C::n << */ " " << c.n << std::endl;
	return 0;
}

