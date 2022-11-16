#include "ComplexMatrix.h"

ComplexMatrix::ComplexMatrix(int ni, int mi, ComplexDouble b)
{
	if (ni <= 0) n = 2; else n = ni;
	if (mi <= 0) m = 2; else m = mi;
	 vec = new ComplexVector[n];
	 for (int i = 0; i < n; i++) vec[i].Init(m, b);
	// vec = new ComplexVector[n]{ ComplexVector(m,b) };
	

}

ComplexMatrix::ComplexMatrix(const ComplexMatrix& s)
{
	n = s.n;
	m = s.m;
	int i;
//	vec = new ComplexVector[n]{ ComplexVector(m) };
	vec = new ComplexVector[n];    
	for (i = 0; i < n; i++) vec[i].Init(m);
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];

}

ComplexMatrix& ComplexMatrix::operator=(const ComplexMatrix& s)
{
	if (this != &s) {
		int i;
		if (n != s.n || m != s.m) {
			n = s.n; m = s.m;
			if (vec != nullptr) {
					delete[] vec;
			}
				vec = new ComplexVector [n];
				for (i = 0; i < n; i++) vec[i].Init(m);
		}
		for (i = 0; i < n; i++)
			for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];
		
	}
	return *this;
}

ComplexMatrix& ComplexMatrix::operator=(ComplexMatrix&& s) noexcept
{
	n = s.n; m = s.m;
	vec = s.vec;
	s.vec = nullptr;
	s.n = 0; s.m = 0;
	return *this;
}

void ComplexMatrix::Input()
{
}

void ComplexMatrix::Output()
{
}

bool ComplexMatrix::operator!() const
{
	return false;
}

bool ComplexMatrix::operator~() const
{
	return false;
}

ComplexVector& ComplexMatrix::operator[](int index)
{
	if (index >= 0 && index < n) return vec[index];
	return vec[0];
}

ComplexMatrix& ComplexMatrix::operator+=(const ComplexMatrix& s)
{
	// TODO: вставьте здесь оператор 
	return *this;
}

ComplexMatrix& ComplexMatrix::operator+=(const ComplexDouble& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix& ComplexMatrix::operator+=(const double& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& b)
{
	return ComplexMatrix();
}

ComplexMatrix ComplexMatrix::operator+(const ComplexDouble& b)
{
	return ComplexMatrix();
}

ComplexMatrix ComplexMatrix::operator+(const double& b)
{
	return ComplexMatrix();
}

ComplexMatrix& ComplexMatrix::operator-=(const ComplexMatrix& s)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix& ComplexMatrix::operator-=(const ComplexDouble& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix& ComplexMatrix::operator-=(const double& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix& b)
{
	return ComplexMatrix();
}

ComplexMatrix ComplexMatrix::operator-(const ComplexDouble& b)
{
	return ComplexMatrix();
}

ComplexMatrix ComplexMatrix::operator-(const double& b)
{
	return ComplexMatrix();
}


ComplexMatrix& ComplexMatrix::operator*=(const ComplexDouble& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix& ComplexMatrix::operator*=(const double& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& b)
{
	return ComplexMatrix();
}

ComplexVector ComplexMatrix::operator*(const ComplexVector& b)
{
	return ComplexVector();
}

ComplexMatrix ComplexMatrix::operator*(const ComplexDouble& b)
{
	return ComplexMatrix();
}

ComplexMatrix ComplexMatrix::operator*(const double& b)
{
	return ComplexMatrix();
}


ComplexMatrix& ComplexMatrix::operator/=(const ComplexDouble& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}

ComplexMatrix& ComplexMatrix::operator/=(const double& b)
{
	// TODO: вставьте здесь оператор return
	return *this;
}



ComplexMatrix ComplexMatrix::operator/(const ComplexDouble& b)
{
	return ComplexMatrix();
}


ComplexMatrix ComplexMatrix::operator/(const double& b)
{
	return ComplexMatrix();
}

void ComplexMatrix::RandComplexMatrix()
{
	for (int i = 0; i < n; i++) vec[i].RandComplexVector();
}

istream& operator>>(istream& is, ComplexMatrix& s)
{
	for (int i = 0; i < s.n; i++) is >> s.vec[i];
	return is;
}

ostream& operator<<(ostream& os, ComplexMatrix& s)
{
	for (int i = 0; i < s.n; i++) os << s.vec[i];  // << endl;
	return os;
}
