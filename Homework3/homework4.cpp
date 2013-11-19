#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int randomRange(int num)
{
	int randomeight = rand()%num + 1;
	return randomeight;
}

int nthDigit(int combination, int position)
{
	    int testComb = combination;
		int g_thousandsdigit;
		int g_hundredsdigit;
		int g_tensdigit;
		int g_onesdigit;
		int digits = 0;
		int position_value;

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
			int g_thousandsdigit;
			int g_hundredsdigit;
			int g_tensdigit;
			int digits = 0;
			int g_onesdigit;
			while (combination != 0)
			{
				combination /= 10;
				digits++;
			}

			if (position > 0 && position <= combination && digits == 4)
			{
				g_thousandsdigit = combination/1000;
				g_hundredsdigit = (combination - 1000*g_thousandsdigit)/100;
				g_tensdigit = (combination - (1000*g_thousandsdigit + 100*g_hundredsdigit))/10;
				g_onesdigit = combination - 1000*g_thousandsdigit - 100*g_hundredsdigit - 10*g_tensdigit;

			}

			if (position == 4)
			g_thousandsdigit = 0;
			if (position == 3)
			g_hundredsdigit = 0;
			if (position == 2)
			g_tensdigit = 0;
			if (position == 1)
			g_onesdigit = 0;

}

void evaluate (int answer, int guess)
{
	int black = 0;
	int white = 0;

		int counter = 1;
		int counter2 = 1;
		int counter3 = 1;
		int counter4 = 1;
		while (counter <= 4)
		{
			if (nthDigit(guess,counter) == nthDigit(answer,counter))
			{
				black++;
				clearnthDigit(guess,counter);
			}

			counter++;
		}

		while (counter3 <= 4)
		{
			while (counter4 <= 4)

			{
				if (nthDigit(guess,counter3) == nthDigit(answer,counter4))
				{
					white++;
				}

			}

		}

		cout << white << " white pegs " << black << " black pegs" << endl;

}

int generateAnswer()
{
	int decision;
	int combination;

	cout << "Would you like to enter your own number or generate a random one? Enter 1 for your own or 2 for a random" << endl;
	cin >> decision; 
	
	if (decision == 1) 
	{

		cout << "Enter combination" << endl;
		cin >> combination;
	
	}

	if (decision == 2) 
	{
		int ones = randomRange(8);
		int tens = randomRange(8);
		int hundreds = randomRange(8);
		int thousands = randomRange(8);

		combination = 1000*thousands + 100*hundreds + 10*tens + ones;

	}

	return combination;

}

int generateSearchSpace(int guesses[], int length)
{
	if (length >= 4096)
	{
	

	for (int i = 0; i <= length; i++)
	{
		
	
	
	
	}


	}
	
	}

int main()
{
	int n = randomRange(8888);
	cout << n;





return 0;
}