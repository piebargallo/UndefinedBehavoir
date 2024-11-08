constexpr int my_div(int a, int b)
{
	return a / b;
}

namespace test {
	template <unsigned int N>
	constexpr int div_test(const int(&A)[N], const int(&B)[N]) {
		int x = 0;
		for (auto i = 0u; i < N; ++i) {
			x = ::my_div(A[i], B[i]);
		}
		return x;
	}
}


int main()
{
	constexpr int A[] = { 1, 2, 3, 4 };
	constexpr int B[] = { 1, 2, 3, 0 };
	static_assert ((test::div_test(A, A), true));
	// static_assert ((test::div_test(A, B), true)); // Goes not compile, divide by zero.
	return 0;
}