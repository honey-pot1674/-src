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
	cout << "조 분배 프로그램\n주의 : 괄호 속 지시를 잘 따르지 않을 시 오류가 일어날 수 있습니다\n";
	cout << "배치 인원 수 입력 : ";
	cin >> n;
	cout << "배치 할 사람 이름 입력 (정확하게 " << n << "명의 이름만 입력) : ";
	for (int i = 0; i < n; i++) {
		cin >> ipt;
		name.push_back(ipt);
	}
	cout << "\n분배 할 조의 수 입력 : ";
	cin >> m;
	sto.resize(m);
	for (int i = 0; i < m; i++) {
		cout << i + 1 << "조의 인원 수 (최대 " << n << "명) : ";
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
		cout << "에러 발생. 개발자한테 문의주세요." << '\n';
		return -1;
	}
	time_t end = chrono::system_clock::to_time_t(chrono::system_clock::now());
	char buf[256];
	ctime_s(buf, sizeof(buf), &end);
	ofs << buf;
	for (int i = 0; i < m; i++) {
		ofs << i + 1 << "조 : ";
		for (int j = 0; j < himang[i]; j++) {
			ofs << sto[i][j] << ' ';
		}
		ofs << '\n';
	}
	ofs.close();
}