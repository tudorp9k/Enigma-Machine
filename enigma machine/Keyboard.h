#pragma once
#include <string>
#include <iostream>
class Keyboard
{
private:
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	unsigned int forward(const char& letter) const;
	char backward(const unsigned int& signal) const;
};

