// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once

#include "disk.h"
#include "gwindow.h"
#include <ctime>

class Disk
{
private:
    // Member Variables
    // Stores the X - Coordinate
    double mXCoordinate;
    // Stores the Y - Coordinate
    double mYCoordinate;
    // Stores the Width
    double mDiskWidth;
    // Stores the Height
    double mDiskHeight;
    // Stores the Disk Color 
    std::string mDiskColor;

public:
    // Constructors 
    // Default constructor holding default values of 0
    Disk();
    // Creating constructor to take in the user's input
    Disk(double x, double y, double width, double height);

    // Setters
    // Sets the x and y coordinates each time it's called
    void setCoordinates (double inXCoor, double inYCoor);

    // Getters
    // Returns the height of the disk
    // marked const to ensure the value of the member variable cannot be changed 
    double getHeight() const;

    // Name: 
    //      drawDisk
    // Input:
    //      1. A (reference) GWindow to be drawn on
    // Output:
    //      None
    // Side Effects:
    //      Draws disk in the GWindow
    // Summary:
    //      Calculates the coordinates of X and Y so they're centered, 
    //        sets the color of the rectangle, draws the disk and a black border around it
    void drawDisk (GWindow& gw);

    
};