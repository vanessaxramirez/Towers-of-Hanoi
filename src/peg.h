// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once

#include <iostream>
#include "gwindow.h"
#include "disk.h"

class Peg
{

private:
    // Member Variables

    // Holds the disk objects that are on the current peg
    std::vector<Disk> diskObjects;
    //Stores the X-Coordinate for peg
    double mXPeg;
    // Stores the Y-Coordinate for peg
    double mYPeg;
    // Stores the width for peg
    double mWidth;
    // Stores the height for peg
    double mHeight;
    // Stores the color of the peg
    std::string mPegColor;

    
public:
    // Constructors

    // Default Constructor
    Peg();
    // Constructor to set the x, y, width, and height
    // Also sets the color of all the pegs
    Peg(double x, double y, double width, double height);

    // Name:
    //      drawPeg
    // Input:
    //      A (reference) gwindow to be drawn on 
    // Output:
    //      None
    // Side Effects:
    //      Draws the disks on that peg
    // Summary:
    //      Draws the peg and loops through a range baased for loop to draw 
    //          all of the disks that are on the peg
    void drawPeg(GWindow& gw);

    // Name:
    //      addDisk
    // Input:
    //      A disk object
    // Output:
    //      None
    // Side Effects:
    //      Adds a disk to the vector of disks
    // Summary:
    //      This member function takes a disk opject as input and adjusts its coordinates
    //          It then pushes this disk object back into a vector 
    void addDisk(Disk disk);

    // Name:
    //      removeDisk
    // Input:
    //      None
    // Output:
    //      A disk object
    // Side Effects:
    //      Removes the last disk on the peg
    // Summary:
    //      This member function removes the last disk object place on
    //          that peg and returns it
    Disk removeDisk();
};