#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
vector<string> dealtCards;//variable declared outside of the class
class DeckOfCards
{
private:
	//variables declared inside the class
	string suite[4] = { "Clubs","Diamonds","Spades","Hearts" };
	string rank_[13] = { " Ace "," King "," Queen "," Jack "," 10 "," 9 "," 8 "," 7 "," 6 "," 5 "," 4 "," 3 "," 2 " };
public:
	string getRandomCard();
	int getRandomNumber(int min_, int max_);
	void dealCard(int numberOfPlayers);
	bool isCardGeneratedAlready(string card);

};
// function checks to see if the same card was already drawn
bool DeckOfCards::isCardGeneratedAlready(string card)
{
	int index;
	for (index = 0; index<dealtCards.size(); index++)
	{
		if (dealtCards[index] == card)
		{
			return true;
		}
	}
	return false;
}

//function to get a random card from the pile
int DeckOfCards::getRandomNumber(int min_, int max_)
{
	int range = (max_ - min_) + 1;
	return (min_ + int(range*rand() / (RAND_MAX + 1.0)));
}
string DeckOfCards::getRandomCard()
{
	string cardName = "";
	while (isCardGeneratedAlready(cardName))
	{
		cardName = rank_[getRandomNumber(0, 12)] + suite[getRandomNumber(0, 3)];
	}
	dealtCards.push_back(cardName);
	return cardName;
}

//function that distributes the cards to the players randomly
void DeckOfCards::dealCard(int numberOfPlayers)
{
	srand((unsigned)time(0));            //seeds rand function for dealing the cards based on time
	int playerNumber = 1;
	int i, j, k, ittr, startAgain = 0;
	for (i = 0; i<53; i++) 
	{
		cout << "Drawn Card: " << getRandomCard() << endl;
	}
	cout << "\n\n\tCard distribution among " << numberOfPlayers << " Players" << endl;
	for (ittr = 1; ittr <= numberOfPlayers; ittr++)
	{
		cout << " Player " << ittr << std::setw(12);
	}
	cout << endl;
	for (j = 0; j<dealtCards.size(); j++)
	{
		cout << dealtCards[j] << std::setw(12);
		if (j%numberOfPlayers == 0)
		{
			cout << endl;
		}
	}
}
int main()
{
	DeckOfCards deck;
	//here the number of players is 4
	deck.dealCard(4);
	system("pause");
}