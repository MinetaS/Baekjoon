#include <cstdio>
#include <cstdint>
#include <cstring>

typedef int32_t *MatrixEntries;

struct SquareMatrix {
	uint8_t _Size;
	MatrixEntries _Values;

	SquareMatrix();
	SquareMatrix(const SquareMatrix &);
	SquareMatrix(uint8_t);
	~SquareMatrix();

	void setIdentity();

	SquareMatrix &operator =(const SquareMatrix &);
	SquareMatrix operator *(const SquareMatrix &) const;
	SquareMatrix operator %(uint32_t &&) const;
};

SquareMatrix::SquareMatrix() : SquareMatrix(1) {}

SquareMatrix::SquareMatrix(const SquareMatrix &__r) {
	this->_Size = __r._Size;
	this->_Values = new int32_t[_Size*_Size];
	memcpy(_Values, __r._Values, 4*_Size*_Size);
}

SquareMatrix::SquareMatrix(uint8_t size) : _Size(size) {
	if (size < 1) size = 1;
	_Values = new int32_t[size*size];
	memset(_Values, 0, 4*size*size);
}

SquareMatrix::~SquareMatrix() {
	delete[] _Values;
}

void SquareMatrix::setIdentity() {
	for (int i=0 ; i<_Size ; i++) _Values[i*_Size+i] = 1;
}

SquareMatrix &SquareMatrix::operator=(const SquareMatrix &__r) {
	if (this == &__r) return *this;
	if (!this->_Values) delete[] _Values;

	this->_Size = __r._Size;
	this->_Values = new int32_t[_Size*_Size];
	memcpy(_Values, __r._Values, 4*_Size*_Size);

	return *this;
}

SquareMatrix SquareMatrix::operator *(const SquareMatrix &__r) const {
	if (this->_Size != __r._Size) return (SquareMatrix)0uLL;

	SquareMatrix __Return(_Size);

	for (int i=0 ; i<_Size ; i++)
		for (int j=0 ; j<_Size ; j++)
			for (int k=0 ; k<_Size ; k++)
				__Return._Values[i*_Size+j] += this->_Values[i*_Size+k] * __r._Values[k*_Size+j];

	return __Return;
}

SquareMatrix SquareMatrix::operator %(uint32_t &&__r) const {
	for (int i=0 ; i<_Size*_Size ; i++) this->_Values[i] %= __r;
	return *this;
}

int main() {
	int N, M, P;
	int i, j, t;
	SquareMatrix *MP;
	bool first = true;

	while (true) {
		scanf("%d %d %d", &N, &M, &P);
		if (!(N | M | P)) break;

		if (!first) printf("\n");
		first = false;

		MP = new SquareMatrix[16];
		MP[0] = SquareMatrix(N);

		for (i=0 ; i<N ; i++) {
			for (int j=0 ; j<N ; j++) {
				scanf("%d", &t);
				MP[0]._Values[i*N+j] = t;
			}
		}

		for (i=1 ; i<16 ; i++) {
			if ((1uLL << i) > P) break;
			MP[i] = (MP[i-1]*MP[i-1])%M;
		}

		SquareMatrix result(N);
		result.setIdentity();

		for (i=0 ; i<16 ; i++) {
			if (P%2) result = (result*MP[i])%M;
			P /= 2;
			if (P == 0) break;
		}

		for (i=0 ; i<N ; i++) {
			for (j=0 ; j<N ; j++)
				printf("%d ", result._Values[i*N+j]);

			printf("\n");
		}

		delete[] MP;
	}

	return 0;
}