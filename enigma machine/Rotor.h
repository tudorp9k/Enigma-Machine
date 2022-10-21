#pragma once
#include <string>
#include <iostream>
#include <cmath>
class Rotor
{
private:
	std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string right;
	char notch;
public:
	Rotor(const std::string& wiring, const char& notch);
	unsigned int forward(unsigned int signal);
	unsigned int backward(unsigned int signal);
	void rotate_step();
	void rotate_to_letter(const char& letter);
	void rotate_ring();
	void set_ring(const char& letter);
	char get_first_letter() const;
	char get_notch() const;
};

