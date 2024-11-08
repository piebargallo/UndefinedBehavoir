#include <string>
#include <iostream>

struct MyMovableStruct {
	operator bool() {
		return !data.empty();
	}
	std::string data;
};

void consume(MyMovableStruct&& x) {
	std::cout << "MyStruct: " << x.data << "\n";
}

void consume(bool x) { std::cout << "bool " << x << "\n"; }
void g(auto&& v) { consume(v); }

int main()
{
	g(MyMovableStruct{ "hello" });
}