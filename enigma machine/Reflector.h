#pragma once
#include <string>
class Reflector
{
private:
	std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string right;
public:
	Reflector(const std::string& wiring);
	unsigned int reflect(unsigned int signal);
};

