#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Profile {
public:
	double iat_mi_limit;
	double iat_de_limit;
	double pay_mi_limit;
	double pay_de_limit;

	Profile()
		: Profile(0.0, 0.0, 0.0, 0.0) {}

	Profile(double arg0, double arg1, double arg2, double arg3)
		: iat_mi_limit(arg0), iat_de_limit(arg1), pay_mi_limit(arg2), pay_de_limit(arg3) {}
};

class DailyTransaction {
public:
	string timestamp;
	double amount;

	DailyTransaction()
		: DailyTransaction(string("00000000")) {}

	DailyTransaction(string time)
		: timestamp(time), amount(0.0) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<string>> instructions;

	while (true) {
		string _str;

		cin >> _str;
		if (_str == "9") break;

		vector<string> args;
		size_t pos = 0;

		while ((pos = _str.find(",")) != string::npos) {
			string split = _str.substr(0, pos);
			args.push_back(split);
			_str.erase(0, pos+1);
		}
		args.push_back(_str);

		instructions.push_back(args);
	}
	
	unordered_map<string, Profile> owners;
	unordered_map<int, string> accounts;
	unordered_map<string, DailyTransaction> iat_daily_tr;
	unordered_map<string, DailyTransaction> pay_daily_tr;

	int order = 1;
	bool init = false;

	for (int i=0 ; i<instructions.size() ; i++) {
		int field = stoi(instructions[i][0]);

		if (field == 1) {
			string name = instructions[i][1];
			double iat_mi_limit = stod(instructions[i][2]);
			double iat_de_limit = stod(instructions[i][3]);
			double pay_mi_limit = stod(instructions[i][4]);
			double pay_de_limit = stod(instructions[i][5]);

			Profile profile = Profile(iat_mi_limit, iat_de_limit, pay_mi_limit, pay_de_limit);
			owners[name] = profile;
			continue;
		}

		if (field == 2) {
			string name = instructions[i][1];
			int account = stoi(instructions[i][2]);

			accounts[account] = name;
			continue;
		}

		if (!init) {
			init = true;

			for (auto const &pair : owners) {
				iat_daily_tr[pair.first] = DailyTransaction("00000000");
				pay_daily_tr[pair.first] = DailyTransaction("00000000");
			}
		}

		if (field == 5) {
			string timestamp = instructions[i][1].substr(0, 8);
			string name = instructions[i][2];
			int src_account = stoi(instructions[i][3]);
			int dst_account = stoi(instructions[i][5]);
			double amount = stod(instructions[i][4]);

			if (name != accounts[src_account]) {
				printf("INSTRUCTION %d: NOT OWNER\n", order++);
				continue;
			}

			int type;
			Profile profile = owners[name];
			DailyTransaction iat_daily = iat_daily_tr[name];
			DailyTransaction pay_daily = pay_daily_tr[name];

			if (name == accounts[dst_account]) type = 1;   // IAT
			else type = 2;								   // Payment

			if (type == 1) {
				if (amount > profile.iat_mi_limit) {
					printf("INSTRUCTION %d: IAT MAX EXCEEDED\n", order++);
					continue;
				}

				if (iat_daily.timestamp != timestamp) {
					iat_daily.timestamp = timestamp;
					iat_daily.amount = 0;
					iat_daily_tr[name] = iat_daily;
				}

				if (iat_daily.amount+amount > profile.iat_de_limit) {
					printf("INSTRUCTION %d: IAT DEL EXCEEDED\n", order++);
					continue;
				}

				iat_daily.amount += amount;
				iat_daily_tr[name] = iat_daily;

				printf("INSTRUCTION %d: IAT OK\n", order++);
			}

			else {
				if (amount > profile.pay_mi_limit) {
					printf("INSTRUCTION %d: PAYMENT MAX EXCEEDED\n", order++);
					continue;
				}

				if (pay_daily.timestamp != timestamp) {
					pay_daily.timestamp = timestamp;
					pay_daily.amount = 0;
				}

				if (pay_daily.amount+amount > profile.pay_de_limit) {
					printf("INSTRUCTION %d: PAYMENT DEL EXCEEDED\n", order++);
					continue;
				}

				pay_daily.amount += amount;
				pay_daily_tr[name] = pay_daily;

				printf("INSTRUCTION %d: PAYMENT OK\n", order++);
			}
		}
	}

	return 0;
}