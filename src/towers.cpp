// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "towers.h"

int promptForDisks()
{
    // Creating new variable to hole the number of disks the user would like on the screen
    int numberOfDisks;
    
    //Prompts user for the number of disks
    std::cout << "Enter the number of disks to start with (2 - 10 disks): ";
    std::cin >> numberOfDisks;

    // While loop to keep prompting hte user if they do not input a valid number
    while (numberOfDisks < dMin || numberOfDisks > dMax)
    {
        std::cout << "Invalid input, try again!"<< std::endl;
        std::cout << "Enter the number of disks to start with (2 - 10 disks):  ";
        std::cin >> numberOfDisks;
    }
    // Returns user input
    return numberOfDisks;
};

void promptForPegs(int& startPeg, int& endPeg)
{
    int start = 0;
    // Prompts user for the starting peg
    std::cout << "Choose a starting peg (1-3):  ";
    std::cin >> start;

    // While loop that checks if entered starting peg is valid
    while (start < 1 || start > 3)
    {
        std::cout << "Choose a starting peg (1-3):  ";
        std::cin >> start;
    }
    // Subtracts 1 from the entered number to fix the indes of each peg
    startPeg = start - 1;

    int end = 0;
    // Prompts user for the ending peg
    std::cout << "Choose an ending peg (1-3):  ";
    std::cin >> end;

    // While loop that checls if entered ending peg is valid
    while (end < 1 || end >3 || end == start)
    {
        std::cout << "Choose an ending peg (1-3):  ";
        std::cin >> end;
    }
    // Subtracts 1 from the entered number to fix the indes of each peg
    endPeg = end - 1;

};

int promptForPause()
{
    // Setting pause to an integer initialized to 0
    int pause = 0;
    // Prompting user for how long they want the pause to be
    std::cout << "How long would you like the pause to be (1 - 1000000)?  ";
    std::cin >> pause;
    
    // Checks to make sure pause is between the pause min and max
    while (pause < pauseMin || pause > pauseMax)
    {
        std::cout << "Invalid input, try again!";
        std::cout << "How long would you like the pause to be (1 - 1000000)?  ";
        std::cin >> pause;
    }

    // Returns the user's entered amount for pause
    return pause;

}

void promptForWindowSize(int& width, int& height)
{   
    // Prompts user for the width they'd like the graphics window
    std::cout << "Enter the width of the graphics window(800 - 1710):  ";
    std::cin >> width;
    
    // Checks if the entered width is between the min and max set in the header file
    while (width < minScreenWidth || width > maxScreenWidth)
    {
    std::cout << "Enter the width of the graphics window(800 - 1710):  ";
    std::cin >> width;
    }

    // Prompts the user for the height they'd like for the graphics window
    std::cout << "Enter the height of the graphics window(600 - 1107):  ";
    std::cin >> height;
    
    // Checks if the entered height is between the min and max set in the header file
    while (height < minScreenHeight || height > maxScreenHeight)
    {
        std::cout << "Invalid input, try again!" << std::endl;
        std::cout << "Enter the height of the graphics window(600 - 1107):  ";
        std::cin >> height;
    }
};

void draw(GWindow& gw, std::vector<Peg>& Pegs, int pauseTime)
{
    // Clears the graphics currently in the window
    gw.clear();
    // For loop that iterates through the pegs and draws the pegs and the disks on those pegs
    for (int i = 0; i < Pegs.size(); i++)
    {
        Pegs[i].drawPeg(gw);
    }
    pause(pauseTime);
}

void moveDisk (GWindow& gw, std::vector<Peg>& Pegs, int start, int end, int pauseTime)
{
    // Creating a temporary disk object to hold the top disk that we remove from the starting peg
    Disk temp = Pegs[start].removeDisk();
    // Adds the temp disk we removed to the ending peg entered by the user
	Pegs[end].addDisk(temp);
    // Draws the pegs and disks that were moved from above
	draw(gw, Pegs, pauseTime);
}

void towerSolver (GWindow& gw, std::vector<Peg>& Pegs, int start, int end, int disksToMove, int pauseTime)
{
    // 
    if (disksToMove == 0)
    {
        return;
    }
    else
    {
        int temp = 3 - (start + end);

        // Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start”
        towerSolver (gw, Pegs, start, temp, disksToMove - 1, pauseTime);

        // Move Disk 0 from “start” to “end”
        moveDisk(gw, Pegs, start, end, pauseTime);

        // Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0
        towerSolver (gw, Pegs, temp, end, disksToMove - 1, pauseTime );
    }
}

void towerRun()
{
    // Initializing start peg, end peg, and the x coordinate of the peg
    int start = 0;
	int end = 0;
	int pegXCoor;

	std::cout << "Welcome to Towers of Hanoi!" << std::endl;

	// Prompting for amount of disks
	int numOfDisks = promptForDisks();
	
	// Prompting for the start and end pegs
	promptForPegs(start, end);

	// Prompting for amount to pause for
	int pauseTime = promptForPause();

    // Initializing screen width and height
	int userScreenWidth = 0;
	int userScreenHeight = 0;

	// Prompting user for window size
	promptForWindowSize(userScreenWidth, userScreenHeight);

	// Setting all pegs' width's and height's 
	int pegWidth = 20;
	int pegHeight = (userScreenHeight - 100);
	
	// Sets the change in x to be a fourth of the enterred window size
	int deltaPX = ((1/4)*userScreenWidth);

    // Creating gwindow with user's input
	GWindow gw(userScreenWidth, userScreenHeight);

	// Vector to hold the peg objects
	std::vector<Peg> PegVector;
	// Creating pegs to have the coordinates based off of user input
	Peg peg2((userScreenWidth/2), userScreenHeight, pegWidth, pegHeight);
	Peg peg1(userScreenWidth/4, userScreenHeight, pegWidth, pegHeight);
	Peg peg3((3 * userScreenWidth)/4, userScreenHeight, pegWidth, pegHeight);

	// Pushing back peg objects into the vector 
	PegVector.push_back(peg1);
	PegVector.push_back(peg2);
	PegVector.push_back(peg3);

    // for loop that iterates through the number of disks
	for (int i = 0; i < numOfDisks; i++)
	{
        // New disk object that created the width and hieght based on the users screen size input
		Disk myDisk(0, 0, ((userScreenWidth/4) - (((userScreenWidth / 4) - 20)/ numOfDisks) * i), 40);
		// Adds disks to the starting peg vector
        PegVector[start].addDisk(myDisk);
	}
    // Draws the pegs and the disks that are on the pegs
	draw(gw, PegVector, pauseTime);

    // Calls tower solver to initiate the recursion for the towers of hanoi
    // Takes in all the parameters we got from the user
	towerSolver(gw, PegVector, start, end, numOfDisks, pauseTime);
    pause(5000);
}