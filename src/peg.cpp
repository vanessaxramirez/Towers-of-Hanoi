// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "peg.h"

Peg::Peg()
{
    // Default constructor  that initializes all the variables
    mXPeg = 0;
    mYPeg = 0;
    mWidth = 0;
    mHeight = 0;

};

Peg::Peg(double x, double y, double width, double height)
{
    // Set's member varibales to values based off of user input
    mXPeg = x;
    mYPeg = y;
    mWidth = width;
    mHeight = height;
    mPegColor = "BLACK";
};

void Peg::drawPeg (GWindow& gw)
{
    // Drawing thhe pegs
    // Calculates the x coordinate so it's at the center of the bottom of the peg
    int xOfPeg = mXPeg - (mWidth/2);
    // Calculates the y coordinate so it's at the center of the bottom of the peg
    int yOfPeg = mYPeg - mHeight;
    gw.setColor("BLACK");
    gw.fillRect(xOfPeg, yOfPeg, mWidth, mHeight);

    // range based for loop that gets the disks on that peg and draws them on the gwindow
    for (Disk disk : diskObjects )
    {
        disk.drawDisk(gw);
    }
};

void Peg::addDisk(Disk inDisk)
{
    // Sets the x and y coordinates for the peg
    inDisk.setCoordinates(mXPeg, mYPeg - (diskObjects.size() * inDisk.getHeight()));
    // Adds a disk to the end of the vector
    diskObjects.push_back(inDisk);
};

Disk Peg::removeDisk()
{
    // Creating disk object to hold the last disk on the vector
    Disk lastDisk = diskObjects.back();
    // Removes the last disk from the vector
    diskObjects.pop_back();

    // Returns the removed disk from the vector
    return lastDisk;
};