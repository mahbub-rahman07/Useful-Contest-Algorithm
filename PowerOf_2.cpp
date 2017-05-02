#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<unsigned char> two1000;
	two1000.push_back(8);
	two1000.push_back(6);
	two1000.push_back(7);
	two1000.push_back(2);
	two1000.push_back(3);
	two1000.reserve(1000);

	// Calculate std::pow(2,1000) using a vector of characters
	for (std::size_t i = 16; i <= 1000; ++i) {
		for (int j = (two1000.size()-1); j >= 0; --j) {
			two1000[j] *= 2;

			// Shift up 10's as when multiplying by hand
			if (two1000[j] >= 10) {
				two1000[j] -= 10;
				if (j == (two1000.size()-1)) {
					two1000.push_back(1);
				}
				else {
					++two1000[j+1];
				}
			}
		}
	}

	unsigned long long running_sum = 0;
	for (int i = (two1000.size()-1); i >= 0; --i) {
		running_sum += two1000[i];
		std::cout << (int)two1000[i];
	}
	std::cout << " produced this sum: " << running_sum << std::endl;
	return 0;
}