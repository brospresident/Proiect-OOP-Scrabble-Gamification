#include "./TopPage.h"

TopPage::TopPage(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font) : AbstractPage(window, textures, font) {
	this->font = font;
	this->readPlayersData();
}

void TopPage::readPlayersData() {
	std::string path = "users";

	for (const auto& file : std::filesystem::directory_iterator(path)) {
		std::string fileName(file.path().filename().string());
		fileName = fileName.substr(0, fileName.find("."));
		
		std::ifstream file("users/" + fileName + ".txt");
		std::string line;
		file >> line;
		int bestScore = std::stoi(line);
		Player player(fileName, 0);
		player.setPlayerBestScore(bestScore);
		this->players.push_back(player);
	}

}

void TopPage::setEvent(sf::Event ev) {
	this->backButton->handleEvents(ev);

	this->displayContent();
}

void TopPage::displayContent() {
	TextWriter* tw1 = new TextWriter("Top players", 17, this->font, this->window->getWidth() / 2, 200);
	this->window->drawText(tw1->text);

	int playersSize = this->players.size();

	if (playersSize > 5) playersSize = 5;

	sort(players.begin(), players.end(), [](Player& p1, Player& p2) {
		return p1.getPlayerBestScore() > p2.getPlayerBestScore();
	});

	std::vector<TextWriter*> writers;

	for (int i = 0; i < playersSize; ++i) {
		std::string msg = std::to_string(i + 1) + ". " + players[i].getPlayerName() + " - " + std::to_string(players[i].getPlayerBestScore());
		TextWriter* tw = new TextWriter(msg, 15, this->font, this->window->getWidth() / 2 - 25, this->startY + i * this->moveY);
		writers.push_back(tw);
	}

	for (int i = 0; i < writers.size(); ++i) {
		this->window->drawText(writers[i]->text);
	}

	delete tw1;

	for (int i = 0; i < writers.size(); ++i) {
		delete writers[i];
	}

}