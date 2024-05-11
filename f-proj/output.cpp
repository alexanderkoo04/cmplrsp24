#include <iostream>
using namespace std;
int main() {
	int p1 , q2s , r , pp ;
	p1 = 3 ;
	pp = 23 ;
	q2s = 4 ;
	r = 5 ;
	p1 = 2 * p1 + r * ( q2s + pp ) ;
	cout << p1 ;
	pp = p1 * ( q2s + 2 * r ) ;
	cout << "value=" << pp ;
	return 0 ;
}
