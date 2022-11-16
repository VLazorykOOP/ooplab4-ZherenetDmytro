#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
int mainExample1() {
	ComplexDouble a(1.0, 2), b, c;
	cout << a << endl;
#if defined(_MSC_VER)
	b._Val[_RE] = 21.3;
	b._Val[_IM] = 22.3;
#else 
	b.real(21.3);
	b.imag(22.3);
#endif	

	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	ComplexVector VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << " Input a " << endl;

#if defined(_MSC_VER)
	cin >> a >> a._Val[_IM];
#else 
	double re, im;
	cin >> re >> im;
	a.real(re);
	a.imag(im);
#endif		
	cout << a << endl;
	ComplexVector VecObj2(10, a);
	VecObj2.Output();

	VecObj.Input();
	cout << endl;
	VecObj.Output();
//	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();

	return 2;
}
int mainExample2() {
	ComplexMatrix a(5, 5, 3);
	cout << endl;
	cout << a;

	
	return 3;
}
int mainExample3() {

	return 4;
}

