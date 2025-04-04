// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "disk.h"

Disk::Disk()
{
    // Creates default variables to initialize variables 
    mXCoordinate = 0;
    mYCoordinate = 0;
    mDiskWidth = 0;
    mDiskHeight = 0;
    mDiskColor = "CYAN";

}

Disk::Disk(double x, double y, double width, double height)
{
    // Set's member varibales to values based off of user input
    mXCoordinate = x;
    mYCoordinate = y;
    mDiskWidth = width;
    mDiskHeight = height;
    mDiskColor = "CYAN";

}

void Disk::setCoordinates (double inXCoor, double inYCoor)
{
    // Setter funtion to set the x and y coordinates of each disk/ update the coordinates each time it's called
    mXCoordinate = inXCoor;
    mYCoordinate = inYCoor;
}

double Disk::getHeight() const
{
    // Gets the disk height and returns it to be used elsewhere
    return mDiskHeight;
}

void Disk::drawDisk (GWindow& gw)
{
    // Creating temp variables to hold the calculations 
    // Calculates and centers the disk's x coordinate by subtracting half the width of the disk from the x coordinate
    double drawX = mXCoordinate - (mDiskWidth/2);
    // Calculates the y coordinate to the the at the bottom of the disk, thus why we subtract the height of the disk from the y coordinate
    double drawY = mYCoordinate - mDiskHeight;
    
    // Setting the color for each disk
	gw.setColor("CYAN");
    //Drawing and filling the rectangle based off of the calculations and the user's input
	gw.fillRect (drawX, drawY, mDiskWidth, mDiskHeight);
    // Setting color to black for the border
    gw.setColor("BLACK");
    // Drawing the border around each disk
    gw.drawRect (drawX, drawY, mDiskWidth, mDiskHeight);
}