#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string message, key;
	int ml, kl;

	cin >> message;
	cin >> key;
	ml = (int)message.length();
	kl = (int)key.length();

	for (int i=0 ; i<kl ; i++) message[i] = (message[i]-key[i]+26)%26+65;
	for (int i=kl ; i<ml ; i++) message[i] = (message[i]-message[i-kl]+26)%26+65;

	cout << message;

	return 0;
}