#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main() {
	string path = "E:\\Qt_Projects\\build-Model_of_LightTransport-Desktop_Qt_5_9_1_MSVC2017_64bit-Release\\Distribution.txt";
	ifstream fs(path);
	string buffer;
	double time_sum = 0;
	double time_min = 100000.0;
	double time_max = -1.0;
	vector<double> time_total;
	getline(fs, buffer);
	while (getline(fs, buffer)) {
		double time = stod(buffer.substr(buffer.size() - 8));
		time_sum += time;
		time_max = std::max(time, time_max);
		time_min = std::min(time, time_min);
		time_total.push_back(time);
	}
	std::cout << "max time:" << time_max << endl
		<< "min time:" << time_min << endl
		<< "average time:" << (accumulate(time_total.begin(), time_total.end(), 0.0)) / static_cast<double>(time_total.size()) << endl;
	return 0;
}