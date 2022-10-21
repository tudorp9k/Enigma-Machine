#include "Plugboard.h"

void Plugboard::swap_letters()
{
	for (int i = 0; i < pairs.size(); i++)
	{
		auto pos_0 = left.find(pairs[i][0]);
		auto pos_1 = left.find(pairs[i][1]);
		std::swap(left[pos_0], left[pos_1]);
	}
}

Plugboard::Plugboard(const std::vector<std::string>& pairs)
{
	this->pairs = pairs;
	swap_letters();
}

unsigned int Plugboard::forward(unsigned int& signal)
{
	char letter = right[signal];
	signal = left.find(letter);
	return signal;
}

unsigned int Plugboard::backward(unsigned int& signal)
{
	char letter = left[signal];
	signal = right.find(letter);
	return signal;
}
