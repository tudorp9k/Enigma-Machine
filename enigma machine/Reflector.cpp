#include "Reflector.h"

Reflector::Reflector(const std::string& wiring)
{
	right = wiring;
}

unsigned int Reflector::reflect(unsigned int signal)
{
	char letter = right[signal];
	signal = left.find(letter);
	return signal;
}
