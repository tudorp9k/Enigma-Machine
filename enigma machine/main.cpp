#include <iostream>
#include "Enigma.h"
#include "Keyboard.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"
int main()
{
	// Historical rotors & reflectors
	Rotor I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
	Rotor II("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
	Rotor III("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
	Rotor IV("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
	Rotor V("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');

	Reflector A("EJMZALYXVBWFCRQUONTSPIKHGD");
	Reflector B("YRUHQSLDPXNGOKMIEBFZCWVJAT");
	Reflector C("FVPJIAOYEDRZXWGCTKUQSBNMHL");

	// Keyboard & Plugboard
	Keyboard KB;
	std::vector<std::string> pairs{ "AR","GK","OX" };
	Plugboard PB(pairs);

	// Machine definition
	Enigma M(B, V, III, IV, PB, KB);

	// Ring settings
	M.set_rings("NOT");

	// Key settings
	M.set_key("MAN");

	// Message encryption
	std::string cyphertext = "";
	std::string plaintext = { "HELLOWORLD" };
	for (auto const& c : plaintext)
		cyphertext += M.encipher(c);

	// Output
	std::cout << cyphertext << std::endl;
}