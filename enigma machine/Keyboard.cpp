#include "Keyboard.h"

unsigned int Keyboard::forward(const char& letter) const
{
		auto found = alphabet.find(letter);
		if (found != std::string::npos)
			return found;
}

char Keyboard::backward(const unsigned int& signal) const
{
	return alphabet[signal];
}
