#pragma once

class Number
{
private:
	int baza, lungime;
	char numar[100] = {};
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number(); // Distruge constructorul (se apelează la finalul programului)

	int GetBase10Value() const;

	bool operator < (Number& num); 
	bool operator > (Number& num);
	bool operator <= (Number& num);
	bool operator >= (Number& num); 
	bool operator == (Number& num);
	
	//Funcția prieten (friend function) este o funcție care nu face parte din clasă, dar are acces la membrii privați ai acesteia.
	
	friend Number operator+ (const Number& num1, const Number& num2);
	friend Number operator- (const Number& num1, const Number& num2);

	Number& operator--();
	Number operator--(int);

	void SwitchBase(int newBase);
	void Print();
	void Print1();
	int  GetDigitsCount() const; // returns the number of digits for the current number
	int  GetBase() const; // returns the current base
};
