#include <cstdio>
#include <cstdint>
#include <cstring>

typedef int64_t *MatrixEntries;

bool MatrixError;

struct Matrix {
	uint32_t _Rows, _Columns;
	MatrixEntries _Values;

	Matrix();
	Matrix(const Matrix &);
	Matrix(uint32_t, uint32_t);
	~Matrix();

	Matrix &operator =(const Matrix &);
	Matrix operator *(const Matrix &) const;
};

Matrix::Matrix() : Matrix(1, 1) {}

Matrix::Matrix(const Matrix &__r) {
	this->_Rows = __r._Rows;
	this->_Columns = __r._Columns;
	this->_Values = new int64_t[_Rows*_Columns];
	memcpy(_Values, __r._Values, 8*_Rows*_Columns);
}

Matrix::Matrix(uint32_t rows, uint32_t columns) {
	_Rows = rows;
	_Columns = columns;

	if (_Rows < 1) _Rows = 1;
	if (_Columns < 1) _Columns = 1;

	_Values = new int64_t[_Rows*_Columns];
	memset(_Values, 0, 8*_Rows*_Columns);
}

Matrix::~Matrix() {
	delete[] _Values;
}

Matrix &Matrix::operator=(const Matrix &__r) {
	if (this == &__r) return *this;
	if (!this->_Values) delete[] _Values;

	this->_Rows = __r._Rows;
	this->_Columns = __r._Columns;
	this->_Values = new int64_t[_Rows*_Columns];
	memcpy(_Values, __r._Values, 8*_Rows*_Columns);

	return *this;
}

Matrix Matrix::operator *(const Matrix &__r) const {
	if (_Columns != __r._Rows) {
		MatrixError = true;
		return Matrix();
	}

	Matrix __Return(_Rows, __r._Columns);

	for (int i=0 ; i<_Rows ; i++)
		for (int j=0 ; j<__r._Columns ; j++)
			for (int k=0 ; k<_Columns ; k++)
				__Return._Values[i*__r._Columns+j] += _Values[i*_Columns+k] * __r._Values[k*__r._Columns+j];

	MatrixError = false;
	return __Return;
}

int main() {
	int _case = 1;
	uint32_t r1, c1, r2, c2;

	while (true) {
		scanf("%u %u %u %u", &r1, &c1, &r2, &c2);
		if (!r1 && !c1 && !r2 && !c2) break;

		Matrix m1(r1, c1);
		Matrix m2(r2, c2);

		for (int i=0 ; i<r1 ; i++)
			for (int j=0 ; j<c1 ; j++)
				scanf("%ld", &m1._Values[i*c1+j]);

		for (int i=0 ; i<r2 ; i++)
			for (int j=0 ; j<c2 ; j++)
				scanf("%ld", &m2._Values[i*c2+j]);

		Matrix r = m1*m2;

		printf("Case #%d:\n", _case++);

		if (MatrixError) printf("undefined\n");
		else {
			for (int i=0 ; i<r1 ; i++) {
				printf("| ");
				for (int j=0 ; j<c2 ; j++) printf("%ld ", r._Values[i*c2+j]);
				printf("|\n");
			}
		}
	}

	return 0;
}