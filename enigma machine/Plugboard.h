#pragma once
#include <string>
#include <vector>
class Plugboard
{
private:
	std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<std::string> pairs;
	void swap_letters();
public:
	Plugboard(const std::vector<std::string>& pairs);
	unsigned int forward(unsigned int& signal);
	unsigned int backward(unsigned int& signal);
};

