/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Test; Contains a class that holds our 5 test cases
 ******************************************************************************/

#include "test.hpp"

 /*************************************************************
 * Function: testMovement
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: tests the movement of the character
 * Input parameters: void
 * Returns:	void
 *************************************************************/
void testMovement() {
	/* Opens window for test function to run in */
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");

	/* Centers camera */
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);

	/* Initializes player for user to move */
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);

	/* Initialize Events object for movement function */
	Events e;

	/* Loop for running test */
	while (mWindow.isOpen()) {

		/* Drawing player */
		mWindow.draw(p1);

		/* Function for moving player around */
		e.movementInput(mWindow, p1);

		/* If statement to leave test function */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			mWindow.close();
		}

		/* Displaying Next Frame */
		mWindow.display();
	}

	/* Clear window to return to menu */
	mWindow.clear();
}
/*************************************************************
* Function: testFalling
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the falling movement
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testFalling() {
	/* Opens window for test function to run in */
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");

	/* Centers camera */
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);

	/* Initializes player for user to move */
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);

	/* Initialize text to display for end screen */
	sf::Text text;
	sf::Font myFont;
	myFont.loadFromFile("Whimsy.ttf");
	text.setPosition(325, 400);
	text.setCharacterSize(50);
	text.setFont(myFont);
	text.setString("GAME OVER");

	/* Initialize actions object for end game checking function */
	Actions a;

	/* Loop for running test */
	while (mWindow.isOpen()) {

		/* Drawing player */
		mWindow.draw(p1);

		/* Moving player down to simulate gravity */
		p1.move(0, 0.1);

		/* Uses bottom of window to decide if player is "dead" returns true if above y = 1000*/
		a.endGame(p1);

		/* Checks if end game returns true, meaning player is "dead" */
		if (a.endGame(p1) == true) {

			/* Draw end game screen */
			mWindow.draw(text);
		}

		/* If statement to leave test function */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			/* Closes window to end loop */
			mWindow.close();
		}

		/* Displaying Next Frame */
		mWindow.display();
	}

	/* Clear window to return to menu */
	mWindow.clear();
}

/*************************************************************
* Function: testAlien
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of an alien
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testAlien() {
	/* Opens window for test function to run in */
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");

	/* Centers camera */
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);

	/* Initializes player for user to move */
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);

	/* Initializes Alien for player to collide into and check if player dies or not from colliding with alien */
	sf::Texture tAlien;
	sf::Vector2f posAlien(1090, 1090);
	tAlien.loadFromFile("Alien.png");
	Alien a1(posAlien, tAlien);

	/* Initialize text to display for end screen */
	sf::Text text;
	sf::Font myFont;
	myFont.loadFromFile("Whimsy.ttf");
	text.setPosition(325, 400);
	text.setCharacterSize(50);
	text.setFont(myFont);
	text.setString("GAME OVER");

	/* Initialize Events object for movement function */
	Events e;

	/* Initialize actions object for end game checking function */
	Actions a;

	/* Set alien original position */
	a1.setPosition(500, 500);

	/* Set player original position */
	p1.setPosition(500, 800);

	/* Loop for running test */
	while (mWindow.isOpen()) {

		/* When player and alien are not colliding, move the player towards the alien */
		if (!p1.getGlobalBounds().intersects(a1.getGlobalBounds())) {
			p1.move(0, -0.1);
		}

		/* Draw player */
		mWindow.draw(p1);

		/* Draw Alien */
		mWindow.draw(a1);

		/* Function to move player down into death plane if colliding with alien */
		e.deathByAlien(p1, a1);

		/* Uses bottom of window to decide if player is "dead" returns true if above y = 1000*/
		a.endGame(p1);

		/* Checks if end game returns true, meaning player is "dead" */
		if (a.endGame(p1) == true) {

			/* Draw end game screen */
			mWindow.draw(text);
		}

		/* If statement to leave test function */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			/* Closes window and ends loop*/
			mWindow.close();
		}

		/* Displaying Next Frame */
		mWindow.display();
	}
	mWindow.clear();
}

/*************************************************************
* Function: testPlatform
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of a single platform
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testPlatform() {
	/* Opens window for test function to run in */
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");

	/* Centers camera */
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);

	/* Initializes player for user to move */
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);

	/* Initialize text to display for end screen */
	sf::Text text;
	sf::Font myFont;
	myFont.loadFromFile("Whimsy.ttf");
	text.setPosition(325, 400);
	text.setCharacterSize(50);
	text.setFont(myFont);
	text.setString("GAME OVER");

	/* Initialize platform */
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	sf::Vector2f size(100.0f, 20.0f);
	sf::Vector2f position((rand() % 800), 0.0f);
	sf::Color green = sf::Color::Green;
	Platform plat1(size, position, green, t1);

	/* Initialize PlatformGenerator object for checking platform collision function */
	PlatformGenerator pg(t1);

	/* Sets platform origin */
	plat1.setPosition(500, 800);

	/* Sets player origin */
	p1.setPosition(500, 500);

	/* Loop for running test */
	while (mWindow.isOpen()) {

		/* Draws player */
		mWindow.draw(p1);
		/* Draws platform */
		mWindow.draw(plat1);

		/* Moves player down to platform if not intersecting */
		if (!p1.getGlobalBounds().intersects(plat1.getGlobalBounds())) {
			p1.move(0, 0.1);
		}

		/* Platform collision function returns true if player and platform collide */
		pg.checkPlatformCollsion(p1);

		/* If statement for if platform and player collide */
		if (pg.checkPlatformCollsion(p1) == true) {

			/* Displays instructions to exit test function */
			mWindow.draw(text);
		}

		/* If statement to close test function */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			/* Window closes and loop ends */
			mWindow.close();
		}

		/* Display next frame */
		mWindow.display();
	}

	/* Clear screen and go back to menu */
	mWindow.clear();
}

/*************************************************************
 * Function: testGeneratePlat
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: tests the generation of multiple platforms
 * Input parameters: void
 * Returns:	void
 *************************************************************/
void Test::testGeneratePlat() {
	/* Opens window for test function to run in */
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");

	/* Centers camera */
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);

	/* Initialize text to display for generating new platform */
	sf::Text text;
	sf::Font myFont;
	myFont.loadFromFile("Whimsy.ttf");
	text.setPosition(325, 400);
	text.setCharacterSize(50);
	text.setFont(myFont);
	text.setString("PRESS SPACE");

	/* Initialize PlatformGenerator object for generating new platform collision function */
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	PlatformGenerator pg(t1);

	/* Loop for running test */
	while (mWindow.isOpen()) {

		/* Draw instructions to make new platform */
		mWindow.draw(text);

		/* If statement to generate new platform */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			/* Generate new platform using generateNew function */
			Platform plat = pg.generateNew(t1);

			/* Draws new platform */
			mWindow.draw(plat);

			/* Set words to text to instruction to exit test function */
			text.setString("PRESS ESCAPE");

			/* Draw text */
			mWindow.draw(text);

			/* If statement to leave test function */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				mWindow.close();
			}

			/* Display next frame*/
			mWindow.display();
		}
	}

	/* Clear screen to go back to main menu */
	mWindow.clear();
}