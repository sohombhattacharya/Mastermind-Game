// Sohom Bhattacharya
// Homework 3
// October 11, 2013


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int rollDie(int sides)
{
	int roll = rand()%sides + 1;
	return roll;
}

int nthDigit(int &combination, int position)
{
	    int testComb = combination;
		int g_thousandsdigit;
		int g_hundredsdigit;
		int g_tensdigit;
		int g_onesdigit;
		int digits = 0;
				int position_value = 0;

		while (testComb != 0)
		{
			testComb /= 10;
			digits++;
		}

		if (position > 0 && digits == 4)
		{
			g_thousandsdigit = combination/1000;
							g_hundredsdigit = (combination - 1000*g_thousandsdigit)/100;
							g_tensdigit = (combination - (1000*g_thousandsdigit + 100*g_hundredsdigit))/10;
							g_onesdigit = combination - 1000*g_thousandsdigit - 100*g_hundredsdigit - 10*g_tensdigit;


		if (position == 3)
		position_value = (combination - 1000*g_thousandsdigit)/100;

		if (position == 2)
		position_value = (combination - (1000*g_thousandsdigit + 100*g_hundredsdigit))/10;


		if (position == 1)
		position_value = combination - 1000*g_thousandsdigit - 100*g_hundredsdigit - 10*g_tensdigit;


		if (position == 4)
		position_value = combination/1000;
		}
		return position_value;

}

void clearnthDigit(int &combination, int position)
{
			nthDigit(combination, position);
			int value; 
			if (position == 1)
				value = nthDigit(combination, position);
			if (position == 2)
				value = nthDigit(combination, position)*(pow(10,1));
			if (position == 3)
				value = nthDigit(combination,position)*(pow(10,2));
			if (position == 4)
				value = nthDigit(combination, position)*(pow(10,3));
			
			combination = combination - value;

			
}

void evaluate (int answer, int guess)
{
	int black = 0;
	int white = 0;
		int counter = 1;
		int counter2 = 1;
		int counter3 = 1;
		while (counter <= 4)
		{
			if (nthDigit(guess,counter) == nthDigit(answer,counter))
			{
				black++;
				clearnthDigit(answer,counter);
			}

			counter++;
		}

		while (counter3 <= 4)
		{ int counter4 = 1;
			while (counter4 <= 4)

			{
				if (nthDigit(guess,counter3) == nthDigit(answer,counter4))
				{
				white++;
				clearnthDigit(guess,counter3);
				}
				counter4++;
			}
			counter3++;
		}

		cout << white << " white pegs " << black << " black pegs" << endl;

}

void playMastermind()
{

	int onesdigit = rollDie(6); // random number for onesdigit
	int tensdigit = rollDie(6); // random number for tens
	int hundredsdigit = rollDie(6); // random number for hundreds
	int thousandsdigit = rollDie(6); // random number for thousands

	int thenumber = 1000*thousandsdigit + 100*hundredsdigit + 10*tensdigit + onesdigit; //myster number

	string play_again = "yes";
	
	while (play_again == "yes")
	{	
		int counter = 0;

	while (counter < 12)
	{
			counter++;

		int combination;
	cout << "The random number has been generated" << endl;
	cout << "Guess the combination:" << endl;
	cin >> combination;
	evaluate(thenumber,combination);
	if (combination == thenumber)
	{
		cout << "You guessed the number!" << endl;
		cout << "Would you like to play another game" << endl; //play again output
	cin >> play_again; //input "yes" for playing again
		
	}
	
	
	}
	cout << "Your number of attempts is up. Would you like to play a new game?" << endl; 
	cin >> play_again; 

	}
	
	
	
	



}



int main() {



	playMastermind();




	



	return 0;
}








