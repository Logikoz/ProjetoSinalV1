#include <Arduino.h>

const unsigned short int liberar = 13;
const unsigned short int parar = 8;
const unsigned short int atencao = 4;
const unsigned short int apitar = 2;
const unsigned short int taxa = 9600;

void setup()
{
	Serial.begin(taxa);
	pinMode(liberar, OUTPUT);
	pinMode(parar, OUTPUT);
	pinMode(atencao, OUTPUT);
	pinMode(apitar, OUTPUT);
}

void loop()
{
	char digito = Serial.read();

	if (digito == '1')
	{
		digitalWrite(liberar, HIGH);
		digitalWrite(atencao, LOW);
		digitalWrite(parar, LOW);
		//digitalWrite(apitar, LOW);
		Serial.println("Pode passar");
	}
	else if (digito == '2')
	{
		digitalWrite(liberar, LOW);
		digitalWrite(atencao, HIGH);
		digitalWrite(parar, LOW);
		//digitalWrite(apitar, LOW);
		Serial.println("Atencao");
	}
	else if (digito == '3')
	{
		digitalWrite(liberar, LOW);
		digitalWrite(atencao, LOW);
		digitalWrite(parar, HIGH);
		Serial.println("Pare!");
	}
	else if (digito == '9')
	{
		digitalWrite(apitar, HIGH);
		Serial.println("Apitandooooo!");
	}
	else if (digito == '0')
	{
		digitalWrite(apitar, LOW);
		Serial.println("Parou!");
	}
}
