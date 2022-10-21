#pragma once
#include "Keyboard.h"
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
class Enigma
{
private:
	Reflector RE;
	Rotor R1;
	Rotor R2;
	Rotor R3;
	Plugboard PB;
	Keyboard KB;
public:
	Enigma(Reflector RE, Rotor R1, Rotor R2, Rotor R3, Plugboard PB, Keyboard KB);
	char encipher(char letter);
	void set_key(std::string key);
	void set_rings(std::string key);
};

