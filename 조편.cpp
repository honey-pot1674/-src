#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int hipt;
	string ipt;
	vector<int>himang;
	vector<string>name;
	vector<vector<string>>sto;
	random_device rd;
	mt19937 gen(rd());
	cout << "�� �й� ���α׷�\n���� : ��ȣ �� ���ø� �� ������ ���� �� ������ �Ͼ �� �ֽ��ϴ�\n";
	cout << "��ġ �ο� �� �Է� : ";
	cin >> n;
	cout << "��ġ �� ��� �̸� �Է� (��Ȯ�ϰ� " << n << "���� �̸��� �Է�) : ";
	for (int i = 0; i < n; i++) {
		cin >> ipt;
		name.push_back(ipt);
	}
	cout << "\n�й� �� ���� �� �Է� : ";
	cin >> m;
	sto.resize(m);
	for (int i = 0; i < m; i++) {
		cout << i + 1 << "���� �ο� �� (�ִ� " << n << "��) : ";
		cin >> hipt;
		himang.push_back(hipt);
		n -= hipt;
	}
	int inx;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < himang[i]; j++) {
			inx = gen() % name.size();
			sto[i].push_back(name[inx]);
			name.erase(name.begin() + inx);
		}
	}
	ofstream ofs("Result.txt", ios::out | ios::app);
	if (ofs.fail())	{
		cout << "���� �߻�. ���������� �����ּ���." << '\n';
		return -1;
	}
	time_t end = chrono::system_clock::to_time_t(chrono::system_clock::now());
	char buf[256];
	ctime_s(buf, sizeof(buf), &end);
	ofs << buf;
	for (int i = 0; i < m; i++) {
		ofs << i + 1 << "�� : ";
		for (int j = 0; j < himang[i]; j++) {
			ofs << sto[i][j] << ' ';
		}
		ofs << '\n';
	}
	ofs.close();
}