#include <iostream>
using std::cout;

void f(float&& x) { cout << "float " << x << "\n"; }
void f(int&& x) { cout << "int " << x << "\n"; }
void g(auto&& v) { f(v); } // C++ 20

int main()
{
	g(2);
	g(1.f);
}