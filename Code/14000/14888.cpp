#include <cstdio>
#include <vector>

using namespace std;

struct Pair {
	int max;
	int min;
};

Pair match(const vector<int> &, vector<int> &, vector<int> &);
int calculate(const vector<int> &, const vector<int> &);

int main() {
	int n, t;
	vector<int> operands;
	vector<int> operators;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		operands.push_back(t);
	}

	for (int i=0 ; i<4 ; i++) {
		scanf("%d", &t);
		operators.push_back(t);
	}

	Pair result = match(operands, *(new vector<int>), operators);

	printf("%d\n%d", result.max, result.min);
	
	return 0;
}

Pair match(const vector<int> &operands, vector<int> &operators, vector<int> &left_operators) {
	if (operators.size() == operands.size()-1) {
		int c = calculate(operands, operators);
		return {c, c};
	}

	int max = -2147483647;
	int min = 2147483647;
	int index = operators.size();
	
	for (int i=0 ; i<4 ; i++) {
		if (left_operators[i] == 0) continue;

		bool div0 = i==3 && operands[index+1]==0;
		if (div0) continue;

		operators.push_back(i);
		left_operators[i]--;

		Pair res = match(operands, operators, left_operators);
		if (res.max > max) max = res.max;
		if (res.min < min) min = res.min;

		if (!div0) {
			operators.pop_back();
			left_operators[i]++;
		}
	}

	return {max, min};
}

int calculate(const vector<int> &operands, const vector<int> &operators) {
	int size = operands.size();
	int result;

	for (int i=0 ; i<size-1 ; i++) {
		int first = (i == 0) ? operands[0] : result;

		if (operators[i] == 0) result = first+operands[i+1];
		if (operators[i] == 1) result = first-operands[i+1];
		if (operators[i] == 2) result = first*operands[i+1];
		if (operators[i] == 3) result = first/operands[i+1];
	}

	return result;
}