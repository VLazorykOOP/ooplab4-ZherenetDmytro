#include "ComplexVector.h"
ComplexDouble ComplexVector::badIndexRef=0;
ComplexVector::ComplexVector(int n) {
	if (n <= 0)    n = 2;  // default num =2;
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0.0;
		//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
	}

}
ComplexVector::ComplexVector(int n, ComplexDouble& b) : ComplexVector(n) {
	for (int i = 0; i < num; i++) {
		v[i] = b;
	}
}
void ComplexVector::Init(int n) {
	if (num != n) {
		if (v != nullptr) delete[] v;
		num = n;
		v = new ComplexDouble[n];
	}
	for (int i = 0; i < num; i++) 	v[i] = 0;
}
void ComplexVector::Init(int n, ComplexDouble b) {
	if (num != n) {
		if (v != nullptr) delete[] v;
		num = n;
		v = new ComplexDouble[n];
	}
	for (int i = 0; i < num; i++) 	v[i] = b;
}
ComplexVector::ComplexVector(int n, ComplexDouble* p) : ComplexVector(n) {
	if (p != nullptr)
		for (int i = 0; i < num; i++)  // !!! dangerous code
			v[i] = p[i];
}
ComplexVector::ComplexVector(const ComplexVector& s) {
	// if (this == &s) return;  // the expression is used in the old standard
	num = s.num;
	v = new ComplexDouble[num];
	state = 1;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}
ComplexVector& ComplexVector::operator=(const ComplexVector& s) {
	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new ComplexDouble[num];
		state = 1;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
ComplexVector& ComplexVector::operator=(ComplexVector&& s) noexcept
{
	if (this == &s) return *this;
	num = s.num; state = s.state;
	if (this->v != nullptr) delete[] v;
	v = s.v;
	s.num = 0; s.v = nullptr; s.state = -1;
}

void ComplexVector::Input() {
	int in_num = 0;
	do {
		cout << "Input size Vec\n";
		cin >> in_num;
	} while (in_num <= 0);
	if (num != in_num) {
		num = in_num;
		if (v) delete[] v;
		v = new ComplexDouble[num];
	}
	cout << " v : real img  ";
	cin >> *this;
}
void ComplexVector::Output() {
	if (num != 0) {
		std::cout << "vec = " << *this;
	}
}

bool ComplexVector::operator!() const   // true : exist v[i] != 0
{
	for (int i = 0; i < num; i++)
		if (fabs(v[i].real()) > 1.e-5 || fabs(v[i].imag()) > 1.e-5)
			return true;
	return false;
}
bool ComplexVector::operator~() const  // true : all  v[i] != 0
{
	for (int i = 0; i < num; i++)
		if (fabs(v[i].real()) < 1.e-5 && fabs(v[i].imag()) < 1.e-5)
			return false;
	return true;
}

ComplexDouble& ComplexVector::operator[](int index)
{
	if (index >= 0 && index < num) return v[index];
	return badIndexRef;
}

ComplexVector& ComplexVector::operator+=(const ComplexVector& b)
{
	int i;
	if (num < b.num) {
		ComplexDouble* tmp;
		tmp = new ComplexDouble[b.num];
		for (i = 0; i < num; i++) tmp[i] = v[i] + b.v[i];
		for (; i < b.num; i++) tmp[i] = b.v[i];
		num = b.num;
		if (v != nullptr) delete[] v;
		v = tmp;
	}
	else {
		for (i = 0; i < b.num; i++) v[i] += b.v[i];
	}
	return *this;
}
ComplexVector& ComplexVector::operator+=(const ComplexDouble& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] += b;
	}
	return *this;
}
ComplexVector& ComplexVector::operator+=(const double& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] += b;
	}
	return *this;
}
ComplexVector& ComplexVector::operator+=(const long& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] += b;
	}
	return *this;
}
ComplexVector ComplexVector::operator+(const ComplexVector& b)
{
	ComplexVector tmp(*this);
	tmp += b;
	return tmp;
}
ComplexVector ComplexVector::operator+(const ComplexDouble& b)
{
	ComplexVector tmp(*this);
	tmp += b;
	return tmp;
}
ComplexVector ComplexVector::operator+(const double& b)
{
	ComplexVector tmp(*this);
	tmp += b;
	return tmp;
}
ComplexVector ComplexVector::operator+(const long& b)
{
	ComplexVector tmp(*this);
	tmp += b;
	return tmp;
}

ComplexVector& ComplexVector::operator-=(const ComplexVector& b)
{
	int i;
	if (num < b.num) {
		ComplexDouble* tmp;
		tmp = new ComplexDouble[b.num];
		for (i = 0; i < num; i++) tmp[i] = v[i] - b.v[i];
		for (; i < b.num; i++) tmp[i] = -b.v[i];
		num = b.num;
		if (v != nullptr) delete[] v;
		v = tmp;
	}
	else {
		for (i = 0; i < b.num; i++) v[i] -= b.v[i];
	}
	return *this;
}
ComplexVector& ComplexVector::operator-=(const ComplexDouble& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] -= b;
	}
	return *this;
}
ComplexVector& ComplexVector::operator-=(const double& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] -= b;
	}
	return *this;
}
ComplexVector& ComplexVector::operator-=(const long& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++) v[i] -= b;
	}
	return *this;
}
ComplexVector ComplexVector::operator-(const ComplexVector& b)
{
	ComplexVector tmp(*this);
	tmp -= b;
	return tmp;
}
ComplexVector ComplexVector::operator-(const ComplexDouble& b)
{
	ComplexVector tmp(*this);
	tmp -= b;
	return tmp;
}
ComplexVector ComplexVector::operator-(const double& b)
{
	ComplexVector tmp(*this);
	tmp -= b;
	return tmp;
}
ComplexVector ComplexVector::operator-(const long& b)
{
	ComplexVector tmp(*this);
	tmp -= b;
	return tmp;
}

