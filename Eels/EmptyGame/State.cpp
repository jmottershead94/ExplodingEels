#include "State.h"

void State::SetText(float x, float y, int size, sf::Text& text)
{
	text.setPosition(x, y);
	text.setFont(font);
	text.setCharacterSize(size);
}

void State::SetSound(sf::SoundBuffer& buffer, const std::string& filename, float volume, sf::Sound& sound)
{
	buffer.loadFromFile(filename);
	sound.setBuffer(buffer);
	sound.setVolume(volume);
}

void State::SaveToFile()
{
	std::ofstream highScoresFile;
	highScoresFile.open("highScores.txt");
	highScoresFile << name + "\n" << score;
	highScoresFile.close();
}