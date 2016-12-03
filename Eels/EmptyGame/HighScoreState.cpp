#include "HighScoreState.h"
/*
//--------Aiden's Plan for highscore---------//
use vector
check for file
check for header text

get amount of lines
for loop to read lines
add to vector
add newPlayer to vector
sort
write to file again
print to game

*/

//////////////////////////////////////////////////////////
//======================================================//
//					Constructor							//
//======================================================//
// This will initialise this state.						//
// Passing in the current state allows for				//
// communication between the states.					//
//////////////////////////////////////////////////////////
HighScoreState::HighScoreState(const State& currentState) : State(currentState)
{
	counter = -1;
	std::string names[10] = { "Daniel", "Jason", "Steve", "Aidun", "Jake", "Matthew", "Craig", "Kate", "Stephen", "Chris" };
	int highScore[10] = { 1500, 1400, 1300, 1300, 1150, 1100, 1100, 1000, 950, 900 };

	//// Set up a new text variable.
	//// Set the font of the text that is going to be displayed.
	SetText(50.0f, 25.0f, 64, latestScore);
	//latestScore.setString("Your Score was " + std::to_string(score));
	SetText(500.0f, 25.0f, 64, typeName);
	typeName.setString("Type Name Here:");
	SetText(800.0f, 25.0f, 64, nameText);
	PlayerScore player(font);
	highScoreBox.setPosition(sf::Vector2f(450.0f, 100.0f));
	highScoreBox.setSize(sf::Vector2f(400.0f, 600.0f));
	highScoreBox.setFillColor(sf::Color::Blue);
	highScoreBox.setOutlineColor(sf::Color::Black);
	highScoreBox.setOutlineThickness(5.0f);

	exitButton.setPosition(sf::Vector2f(900.f, 500.0f));
	exitButton.setSize(sf::Vector2f(300.0f, 150.0f));
	exitButton.setOutlineColor(sf::Color::Black);
	exitButton.setOutlineThickness(3.0f);
	exitButton.setFillColor(sf::Color::Blue);

	SetText(930.0f, 535.0f, 48, exitText);
	exitText.setString("Press Enter - Menu");

	//Make ten spaces for 
	for (int i = 0; i < 10; i++)
	{
		player.placeText.setPosition(sf::Vector2f(490.0f, 100.0f + (60 * i)));
		player.placeText.setCharacterSize(50);
		player.name.setPosition(sf::Vector2f(550.0f, 100.0f + (60 * i)));
		player.name.setCharacterSize(50);
		player.scoreText.setPosition(sf::Vector2f(710.0f, 100.0f + (60 * i)));
		player.scoreText.setCharacterSize(50);
		player.scoreText.setString(std::to_string(highScore[i]));
		player.name.setString(names[i]);
		player.placeText.setString(std::to_string(i + 1));
		playerScores.push_back(player);
	}
	menuMusic->play();
	//std::ifstream getHighScores;
	//std::string temp;
	//SetText(500.0f, 300.0f, 50.0f, test);
	//getHighScores.open("Highscores.txt");
	//if (getHighScores.bad())
	//{
	//	std::cout << "Error";
	//	return;
	//}
	//if (getHighScores.is_open()) 
	//{

	//	//getHighScores.getline(temp, 10);
	//}
	//getHighScores.close();
	//Only lets you type if your score is higher than one of the top ten
}

//////////////////////////////////////////////////////////
//======================================================//
//					Destructor							//
//======================================================//
// This will clean up any variables.					//
//////////////////////////////////////////////////////////
HighScoreState::~HighScoreState()
{
}

//////////////////////////////////////////////////////////
//======================================================//
//					HandleInput							//
//======================================================//
// This function will handle all of the user input.		//
// This function also allows the states to change to	//
// each other, by return a pointer of state.			//
// If there is a state transition, it will be placed	//
// here.												//
//////////////////////////////////////////////////////////
State* HighScoreState::HandleInput()
{
	// Handle any input here for changing states.
	if (exitButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		// Return any new states here.
		// This function requires a state to be returned.
		//newHighScore = false;
		menuMusic->stop();
		return new MenuState(*this);
	}

	// Returns nothing because there has been no input from the player yet. 
	return NULL;

}


void HighScoreState::Render()
{

	// Draw your all of your sprites/gameobjects here.
	window->draw(exitButton);
	window->draw(exitText);
	window->draw(highScoreBox);
	for (int i = 0; i < playerScores.size(); i++)
	{
		window->draw(playerScores[i].name);
		window->draw(playerScores[i].placeText);
		window->draw(playerScores[i].scoreText);
	}
	if (score > 0)
	{
		//window->draw(latestScore);
		//window->draw(typeName);
		//window->draw(nameText);
	}
}

void HighScoreState::Update(const sf::Time& deltaTime)
{
	nameText.setString(name);
}

/*
void HighScoreState::HandleTextInput()
{
sf::Event event;

}
void HighScoreState::SetupText()
{

newPlayer.name = "s";
//	newPlayer.score = player->score;
newPlayer.date = std::to_string(tDay) + "-" + std::to_string(tMonth) + "-" + std::to_string(tYear);
if (tHour < 10 && tMinute < 10)
newPlayer.time = "0" + std::to_string(tHour) + ":0" + std::to_string(tMinute);
else if (tHour < 10 && tMinute >= 10)
newPlayer.time = "0" + std::to_string(tHour) + ":" + std::to_string(tMinute);
else if (tHour >= 10 && tMinute < 10)
newPlayer.time = std::to_string(tHour) + ":0" + std::to_string(tMinute);
else
newPlayer.time = std::to_string(tHour) + ":" + std::to_string(tMinute);
topScores.push_back(newPlayer);

}
void HighScoreState::SortText()
{
for (int x = 0; x< topScores.size(); x++)	// bubble sort
{
for (int y = 0; y<topScores.size() - 1; y++)
{
if (topScores[y].score < topScores[y + 1].score)
{
PlayerScore temp = topScores[y + 1];
topScores[y + 1] = topScores[y];
topScores[y] = temp;
}
}
}
}
void HighScoreState::PrintText()
{
number.setString("1.\n2.\n3.\n4.\n5.\n6.\n7.\n8.\n9.\n10.\n");
}
void HighScoreState::FileHandling()
{
std::ofstream highscoresText("Highscores.txt", std::ios::out | std::ios::app | std::ios::binary);
if (highscoresText.is_open())
{
std::ifstream firstLine("Highscores.txt");
std::string readLine, compareLine;
compareLine = "Name:	Score:	Time:	Date:";
highscoresText << newPlayer.name << "\t\t";
if (firstLine.good()) getline(firstLine, readLine);
if (readLine != compareLine) highscoresText << "Name:	Score:	Time:	Date:\n";
if (newPlayer.score >= 1000) highscoresText << newPlayer.score << "\t";
else highscoresText << newPlayer.score << "\t\t";
highscoresText << newPlayer.time << "\t" << newPlayer.date << "\n";
firstLine.close();
highscoresText.close();
}
}


*/