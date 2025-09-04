#include <iostream>
using namespace std;

enum enReadShape { Rock = 1,Paper = 2,Scissor = 3 };
enum enWinner { Player = 1,Computer = 2, Draw = 3 };

struct stResult {
	int PlayerWonTimes = 0;
	int ComputerWonTimes = 0;
	int DrawTimes = 0;
	string WinnerName = "";
};

enReadShape ReadPlayerChoice() {
	cout << "\nChoose your shape \n1-Rock \n2-Paper\n3-Scissor\n";
	int shape; cin >> shape;
	return (enReadShape)shape;
}

int RandomNumber(int From, int To){
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enReadShape ReadComputerChoice() {
	return  (enReadShape)RandomNumber(1, 3);
}

string GetReadShapeName(enReadShape choice) {
	switch (choice) {
	case Paper: return " Paper";
	case Rock: return " Rock";
	case Scissor: return " Scissor";
	default:
			return "Invalid";
	}
}

enWinner WhoWinTheRound(enReadShape PlayerChoice, enReadShape ComputerChoice) {
	if(PlayerChoice== ComputerChoice)
		return enWinner::Draw;
	switch (PlayerChoice) {
	case enReadShape::Paper:
		 if (ComputerChoice == enReadShape::Rock)
			return enWinner::Player;
		else
			return enWinner::Computer;

	case enReadShape::Rock:
		 if (ComputerChoice == enReadShape::Paper)
			return enWinner::Computer;
		else
			return enWinner::Player;

	case enReadShape::Scissor:
		 if (ComputerChoice == enReadShape::Paper)
			return enWinner::Player;
		else
			return enWinner::Computer;
	
	}
}

stResult result;
stResult res(enWinner Winner) {
	switch(Winner) {
	case Player:
		result.PlayerWonTimes++;
		result.WinnerName = "Player is Won!";
		break;
	case Computer:
		result.ComputerWonTimes++;
		result.WinnerName = "Computer is Won!";
		break;
	case Draw:
		result.DrawTimes++;
		result.WinnerName = "Draw!";
		break;
	}
	return result;
}
void SetScreenColor(enWinner winner) {
	switch (winner) {
	case Player:
		system("color 2F"); //green
		break;
	case Computer:
		system("color 4F"); //red
		break;
	case Draw:
		system("color 6F"); //yellow
		break;
	default:
		system("color 1F"); //blue
	}
}

char PlayAgain = 'y';
void print(stResult res, enReadShape computer_choice, enReadShape PlayerChoice, enWinner Winner) {
	cout << "Player choise is: " << GetReadShapeName(PlayerChoice) << '\n';
	cout << "Computer choise is: " << GetReadShapeName(computer_choice) << '\n';
	cout << "Winner: " << res.WinnerName << '\n';
	cout << "The Player Won: " << res.PlayerWonTimes << " Times" << '\n';
	cout << "The computer Won: " << res.ComputerWonTimes << " Times" << '\n';
	cout << "Draw Times: " << res.DrawTimes << '\n';
	SetScreenColor(Winner);
	do {
		cout << "play again ? y or n \n ";
		cin >> PlayAgain;
	} while (tolower(PlayAgain) != 'y' && tolower(PlayAgain) != 'n');
	cout << "________________________________________________________________________\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void FinalResult(stResult finalres) {
	cout << "The Player Won: " << finalres.PlayerWonTimes << " Times" << '\n';
	cout << "The computer Won: " << finalres.ComputerWonTimes << " Times" << '\n';
	cout << "Draw Times: " << finalres.DrawTimes << '\n';
	if (finalres.ComputerWonTimes > finalres.PlayerWonTimes)
		cout << "*************************** Game Over! ***************************";
	else if (finalres.ComputerWonTimes < finalres.PlayerWonTimes)
		cout << "*************************** Player won!**************************";
	else
		cout << "***************************Draw!***************************";
}
void startGame() {
	cout << "*****************************\nRock, Paper, Scissors Game:\n*****************************";

	do {
		ResetScreen();
		enReadShape PlayerChoice = ReadPlayerChoice();
		enReadShape ComputerChoice = ReadComputerChoice();
		enWinner Winner = WhoWinTheRound(PlayerChoice, ComputerChoice);
		stResult Result = res(Winner);
		print(Result, ComputerChoice, PlayerChoice, Winner);
		
	} while (tolower(PlayAgain) == 'y');
	ResetScreen();
	FinalResult(result);
}
int main()
{
	srand((unsigned)time(NULL));
	startGame();

	return 0;
}
