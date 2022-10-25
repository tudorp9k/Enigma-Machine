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
	std::vector<std::string> pairs{ "ND","AS","KX" };
	Plugboard PB(pairs);

	// Machine definition
	Enigma M(B, V, III, IV, PB, KB);

	// Ring settings
	M.set_rings("NYX");

	// Key settings
	M.set_key("MAN");

	// Message encryption
	std::string plaintext = "";
	std::string cyphertext = "";
	std::string input = { "HELLOWORLD" };

	// Input handling
	for (const auto& c : input)
	{
		if (isalpha(c))
			plaintext.push_back(toupper(c));
	}
	plaintext.erase(std::remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end());

	// Encryption
	for (auto const& c : plaintext)
		cyphertext += M.encipher(c);

	// Output
	std::cout << cyphertext << std::endl;
}