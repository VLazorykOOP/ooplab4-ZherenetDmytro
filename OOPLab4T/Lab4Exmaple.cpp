#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
int mainExample1() {

	/// <summary>
	/// Задано : A,B,C,D,F  -  Вектори комплесних чисел 
	///         a,b,c - комплексні числа.
	/// Обчислити вираз : F = A+B-B*c+C/b+D*a        
	/// </summary>
	/// <returns></returns>
	ComplexDouble a(1.0, 2), b, c;
	ComplexVector A, B, C, D, F;
#if defined(_MSC_VER)
	b._Val[_RE] = 2.3;
	b._Val[_IM] = 3.1;
	c = 4.1;
#else 
	b.real(2.3);
	b.imag(3.1);
	c.real(4.1);
#endif	
	ComplexVector A(3,2.7), B(3,a), C(3), D, F;
	D[0] = a; D[1] = b; D[2] = ComplexDouble(3.1, 1);
	cout <<" Begin data "  << endl;
	cout << " a= " << a << " b= " << b << " c " << c << endl;
	cout << " A  \n" << A;
	cout << " B  \n" << B;
	cout << " C  \n" << C;
	cout << " D  \n" << D;

	F = A + B - B * c + C / b + D * a;
	
	cout << " D  \n" << D;
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

