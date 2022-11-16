#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"

ComplexDouble RandComplexDouble()
{
	return ComplexDouble(rand()%10000/(1.0+rand()/100), rand() % 10000 / (1.0 + rand() / 100));
}

int mainExample1() {

	/// <summary>
	/// Задано : A,B,C,D,F  -  Вектори комплесних чисел 
	///         a,b,c - комплексні числа.
	/// Обчислити вираз : F = A+B-B*c+C/b+D*a        
	/// </summary>
	/// <returns></returns>
	ComplexDouble a(1.0, 2), b, c;
#if defined(_MSC_VER)
	b._Val[_RE] = 2.3;
	b._Val[_IM] = 3.1;
	c = 4.1;
#else 
	b.real(2.3);
	b.imag(3.1);
	c.real(4.1);
#endif	
	ComplexDouble r(2.7, 2.1);
	ComplexVector A(3,r), B(3,a), C(3,b), D(3), F(1);
	D[0] = a; 
	D[1] = b; 
	D[2] = ComplexDouble(3.1, 1);
	F[0] = (1, 3);
	F[1] = 3.2;
	cout <<" Begin data "  << endl;
	cout << " a= " << a << " b= " << b << " c " << c << endl;
	cout << " A  \n" << A;
	cout << " B  \n" << B;
	cout << " C  \n" << C;
	cout << " D  \n" << D;

	F = A + B - B * c + C / b + D * a;
	
	cout << " \n F =   \n" << F;
	return 2;
}



/// <summary>
	/// Задано : A,B,C,D,F  -  Матриці комплесних чисел
	///          a,b,c  -  Вектори комплесних чисел 
	///          _a,_b,_c - комплексні числа.
	/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
	///                   c = F*a + D*c         
	/// </summary>
	/// <returns></returns>

int mainExample2() {
	ComplexMatrix a(5, 5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) a[i][j] = RandComplexDouble();
	cout << endl;
	cout << a;

	
	return 3;
}
int mainExample3() {

	return 4;
}

