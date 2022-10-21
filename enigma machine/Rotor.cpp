#include "Rotor.h"

Rotor::Rotor(const std::string& wiring, const char& notch)
{
	right = wiring;
	this->notch = notch;
}

unsigned int Rotor::forward(unsigned int signal)
{
	char letter = right[signal];
	signal = left.find(letter);
	return signal;
}

unsigned int Rotor::backward(unsigned int signal)
{
	char letter = left[signal];
	signal = right.find(letter);
	return signal;
}

void Rotor::rotate_step()
{
	std::rotate(right.begin(), right.begin() + 1, right.end());
	std::rotate(left.begin(), left.begin() + 1, left.end());
}

void Rotor::rotate_to_letter(const char& letter)
{
	int p = left.find(letter);
	for (int i = 0; i < p; i++)
		rotate_step();
}

void Rotor::rotate_ring()
{
	std::rotate(right.begin(), right.begin() + 1, right.end());
}

void Rotor::set_ring(const char& letter)
{
	char dot_pos = right.find('A');
	int p = left.find(letter);
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < right.length(); j++)
		{
			if (right[j] == 'Z')
				right[j] = 'A';
			else right[j] = char(right[j] + 1);
		}
		dot_pos = (dot_pos + 1) % 26;
	}
	while (letter != right[dot_pos])
		rotate_ring();
}

char Rotor::get_first_letter() const
{
	return left[0];
}

char Rotor::get_notch() const
{
	return notch;
}