#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
#include<time.h>
#include"Menu.h"
#include"retryMenu.h"

#include<utility>
#include<fstream>
#include<sstream>
#include<algorithm>


int section_number = 1;

int main()
{
	sf::String Input;
	int a = 0;


	while (true)
	{
		//menu//
		if (section_number == 1)
		{
			sf::SoundBuffer bgBuffer;
			sf::Sound bgSound;
			bgBuffer.loadFromFile("Sound/Beyond - Patrick Patrikios.wav");
			bgSound.setBuffer(bgBuffer);
			bgSound.setVolume(3);
			bgSound.play();
			bgSound.setLoop(true);

			sf::SoundBuffer  select;
			sf::Sound  selectSound;
			select.loadFromFile("Sound/Bub.wav");
			selectSound.setBuffer(select);
			selectSound.setVolume(30.0);

			sf::RenderWindow window(sf::VideoMode(1280, 720), "GameR");
			Menu menu(window.getSize().x, window.getSize().y);
			sf::Texture Mtexture;
			Mtexture.loadFromFile("Texture/M2.png");

			sf::Sprite Mbackground;
			Mbackground.setTexture(Mtexture);
			Mbackground.setPosition(0, 0);
			Mbackground.setScale(1.45f, 1.2f);

			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
						window.close();
						return 0;
					}
					switch (event.type)
					{
					case sf::Event::KeyPressed:
						switch (event.key.code)
						{
						case sf::Keyboard::W:
							selectSound.play();
							menu.MoveUp();
							break;
						case sf::Keyboard::S:
							selectSound.play();
							menu.MoveDown();
							break;
						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
							case 0:
								section_number = 4;
								std::cout << "Play button has been pressed" << std::endl;
								window.close();
								break;
							case 1:
								section_number = 5;
								window.close();
								break;
							case 2:
								section_number = 5;
								return 0;

							}
						}
					}
				}

				window.clear();
				window.draw(Mbackground);
				menu.draw(window);
				window.display();
			}
		}
		
		//game
		if (section_number == 2)
		{
			//game
			Game game;
			game.run();

			FILE* fp;
			char temp[255];
			int score[6];
			std::string names[6];
			std::vector <std::pair<int, std::string>> userScore;

			fp = fopen("./Score.txt", "r");

			for (int i = 0; i < 5; i++)
			{
				fscanf(fp, "%s", &temp);
				names[i] = temp;
				fscanf(fp, "%d", &score[i]);
				userScore.push_back(std::make_pair(score[i], names[i]));
			}

			names[5] = Input;
			score[5] = game.getScore();
			userScore.push_back(std::make_pair(score[5], names[5]));
			sort(userScore.begin(), userScore.end());

			fclose(fp);
			fopen("./Score.txt", "w");

			for (int i = 5; i >= 1; i--)
			{
				strcpy_s(temp, userScore[i].second.c_str());
				fprintf(fp, "%s %d\n", temp, userScore[i].first);
			}
			fclose(fp);
			section_number = 3;
		}

		//restart//
		if (section_number == 3)
		{


			sf::SoundBuffer bgBuffer;
			sf::Sound bgSound;
			bgBuffer.loadFromFile("Sound/Sad Violin.wav");
			bgSound.setBuffer(bgBuffer);
			bgSound.setVolume(6);
			bgSound.play();
			bgSound.setLoop(true);

			sf::SoundBuffer  select;
			sf::Sound  selectSound;
			select.loadFromFile("Sound/Bub.wav");
			selectSound.setBuffer(select);
			selectSound.setVolume(10.0);

			sf::RenderWindow window(sf::VideoMode(1000, 700), "GameR");
			retryMenu retrymenu(window.getSize().x, window.getSize().y);

			sf::Texture Rtexture;
			Rtexture.loadFromFile("Texture/main.jpg");

			sf::Sprite Rbackground;
			Rbackground.setTexture(Rtexture);
			Rbackground.setScale(1.7f, 1.55f);

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
					{
						window.close();
						return 0;
					}
					switch (event.type)
					{
					case sf::Event::KeyPressed:
						switch (event.key.code)
						{
						case sf::Keyboard::W:
							selectSound.play();
							retrymenu.MoveUp();
							break;
						case sf::Keyboard::S:
							selectSound.play();
							retrymenu.MoveDown();
							break;
						case sf::Keyboard::Return:
							switch (retrymenu.GetPressedItem())
							{
							case 0:

								section_number = 2;
								window.close();
								break;

							case 1:
								section_number = 1;
								window.close();
								break;

							}
						}
					}
				}
				window.clear();
				window.draw(Rbackground);
				retrymenu.draw(window);
				window.display();
			}
		}

		//input name//
		if (section_number == 4)
		{
			sf::SoundBuffer  click;
			sf::Sound  clickSound;
			click.loadFromFile("Sound/Mouse click.wav");
			clickSound.setBuffer(click);
			clickSound.setVolume(30.0);

			sf::RenderWindow window(sf::VideoMode(1000, 720), "GameR", sf::Style::Close);
			sf::Texture texture;
			sf::Texture btexture;
			sf::Texture boxtexture;

			sf::Text Text;
			if (!texture.loadFromFile("Texture/inputPilot.png"));
			{
				//handle error
			}
			if (!btexture.loadFromFile("Texture/realbackground.png"));
			{
				//handle error
			}
			if (!boxtexture.loadFromFile("Texture/Message Box.png"));
			{
				//handle error
			}
			sf::Sprite background;
			background.setTexture(texture);
			background.setPosition(10.f, 10.f);
			background.setScale(0.6f, 0.6f);

			sf::Sprite box;
			box.setTexture(boxtexture);
			box.setPosition(window.getSize().x / 2 - 60 + 200, window.getSize().y / 2);
			box.setScale(1.5f, 1.f);


			sf::Sprite bbackground;
			bbackground.setTexture(btexture);
			bbackground.setPosition(0.f, 0.f);
			bbackground.setScale(1.5f, 1.5f);
			
			sf::Font font;
			font.loadFromFile("Fonts/Dosis-Light.ttf");
			Text.setPosition(window.getSize().x / 2 - 50 + 200, window.getSize().y / 2);
			Text.setCharacterSize(70);
			Text.setFillColor(sf::Color::Black);
			Text.setFont(font);


			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::TextEntered)
					{
						clickSound.play();
						if (event.text.unicode < 128)
						{
							if (event.text.unicode == static_cast <sf::Uint32>(8) && Input.getSize() > 0)
							{
								Input.erase(Input.getSize() - 1);
							}
							else
							{
								if (Input.getSize() < 7 && event.text.unicode != 13)
								{
									if (event.text.unicode == 32)
									{
										event.text.unicode = 95;
									}
									Input += event.text.unicode;
								}
							}
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Input.getSize() >= 1)
				{
					section_number = 2;
					window.close();
					break;
				}
				window.clear();
				Text.setString(Input);
				window.draw(bbackground);
				window.draw(background);
				window.draw(box);
				window.draw(Text);
				window.display();
			}


		}

		//scoreboard//
		if (section_number == 5)
		{
			sf::SoundBuffer bgBuffer;
			sf::Sound bgSound;
			bgBuffer.loadFromFile("Sound/Beyond - Patrick Patrikios.wav");
			bgSound.setBuffer(bgBuffer);
			bgSound.setVolume(3);
			bgSound.play();
			bgSound.setLoop(true);

			sf::RenderWindow window(sf::VideoMode(1280, 720), "GameR", sf::Style::Close);
			sf::Sprite background;
			sf::Sprite bbackground;

			sf::Font font;
			font.loadFromFile("Fonts/Dosis-Light.ttf");

			sf::Texture texture;
			sf::Texture bbtexture;
			std::string Name[6];
			sf::Text Text;
			sf::Text PlayerName[6];
			sf::Text PlayerScore[6];

			FILE* fp;
			char temp[255];
			int score[6];

			std::vector <std::pair<int, std::string>> userScore;

			fp = fopen("./Score.txt", "r");
			for (int i = 0; i < 5; i++)
			{
				fscanf(fp, "%s", &temp);
				Name[i] = temp;
				PlayerName[i].setString(Name[i]);
				fscanf(fp, "%d", &score[i]);
				PlayerScore[i].setString(std::to_string(score[i]));
				userScore.push_back(std::make_pair(score[i], Name[i]));
			}

			for (int i = 0; i < 5; i++)
			{
				PlayerName[i].setFont(font);
				PlayerName[i].setCharacterSize(50);
				PlayerName[i].setFillColor(sf::Color::Red);
				PlayerName[i].setPosition(window.getSize().x / 2 + 200, window.getSize().y / 2 - 250 + (80 * i));
				PlayerScore[i].setFont(font);
				PlayerScore[i].setCharacterSize(50);
				PlayerScore[i].setFillColor(sf::Color::Red);
				PlayerScore[i].setPosition(window.getSize().x / 2 + 450, window.getSize().y / 2 - 250 + (80 * i));
			}

			if (!texture.loadFromFile("Texture/HeliPilot.png"));
			{
				//handle error
			}
			background.setTexture(texture);
			background.setPosition(-90.f, -80.f);
			background.setScale(0.8f, 0.8f);

			if (!bbtexture.loadFromFile("Texture/background1.jpg"));
			{
				//handle error
			}
			bbackground.setTexture(bbtexture);
			bbackground.setPosition(0.f, 0.f);
			bbackground.setScale(0.8f, 0.8f);

			Text.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);
			Text.setCharacterSize(25);
			Text.setFont(font);
			Text.setOutlineThickness(3.f);
			Text.setOutlineColor(sf::Color::White);

			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					section_number = 1;
					window.close();
					break;
				}
				window.clear();
				window.draw(bbackground);
				window.draw(background);
				for (int i = 0; i < 5; i++)
				{
					window.draw(PlayerName[i]);
					window.draw(PlayerScore[i]);
				}
				window.display();
			}

		}

	}

	//end app
	return 0;
}