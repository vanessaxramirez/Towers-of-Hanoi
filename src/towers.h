// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once

#include <iostream>
#include "gwindow.h"
#include "disk.h"
#include "peg.h"


    const int dMin = 2;
    const int dMax = 10;
    const long long pauseMin = 1;
    const long long pauseMax = 1000000;
    const int minScreenWidth = 800;
    const int minScreenHeight = 600;
    const int maxScreenWidth = 1710;
    const int maxScreenHeight = 1107;

    // Name:
    //      promptForDisk
    // Input:
    //      None
    // Output:
    //      Removed the last disk on the peg
    // Side Effects:
    //      Checks to make sure its between 2 and 10 disks
    // Summary:
    //      Function prompts user for the amount of disks they want to be in
    //          their program
int promptForDisks();


    // Name:
    //      promptForPegs
    // Input:
    //      Two integers (passed by reference)
    // Output:
    //      None
    // Side Effects:
    //      Checks if the entered numbers are between the valid numbers to enter (1-3)
    // Summary:
    //      Function prompts user for the starting peg and the ending peg
    //
void promptForPegs(int& start, int& end);

    // Name:
    //      promptForPause
    // Input:
    //      None
    // Output:
    //      Returns a value for the amount of time to pause
    // Side Effects:
    //      Checks to make sure the entered number is between the valid min and max
    // Summary:
    //      Prompts for the amount the user wants to pause in between each disk
    //          movement
int promptForPause();

    // Name:
    //      promptForWindowSize
    // Input:
    //      Two integers passeed by reference
    // Output:
    //      None
    // Side Effects:
    //      Checks that the number is valid for the set mmins and max 
    // Summary:
    //      Prompts the user for the width and height of the screen 
    //
void promptForWindowSize(int& width, int& height);

    // Name:
    //      draw
    // Input:
    //      A (reference) gwindow, a (reference) collection of pegs, and an integer
    // Output:
    //      None
    // Side Effects:
    //      Clears the window 
    // Summary:
    //      Draws all the pegs and all the disks that are on each peg
    //
void draw(GWindow& gw, std::vector<Peg>& Pegs, int pauseTime);

    // Name:
    //      moveDisk
    // Input:
    //      A (GWindow object (by reference), the Peg collection (by reference), the starting Peg (represented with an int), the destination Peg
    //          (represented with an int), and the pause length (represented by an int)
    // Output:
    //      None
    // Side Effects:
    //      None
    // Summary:
    //      This fucntion removes the top most disk from the starting peg and moves it to the 
    //          ending peg. It then draws the pegs and moved disks
void moveDisk (GWindow& gw, std::vector<Peg>& Pegs, int start, int end, int pauseTime);
    
    
    // Name:
    //      towerSolver
    // Input:
    //      A GWindow object (by reference), the Peg collection (by reference), the starting Peg (represented
    //         with an int), the destination Peg (represented with an int), the number of disks to move, and the
    //             pause duration
    // Output:
    //      None
    // Side Effects:
    //      Solves towers 
    // Summary:
    //      Creates a temporary peg to move disk from start to temporary peg, then moves the the second on disk on start
    //          to the end peg. then moves the disk on the temporary peg to the end peg
void towerSolver (GWindow& gw, std::vector<Peg>& Pegs, int start, int end, int disksToMove, int pauseTime);


    // Name:
    //      towerRun
    // Input:
    //      None
    // Output:
    //      None
    // Side Effects:
    //      None
    // Summary:
    //      Runs the entire program 
void towerRun();