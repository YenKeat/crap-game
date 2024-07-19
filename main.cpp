# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));  	 // Using current time as random seed
	enum status {WIN, CONTINUE, LOSE};
	status gameStatus = CONTINUE;

	int winCounts = 0;
	int loseCounts = 0;

	long numberRounds = 1000000;
	int numberCounts = 0;

	while (numberCounts < numberRounds) {

		unsigned int firstRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
		switch (firstRoll)
		{
		case 2:
		case 3:
		case 12:
			gameStatus = LOSE;
			break;

		case 7:
		case 11:
			gameStatus = WIN;
			break;

		default:
			gameStatus = CONTINUE;
		}

		while (gameStatus == CONTINUE)
		{
			unsigned int secondRoll = (rand() % 6 + 1) + (rand() % 6 + 1);

			if (secondRoll == firstRoll)
			{
				gameStatus = WIN;
				break;
			}
			else if (secondRoll == 7)
			{
				gameStatus = LOSE;
				break;
			}
		}

		if (gameStatus == WIN)
		{
			winCounts++;
		}

		else
		{
			loseCounts++;
		}

		if (numberCounts == 0)
		{
			cout << fixed << setprecision(2);
			cout << setw(15) << "Rounds" << setw(20) << "Win Rate" << endl;
		}

		if (numberCounts == 1 || numberCounts == 10 || numberCounts == 100 || numberCounts == 1000|| numberCounts == 10000 
			|| numberCounts == 100000 || numberCounts == 1000000)
		{
			cout <<setw(15)<< numberCounts << setw(20)<<
				static_cast<float>(winCounts) / static_cast<float>(numberCounts) * 100 << " %";
			
			cout << endl;
		}

		numberCounts++;
	}

  
	
	return 0;
}
