#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	float x, y;

	cin >> x; cin >> y;

	float R, S, C;

	R = 1/cos(pow(y, 2)/x);
	S = cbrt(x + log(1 / x));

	C = max(R, S);

	cout << "R = " << R << endl;
	cout << "S = " << S << endl;
	cout << "C = " << C << endl;

	system("pause");
}