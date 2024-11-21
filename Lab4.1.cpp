#include <iostream>
#include <stdexcept>

using namespace std;

class VectorShort {
private:
    short* data;
    size_t size;
    int codeError;
    static int objectCount;

public:
    VectorShort() : size(1), codeError(0) {
        data = new short[1]{0};
        if (!data) {
            codeError = -1;
        }
        objectCount++;
    }

    VectorShort(size_t n) : size(n), codeError(0) {
        data = new short[n]{0};
        if (!data) {
            codeError = -1;
        }
        objectCount++;
    }

    VectorShort(size_t n, short value) : size(n), codeError(0) {
        data = new short[n];
        if (!data) {
            codeError = -1;
            return;
        }
        for (size_t i = 0; i < n; ++i) {
            data[i] = value;
        }
        objectCount++;
    }

    VectorShort(const VectorShort& other) : size(other.size), codeError(other.codeError) {
        data = new short[size];
        if (!data) {
            codeError = -1;
        } else {
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        objectCount++;
    }

    ~VectorShort() {
        delete[] data;
        objectCount--;
    }

    short& operator[](size_t index) {
        if (index >= size) {
            codeError = -2;
            return data[size - 1];
        }
        return data[index];
    }

    bool operator==(const VectorShort& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const VectorShort& other) const {
        return !(*this == other);
    }

    bool operator>(const VectorShort& other) const {
        for (size_t i = 0; i < size && i < other.size; ++i) {
            if (data[i] <= other.data[i]) return false;
        }
        return true;
    }

    bool operator>=(const VectorShort& other) const {
        for (size_t i = 0; i < size && i < other.size; ++i) {
            if (data[i] < other.data[i]) return false;
        }
        return true;
    }

    bool operator<(const VectorShort& other) const {
        return !(*this >= other);
    }

    bool operator<=(const VectorShort& other) const {
        return !(*this > other);
    }

    VectorShort operator+(const VectorShort& other) const {
        size_t newSize = std::min(size, other.size);
        VectorShort result(newSize);
        for (size_t i = 0; i < newSize; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    VectorShort operator-(const VectorShort& other) const {
        size_t newSize = std::min(size, other.size);
        VectorShort result(newSize);
        for (size_t i = 0; i < newSize; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    VectorShort operator*(short value) const {
        VectorShort result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] * value;
        }
        return result;
    }

    VectorShort operator/(short value) {
        if (value == 0) {
            codeError = -3;
            return *this;
        }
        VectorShort result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] / value;
        }
        return result;
    }

    VectorShort operator%(short value){
        if (value == 0) {
            codeError = -3;
            return *this;
        }
        VectorShort result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] % value;
        }
        return result;
    }

    VectorShort operator|(const VectorShort& other) const {
        size_t newSize = std::min(size, other.size);
        VectorShort result(newSize);
        for (size_t i = 0; i < newSize; ++i) {
            result.data[i] = data[i] | other.data[i];
        }
        return result;
    }

    VectorShort operator^(const VectorShort& other) const {
        size_t newSize = std::min(size, other.size);
        VectorShort result(newSize);
        for (size_t i = 0; i < newSize; ++i) {
            result.data[i] = data[i] ^ other.data[i];
        }
        return result;
    }

    VectorShort operator&(const VectorShort& other) const {
        size_t newSize = std::min(size, other.size);
        VectorShort result(newSize);
        for (size_t i = 0; i < newSize; ++i) {
            result.data[i] = data[i] & other.data[i];
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const VectorShort& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, VectorShort& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            is >> vec.data[i];
        }
        return is;
    }

    static int getObjectCount() {
        return objectCount;
    }

    int getCodeError() const {
        return codeError;
    }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        codeError = 0;
    }

    void operator()() const {
        cout << "Вектор містить елементи: ";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    VectorShort& operator++() {
        for (size_t i = 0; i < size; ++i) {
            ++data[i];
        }
        return *this;
    }

    VectorShort operator++(int) {
        VectorShort temp = *this;
        ++(*this);
        return temp;
    }

    VectorShort& operator--() {
        for (size_t i = 0; i < size; ++i) {
            --data[i];
        }
        return *this;
    }

    VectorShort operator--(int) {
        VectorShort temp = *this;
        --(*this);
        return temp;
    }

    bool operator!() const {
        return size == 0;
    }

    VectorShort operator~() const {
        VectorShort result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = ~data[i];
        }
        return result;
    }

    VectorShort operator-() const {
        VectorShort result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = -data[i];
        }
        return result;
    }
};

int VectorShort::objectCount = 0;

int main() {
    VectorShort v1(5, 3);
    VectorShort v2(5, 4);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    // Тест арифметичних операцій
    VectorShort v3 = v1 + v2;
    cout << "v1 + v2: " << v3 << endl;
    
    VectorShort v4 = v1 - v2;
    cout << "v1 - v2: " << v4 << endl;

    VectorShort v5 = v1 * 2;
    cout << "v1 * 2: " << v5 << endl;

    VectorShort v6 = v1 / 2;
    cout << "v1 / 2: " << v6 << endl;

    VectorShort v7 = v1 % 2;
    cout << "v1 % 2: " << v7 << endl;

    // Тест побітових операцій
    VectorShort v8 = v1 | v2;
    cout << "v1 | v2: " << v8 << endl;

    VectorShort v9 = v1 ^ v2;
    cout << "v1 ^ v2: " << v9 << endl;

    VectorShort v10 = v1 & v2;
    cout << "v1 & v2: " << v10 << endl;

    // Тест порівнянь
    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 != v2: " << (v1 != v2) << endl;
    cout << "v1 > v2: " << (v1 > v2) << endl;
    cout << "v1 >= v2: " << (v1 >= v2) << endl;
    cout << "v1 < v2: " << (v1 < v2) << endl;
    cout << "v1 <= v2: " << (v1 <= v2) << endl;


    ++v1;
    cout << "v1 після інкременту: " << v1 << endl;

    v2++;
    cout << "v2 після інкременту: " << v2 << endl;

    --v1;
    cout << "v1 після деінкременту: " << v1 << endl;

    v2--;
    cout << "v2 після деінкременту: " << v2 << endl;
    
    v1();
    v2();

    
    cout << "Число об'єктів: " << VectorShort::getObjectCount() << endl;

    return 0;
}
