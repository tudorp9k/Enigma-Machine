#include "Enigma.h"

Enigma::Enigma(Reflector RE, Rotor R1, Rotor R2, Rotor R3, Plugboard PB, Keyboard KB) : RE(RE), R1(R1), R2(R2), R3(R3), PB(PB), KB(KB)
{}

char Enigma::encipher(char letter)
{
	// Rotors rotations
	if (R2.get_first_letter() == R2.get_notch() && R3.get_first_letter() == R3.get_notch())
	{
		R1.rotate_step();
		R2.rotate_step();
		R3.rotate_step();
	}
	// Double step anomaly
	else if (R2.get_first_letter() == R2.get_notch())
	{
		R1.rotate_step();
		R2.rotate_step();
		R3.rotate_step();
	}
	else if (R3.get_first_letter() == R3.get_notch())
	{
		R2.rotate_step();
		R3.rotate_step();
	}
	else R3.rotate_step();


	// Full signal circuit
	unsigned int signal = KB.forward(letter);
	signal = PB.forward(signal);
	signal = R3.forward(signal);
	signal = R2.forward(signal);
	signal = R1.forward(signal);
	signal = RE.reflect(signal);
	signal = R1.backward(signal);
	signal = R2.backward(signal);
	signal = R3.backward(signal);
	signal = PB.backward(signal);
	letter = KB.backward(signal);
	return letter;
}

void Enigma::set_key(std::string key)
{
	R1.rotate_to_letter(key[0]);
	R2.rotate_to_letter(key[1]);
	R3.rotate_to_letter(key[2]);
}

void Enigma::set_rings(std::string key)
{
	R1.set_ring(key[0]);
	R2.set_ring(key[1]);
	R3.set_ring(key[2]);
}