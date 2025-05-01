#include <iostream>
#include <stdexcept>
using namespace std;

class VectorLong {
private:
    long* data;
    int size;
    int codeError;
    static int objectCount;

public:
    // Get error code
    int getCodeError() const { return codeError; }

    // Get vector size
    int getSize() const { return size; }

    // Get object count
    static int getObjectCount() { return objectCount; }

    // Default constructor
    VectorLong() : size(1), codeError(0) {
        data = new(nothrow) long[size];
        if (data) {
            data[0] = 0;
        }
        else {
            codeError = 1;
        }
        objectCount++;
    }

    // Constructor with size
    VectorLong(int s) : size(s), codeError(0) {
        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; ++i)
                data[i] = 0;
        }
        else {
            codeError = 1;
        }
        objectCount++;
    }

    // Constructor with size and init value
    VectorLong(int s, long value) : size(s), codeError(0) {
        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; ++i)
                data[i] = value;
        }
        else {
            codeError = 1;
        }
        objectCount++;
    }

    // Copy constructor
    VectorLong(const VectorLong& other) : size(other.size), codeError(0) {
        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        else {
            codeError = 1;
        }
        objectCount++;
    }

    // Destructor
    ~VectorLong() {
        delete[] data;
        objectCount--;
    }

    // Assignment operator
    VectorLong& operator=(const VectorLong& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new(nothrow) long[size];
            if (data) {
                for (int i = 0; i < size; ++i)
                    data[i] = other.data[i];
            }
            else {
                codeError = 1;
            }
        }
        return *this;
    }

    // Unary ++/-- prefix
    VectorLong& operator++() {
        for (int i = 0; i < size; ++i)
            ++data[i];
        return *this;
    }

    VectorLong& operator--() {
        for (int i = 0; i < size; ++i)
            --data[i];
        return *this;
    }

    // Unary ++/-- postfix
    VectorLong operator++(int) {
        VectorLong temp = *this;
        ++(*this);
        return temp;
    }

    VectorLong operator--(int) {
        VectorLong temp = *this;
        --(*this);
        return temp;
    }

    // Unary logical NOT
    bool operator!() const {
        return size != 0;
    }

    // Unary bitwise NOT
    VectorLong operator~() const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = ~data[i];
        return result;
    }

    // Unary minus
    VectorLong operator-() const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = -data[i];
        return result;
    }

    // Operator []
    long& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index];
        codeError = 2;
        return data[size - 1];
    }

    // Arithmetic binary operators
    VectorLong operator+(const VectorLong& other) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    VectorLong operator-(const VectorLong& other) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    VectorLong operator*(long num) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] * num;
        return result;
    }

    VectorLong operator/(long num) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] / num;
        return result;
    }

    VectorLong operator%(long num) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] % num;
        return result;
    }

    // Bitwise binary
    VectorLong operator|(const VectorLong& other) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] | other.data[i];
        return result;
    }

    VectorLong operator^(const VectorLong& other) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] ^ other.data[i];
        return result;
    }

    VectorLong operator&(const VectorLong& other) const {
        VectorLong result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] & other.data[i];
        return result;
    }

    // Assignment operators with operation
    VectorLong& operator+=(const VectorLong& other) {
        for (int i = 0; i < size; ++i)
            data[i] += other.data[i];
        return *this;
    }

    VectorLong& operator-=(const VectorLong& other) {
        for (int i = 0; i < size; ++i)
            data[i] -= other.data[i];
        return *this;
    }

    VectorLong& operator*=(long num) {
        for (int i = 0; i < size; ++i)
            data[i] *= num;
        return *this;
    }

    VectorLong& operator/=(long num) {
        for (int i = 0; i < size; ++i)
            data[i] /= num;
        return *this;
    }

    VectorLong& operator%=(long num) {
        for (int i = 0; i < size; ++i)
            data[i] %= num;
        return *this;
    }

    VectorLong& operator|=(const VectorLong& other) {
        for (int i = 0; i < size; ++i)
            data[i] |= other.data[i];
        return *this;
    }

    VectorLong& operator^=(const VectorLong& other) {
        for (int i = 0; i < size; ++i)
            data[i] ^= other.data[i];
        return *this;
    }

    VectorLong& operator&=(const VectorLong& other) {
        for (int i = 0; i < size; ++i)
            data[i] &= other.data[i];
        return *this;
    }

    // Comparison
    bool operator==(const VectorLong& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; ++i)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    bool operator!=(const VectorLong& other) const {
        return !(*this == other);
    }

    bool operator>(const VectorLong& other) const {
        for (int i = 0; i < size; ++i)
            if (data[i] <= other.data[i]) return false;
        return true;
    }

    bool operator<(const VectorLong& other) const {
        for (int i = 0; i < size; ++i)
            if (data[i] >= other.data[i]) return false;
        return true;
    }

    bool operator>=(const VectorLong& other) const {
        return !(*this < other);
    }

    bool operator<=(const VectorLong& other) const {
        return !(*this > other);
    }

    // Function call operator
    void operator()() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    // Friend stream operators
    friend istream& operator>>(istream& in, VectorLong& vec) {
        for (int i = 0; i < vec.size; ++i)
            in >> vec.data[i];
        return in;
    }

    friend ostream& operator<<(ostream& out, const VectorLong& vec) {
        for (int i = 0; i < vec.size; ++i)
            out << vec.data[i] << " ";
        return out;
    }
};

// Static member initialization
int VectorLong::objectCount = 0;
int main() {
    VectorLong v1(3, 10);
    VectorLong v2(3, 5);
    VectorLong result = v1 + v2;

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v1 + v2: " << result << endl;

    return 0;
}