ComplexDouble ComplexVector::operator*=(const ComplexVector& b)  //  r= a0*b0+a1*b1+...+an-1*bn-1
{
	ComplexDouble ret(0, 0);
	if (num != b.num) { std::cout << " Error Vector opreation *= \n"; return ret; }
	for (int i = 0; i < num; i++) ret += v[i] * b.v[i];
	return ret;
}
ComplexVector& ComplexVector::operator%=(const  ComplexVector& b)  // (a0*b0, a1*b1,...,an-1*bn-1)
{
	if (num != b.num) { std::cout << " Error Vector opreation %= \n"; return *this; }
	for (int i = 0; i < num; i++) v[i] *= b.v[i];
	return *this;
}
ComplexVector& ComplexVector::operator*=(const ComplexDouble& b) {
	for (int i = 0; i < num; i++) v[i] *= b;
	return *this;
}
ComplexVector& ComplexVector::operator*=(const double& b) {
	for (int i = 0; i < num; i++) v[i] *= b;
	return *this;
}
ComplexVector& ComplexVector::operator*=(const long& b) {
	for (int i = 0; i < num; i++) v[i] *= b;
	return *this;
}
ComplexDouble ComplexVector::operator*(const ComplexVector& b)  //  r= a0*b0+a1*b1+...+an-1*bn-1
{
	//	ComplexVector rez(*this);
	return (*this) * b;
}
ComplexVector ComplexVector::operator%(const ComplexVector& b)  // (a0*b0, a1*b1,...,an-1*bn-1)
{
	ComplexVector rez(*this);
	rez *= b;
	return rez;
}
ComplexVector ComplexVector::operator*(const ComplexDouble& b) {
	ComplexVector rez(*this);
	rez *= b;
	return rez;
}
ComplexVector ComplexVector::operator*(const double& b) {
	ComplexVector rez(*this);
	rez *= b;
	return rez;
}
ComplexVector ComplexVector::operator*(const long& b) {
	ComplexVector rez(*this);
	rez *= b;
	return rez;
}

ComplexVector& ComplexVector::operator/=(const ComplexVector& b)  // (a0/b0, a1/b1,...,an-1/bn-1)
{
	if (num != b.num || ~b) { std::cout << " Error Vector opreation %= \n"; return *this; }
	for (int i = 0; i < num; i++) v[i] *= b.v[i];
	return *this;
}
ComplexVector& ComplexVector::operator/=(const ComplexDouble& b)
{
	if (fabs(b.real()) < 1.e-5 && fabs(b.imag()) < 1.e-5)
	{
		std::cout << " Error Vector opreation /= b \n";
	}
	else for (int i = 0; i < num; i++) v[i] /= b;
	return *this;
}
ComplexVector& ComplexVector::operator/=(const double& b) {
	if (fabs(b) < 1.e-5)
	{
		std::cout << " Error Vector opreation /= b \n";
	}
	else for (int i = 0; i < num; i++) v[i] /= b;
	return *this;
}
ComplexVector& ComplexVector::operator/=(const long& b) {
	if (fabs(b) < 1.e-5)
	{
		std::cout << " Error Vector opreation /= b \n";
	}
	else for (int i = 0; i < num; i++) v[i] /= b;
	return *this;
}
ComplexVector ComplexVector::operator/(const ComplexVector& b)  // (a0/b0, a1/b1,...,an-1/bn-1)
{
	ComplexVector rez(*this);
	rez /= b;
	return rez;
}
ComplexVector ComplexVector::operator/(const ComplexDouble& b) {
	ComplexVector rez(*this);
	rez /= b;
	return rez;
}
ComplexVector ComplexVector::operator/(const double& b) {
	ComplexVector rez(*this);
	rez /= b;
	return rez;
}
ComplexVector ComplexVector::operator/(const long& b) {
	ComplexVector rez(*this);
	rez /= b;
	return rez;
}

/// <summary>
/// friend function 
/// </summary>
/// <param name="is"></param>
/// <param name="s"></param>
/// <returns></returns>
istream& operator>>(istream& is, ComplexVector& s) {
	for (int i = 0; i < s.num; i++)
	{
#if defined(_MSC_VER)
		//cout << " v [ " << i << " ] real img  "; 
		is >> s.v[i] >> s.v[i]._Val[_IM];
#else 
		double re, im;
		// cout << " v [ " << i << " ] real img  "; 
		is >> re >> im;
		s.v[i].real(re);
		s.v[i].imag(im);
#endif		
	}
	return is;
};
ostream& operator<<(ostream& os, ComplexVector& s) {
	for (int i = 0; i < s.num; i++)
		os << s.v[i] << '\t';
	os << endl;
	return os;
}
