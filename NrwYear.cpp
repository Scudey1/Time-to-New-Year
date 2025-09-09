#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
	using namespace std::chrono;

	// �������� ������� �����
	system_clock::time_point now = system_clock::now();
	std::time_t now_c = system_clock::to_time_t(now);
	std::tm now_tm = *std::localtime(&now_c);

	// ���������� ��������� ����� ���
	std::tm new_year_tm = {};
	new_year_tm.tm_year = now_tm.tm_year + 1;   // ��������� ���
	new_year_tm.tm_mon = 0;                      // ������
	new_year_tm.tm_mday = 1;                     // 1-� �����
	new_year_tm.tm_hour = 0;
	new_year_tm.tm_min = 0;
	new_year_tm.tm_sec = 0;

	std::time_t new_year_time = std::mktime(&new_year_tm);
	auto new_year_tp = system_clock::from_time_t(new_year_time);

	// ��������� �������
	auto diff = duration_cast<seconds>(new_year_tp - now);
	if (diff.count() < 0) {
		std::cout << "����� ��� ��� ��������!" << std::endl;
		return 0;
	}

	int total_seconds = static_cast<int>(diff.count());

	int days = total_seconds / (24 * 3600);
	total_seconds %= 24 * 3600;
	int hours = total_seconds / 3600;
	total_seconds %= 3600;
	int minutes = total_seconds / 60;
	int seconds = total_seconds % 60;

	std::cout << "�� ������ ���� ��������: "
		<< days << " ���� "
		<< hours << " ����� "
		<< minutes << " ����� "
		<< seconds << " ������.\n";

	return 0;
}