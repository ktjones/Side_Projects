
//*******************************
//
//  Program Outline/Notes Area
//
//*******************************

//*******************************
//
// Modules
//
//*******************************


// Display the Instructions - Complete

// Initializing the Board - Complete

// Displaying The Board - Complete

// Taking Turns - Complete

    // Initial Turn - Complete
        // Create the player array (fixed size)
        // Ask the player how many Monsters and Traps they would like to play against.
        // Determine the initial position of the exit.
        // Determine the initial position of the Player.
        // Determine the initial position of each monster.
        // Determine the initial position of each trap.
        // For each step above, verify that the position isn't already taken by a previous iteration.
        // Set all positions.

    // Regular Play - Player takes turn - Complete
        // Get Player's Current Position (x & y coordinates)
        // Ask Player how to move (u), (d), (l), (r)
        // Determine new position based on current and requested direction
        // Verify that the move is valid - move is still on game board
            // if not valid, then say so, and ask for a new direction.
        // If Valid, and not a win, or a loss - move the player to the new spot.
        // If Valid - Check to see if move is a win (Player Makes it to eXit)
            // if a Win - Break out and end game.  Declare a WIN for the player.
            // Ask if player wants to play again.
        // If Valid, and not a win - Check to see if move is a loss (monster or trap).
            // If a loss - Break out and end game.  Declare a LOSS.

    // Computer takes turn - Complete
        // Get Monster's Current Position (x & y coordinates)
        // Calculate new positions for Monsters (random u,d,l,r)
        // Determine new position based on current and requested direction
        // Verify that move is valid - move is still on game board
            // if not valid, then generate a new random number
        //  Verify that the move is valid - Space is not occupied by the eXit or a Trap.
            // if not valid, then generate a new random number
        // If Valid - Check to see if move is a win (Player Catches Monster)
            // if a Win - Break out and end game.  Declare a WIN for the monster.
            // Ask if player wants to play again.
        // If Valid, and not a win - Check to see if move is a loss (monster or trap).
            // If a loss - Break out and end game.  Declare a LOSS.
        // If Valid, and not a win, or a loss - move the player to the new spot.

// Evaluate the Results
    // Determine if the game has been won or lost by the player.
    // Declare accordingly.
    // Ask if the player wants to play another game.
        // if yes - start over.
        // if not - end the game.

