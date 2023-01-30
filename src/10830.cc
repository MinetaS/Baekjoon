#include <cstdio>
#include <cstdint>
#include <cstring>

typedef int32_t *MatrixEntries;

struct SquareMatrix {
	uint8_t _Size;
	MatrixEntries _Values;

	SquareMatrix();
	SquareMatrix(uint8_t);

	void setIdentity();
	void finalize();

	SquareMatrix operator *(const SquareMatrix &) const;
	SquareMatrix operator %(uint32_t &&) const;
};

SquareMatrix::SquareMatrix() : SquareMatrix(1) {}

SquareMatrix::SquareMatrix(uint8_t size) : _Size(size) {
	if (size < 1) size = 1;
	_Values = new int32_t[size*size];
	memset(_Values, 0, 4*size*size);
}

void SquareMatrix::setIdentity() {
	for (int i=0 ; i<_Size ; i++) _Values[i*_Size+i] = 1;
}

void SquareMatrix::finalize() {
	delete[] _Values;
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
	int N, t, i;
	int64_t p;
	SquareMatrix MP[37];
	
	scanf("%d %lld", &N, &p);
	MP[0] = SquareMatrix(N);

	for (i=0 ; i<N ; i++) {
		for (int j=0 ; j<N ; j++) {
			scanf("%d", &t);
			MP[0]._Values[i*N+j] = t;
		}
	}

	for (i=1 ; i<37 ; i++) {
		if ((1uLL << i) > p) break;
		MP[i] = (MP[i-1]*MP[i-1])%1000;
	}

	SquareMatrix result(N);
	result.setIdentity();

	for (int i=0 ; i<37 ; i++) {
		if (p%2) result = (result*MP[i])%1000;
		p /= 2;
		if (p == 0) break;
	}

	for (int i=0 ; i<N ; i++) {
		for (int j=0 ; j<N ; j++)
			printf("%d ", result._Values[i*N+j]);

		printf("\n");
	}

	result.finalize();
	for (--i ; i>=0 ; i--) MP[i].finalize();

	return 0;
}