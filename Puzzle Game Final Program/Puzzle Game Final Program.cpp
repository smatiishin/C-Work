/* Sam Matiishin
CSC 223
Puzzle Gamw Final Program*/

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

// Initialize board sizes
const int ROW1 = 10;
const int ROW2 = 20;
const int ROW3 = 30;
const int COL1 = 10;
const int COL2 = 20;
const int COL3 = 30;

/* Function name: createEasyBoard()
   Function parameter: char
   Return: None
   Description: This function generates an easy difficulty board by building a board using a 2-dimensional array as a parameter
 */
void createEasyBoard(char easyBoard[ROW1][COL1]) {
    for (char i = 0; i < ROW1; i++)
    {
        for (char j = 0; j < COL1; j++)
        {
            cout << easyBoard[i][j] << " ";
        }

        cout << endl;
    }
}

/* Function name: createNormalBoard()
   Function parameter: char
   Return: None
   Description: This function generates a normal difficulty board by building a board using a 2-dimensional array as a parameter
 */
void createNormalBoard(char normalBoard[ROW2][COL2]) {
    for (char i = 0; i < ROW2; i++)
    {
        for (char j = 0; j < COL2; j++)
        {
            cout << normalBoard[i][j] << " ";
        }

        cout << endl;
    }
}

/* Function name: createHardBoard()
   Function parameter: char
   Return: None
   Description: This function generates a hard difficulty board by building a board using a 2-dimensional array as a parameter
 */
void createHardBoard(char hardBoard[ROW3][COL3]) {
    for (char i = 0; i < ROW3; i++)
    {
        for (char j = 0; j < COL3; j++)
        {
            cout << hardBoard[i][j] << " ";
        }

        cout << endl;
    }
}

/* Function name: generateRandomCoordinate()
   Function parameter: int
   Return: int
   Description: This function generates a random number, and uses this number to set a coordinate for CPUs and treasure
 */
int generateRandomCoordinate(int difficulty)
{
    // Initialize objects and variables
    int value = 0;

    // This is used to randomize the numbers
    srand(time(0));

    // Determine random coordinates based off the difficulty set
    if (difficulty == 1)
    {
        value = rand() % 9 + 1;
        return value;
    }
    else if (difficulty == 2)
    {
        value = rand() % 19 + 1;
        return value;
    }
    else {
        value = rand() % 29 + 1;
        return value;
    }

    return value;
}

/* Function name: userOption()
   Function parameter: none
   Return: int
   Description: This function obtains a user input for the difficulty level
 */
int userOption()
{
    // Initialize objects and variables
    int userChoice;

    // Obtain difficulty input
    cout << "Please enter the difficulty (1, easy), (2, normal), (3, hard - full screen terminal recommended): " << endl;
    cin >> userChoice;
    if (userChoice == 1 || userChoice == 2 || userChoice == 3)
    {
        return userChoice;
    }

    // There was an error, so ask the user again for the input
    cout << "Invalid Choice" << endl;
    userOption();
}

/* Function name: generateCpuDirection()
   Function parameter: none
   Return: char
   Description: This function generates a direction for Cpus, used with movements() function
 */
char generateCpuDirection()
{
    // Initialize objects and variables
    char direction;

    // Select a movement direction at random
    int randomNum = rand() % 4 + 1;
    if (randomNum == 1)
    {
        direction = 'w';
    }
    else if (randomNum == 2)
    {
        direction = 'a';
    }
    else if (randomNum == 3)
    {
        direction = 's';
    }
    else
    {
        direction = 'd';
    }
    return direction;
}

/* Function name: movements()
   Function parameter: char, int*, int*, int
   Return: none
   Description: This function determines a movement for the user and Cpus
 */
void movements(char direction, int* x, int* y, int difficulty)
{
    // Check the difficulty level
    if (difficulty == 1)
    {
        // Check to see if a movement is valid (within playing space)
        if (direction == 'w')
        {
            if (x != 0)
            {
                *x = *x - 1;
            }
        }
        else if (direction == 'a')
        {
            if (y != 0)
            {
                *y = *y - 1;
            }
        }
        else if (direction == 's')
        {
            if (*x != ROW1 - 1)
            {
                *x = *x + 1;
            }
        }
        else if (direction == 'd')
        {
            if (*y != COL1 - 1)
            {
                *y = *y + 1;
            }
        }
        else
        {
            ;
        }

    }
    else if (difficulty == 2)
    {
        if (direction == 'w')
        {
            if (x != 0)
            {
                *x = *x - 1;
            }
        }
        else if (direction == 'a')
        {
            if (y != 0)
            {
                *y = *y - 1;
            }
        }
        else if (direction == 's')
        {
            if (*x != ROW2 - 1)
            {
                *x = *x + 1;
            }
        }
        else if (direction == 'd')
        {
            if (*y != COL2 - 1)
            {
                *y = *y + 1;
            }
        }
        else
        {
            ;
        }
    }
    else 
    {
        if (direction == 'w')
        {
            if (x != 0)
            {
                *x = *x - 1;
            }
        }
        else if (direction == 'a')
        {
            if (y != 0)
            {
                *y = *y - 1;
            }
        }
        else if (direction == 's')
        {
            if (*x != ROW3 - 1)
            {
                *x = *x + 1;
            }
        }
        else if (direction == 'd')
        {
            if (*y != COL3 - 1)
            {
                *y = *y + 1;
            }
        }
        else
        {
            ;
        }
    }

}

// Primary function that executes the main program
int main()
{
    // Initialize objects and variables
    int userChoice = userOption();

    // Determine difficulty based off user input
    if (userChoice == 1)
    {
        // Initialize objects and variables
        bool endLoop = false;
        char easyBoard[ROW1][COL1];

        // Initialize a board with easy dimensions
        for (int i = 0; i < ROW1; i++)
        {
            for (int j = 0; j < COL1; j++)
            {
                easyBoard[i][j] = '.';
            }
        }

        // Generate coordinates for player
        int xCoordinate = 0;
        int yCoordinate = 0;

        // Generate coordinates for first enemy
        int xCoordinate1 = generateRandomCoordinate(userChoice);
        int yCoordinate1 = generateRandomCoordinate(userChoice);

        // Generate coordinates for second enemy
        int xCoordinate2 = generateRandomCoordinate(userChoice);
        int yCoordinate2 = generateRandomCoordinate(userChoice);

        // Generate coordinates for treasure
        int xCoordinate3 = generateRandomCoordinate(userChoice);
        int yCoordinate3 = generateRandomCoordinate(userChoice);

        // Protect against spawning on other enemy or treasure
        while (xCoordinate1 == xCoordinate2 && yCoordinate1 == yCoordinate2 || xCoordinate1 == xCoordinate3 && yCoordinate1 == yCoordinate3 || xCoordinate2 == xCoordinate3 && yCoordinate2 == yCoordinate3)
        {
            xCoordinate1 = generateRandomCoordinate(userChoice);
            yCoordinate1 = generateRandomCoordinate(userChoice);
            xCoordinate2 = generateRandomCoordinate(userChoice);
            yCoordinate2 = generateRandomCoordinate(userChoice);
        }

        // Protect against spawning on user
        while (xCoordinate1 == 0 && yCoordinate1 == 0 || xCoordinate2 == 0 && yCoordinate2 == 0 || xCoordinate3 == 0 && yCoordinate3 == 0)
        {
            xCoordinate1 = generateRandomCoordinate(userChoice);
            yCoordinate1 = generateRandomCoordinate(userChoice);
            xCoordinate2 = generateRandomCoordinate(userChoice);
            yCoordinate2 = generateRandomCoordinate(userChoice);
        }
        
        // Create characters for each object (enemy - T, user - G, treasure - X)
        easyBoard[xCoordinate][yCoordinate] = 'G';
        easyBoard[xCoordinate1][yCoordinate1] = 'T';
        easyBoard[xCoordinate2][yCoordinate2] = 'T';
        easyBoard[xCoordinate3][yCoordinate3] = 'X';

        // Create the easy board with new objects added
        createEasyBoard(easyBoard);

        // Loop that continuously executes the game until the user wins or loses
        while (endLoop == false)
        {
            // Initialize objects and variables
            char direction;
            
            // Obtain user choice for a movement
            cout << "The options are w,a,s,d(w, move up)(a, move left)(s, move down)(d, move right)" << endl;
            cout << "Enter your choice: " << endl;
            cin >> direction;

            // Initialize objects for the easy board (enemy, user, Cpu)
            easyBoard[xCoordinate][yCoordinate] = '.';
            easyBoard[xCoordinate1][yCoordinate1] = '.';
            easyBoard[xCoordinate2][yCoordinate2] = '.';
            easyBoard[xCoordinate3][yCoordinate3] = '.';

            // Execute user movement
            movements(direction, &xCoordinate, &yCoordinate, userChoice);

            // Obtain random direction for Cpu1 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate1, &yCoordinate1, userChoice);

            // Obtain random direction for Cpu2 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate2, &yCoordinate2, userChoice);

            // Protect against overlapping on other enemy or treasure
            while (xCoordinate1 == xCoordinate2 && yCoordinate1 == yCoordinate2 || xCoordinate1 == xCoordinate3 && yCoordinate1 == yCoordinate3 || xCoordinate2 == xCoordinate3 && yCoordinate2 == yCoordinate3)
            {
                movements(direction, &xCoordinate1, &yCoordinate1, userChoice);
                movements(direction, &xCoordinate2, &yCoordinate2, userChoice);
            }

            // Check if player has reached treasure, if true, end the program
            if (xCoordinate == xCoordinate3 && yCoordinate == yCoordinate3)
            {
                cout << "Congrats, you won!" << endl;
                endLoop = true;
            }

            // Check if player was caught by enemy, if true, end the program
            else if (xCoordinate == xCoordinate1 && yCoordinate == yCoordinate1 || xCoordinate == xCoordinate2 && yCoordinate == yCoordinate2 || xCoordinate == xCoordinate3 && yCoordinate == yCoordinate3)
            {
                cout << "Tough, you lost" << endl;
                endLoop = true;
            }

            // Create characters for each object (enemy - T, user - G, treasure - X)
            easyBoard[xCoordinate][yCoordinate] = 'G';
            easyBoard[xCoordinate1][yCoordinate1] = 'T';
            easyBoard[xCoordinate2][yCoordinate2] = 'T';
            easyBoard[xCoordinate3][yCoordinate3] = 'X';

            // Update the easy board with new objects added
            createEasyBoard(easyBoard);
        }

    }
    else if (userChoice == 2)
    {
        // Initialize objects and variables
        bool endLoop = false;
        char normalBoard[ROW2][COL2];

        // This is used to randomize the numbers
        srand(time(0));

        // Initialize board with normal dimensions
        for (int i = 0; i < ROW2; i++)
        {
            for (int j = 0; j < COL2; j++)
            {
                normalBoard[i][j] = '.';
            }
        }

        // Generate coordinates for player
        int xCoordinate = 0;
        int yCoordinate = 0;
        // Generate coordinates for first enemy
        int xCoordinate1 = 10;
        int yCoordinate1 = 10;

        // Generate coordinates for second enemy
        int xCoordinate2 = 12;
        int yCoordinate2 = 12;

        // Generate coordinates for third enemy
        int xCoordinate3 = 11;
        int yCoordinate3 = 11;

        // Generate coordinates for fourth enemy
        int xCoordinate4 = 13;
        int yCoordinate4 = 13;

        // Generate coordinates for fifth enemy
        int xCoordinate5 = 14;
        int yCoordinate5 = 14;

        // Generate coordinates for sixth enemy
        int xCoordinate6 = 15;
        int yCoordinate6 = 15;

        // Generate coordinates for treasure
        int xCoordinate7 = 16;
        int yCoordinate7 = 16;

        // Create characters for each object (enemy - T, user - G, treasure - X)
        normalBoard[xCoordinate][yCoordinate] = 'G';
        normalBoard[xCoordinate1][yCoordinate1] = 'T';
        normalBoard[xCoordinate2][yCoordinate2] = 'T';
        normalBoard[xCoordinate3][yCoordinate3] = 'T';
        normalBoard[xCoordinate4][yCoordinate4] = 'T';
        normalBoard[xCoordinate5][yCoordinate5] = 'T';
        normalBoard[xCoordinate6][yCoordinate6] = 'T';
        normalBoard[xCoordinate7][yCoordinate7] = 'X';

        // Update the normal board with objects added
        createNormalBoard(normalBoard);

        // Loop that continuously executes the game until the user wins or loses
        while (endLoop == false)
        {
            // Initialize objects and variables
            char direction;

            // Obtain user input for a movement
            cout << "The options are w,a,s,d(w, move up)(a, move left)(s, move down)(d, move right)" << endl;
            cout << "Enter your choice: " << endl;
            cin >> direction;

            // Initialize objects for the normal board (enemy, user, Cpu)
            normalBoard[xCoordinate][yCoordinate] = '.';
            normalBoard[xCoordinate1][yCoordinate1] = '.';
            normalBoard[xCoordinate2][yCoordinate2] = '.';
            normalBoard[xCoordinate3][yCoordinate3] = '.';
            normalBoard[xCoordinate4][yCoordinate4] = '.';
            normalBoard[xCoordinate5][yCoordinate5] = '.';
            normalBoard[xCoordinate6][yCoordinate6] = '.';
            normalBoard[xCoordinate7][yCoordinate7] = '.';

            // Execute user movement
            movements(direction, &xCoordinate, &yCoordinate, userChoice);

            // Obtain random direction for Cpu1 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate1, &yCoordinate1, userChoice);

            // Obtain random direction for Cpu2 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate2, &yCoordinate2, userChoice);

            // Obtain random direction for Cpu3 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate3, &yCoordinate3, userChoice);

            // Obtain random direction for Cpu4 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate4, &yCoordinate4, userChoice);

            // Obtain random direction for Cpu5 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate5, &yCoordinate5, userChoice);

            // Obtain random direction for Cpu6 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate6, &yCoordinate6, userChoice);



            // Protect against overlapping on other enemy or treasure
            while (xCoordinate1 == xCoordinate2 && yCoordinate1 == yCoordinate2 ||
                xCoordinate1 == xCoordinate3 && yCoordinate1 == yCoordinate3 ||
                xCoordinate1 == xCoordinate4 && yCoordinate1 == yCoordinate4 ||
                xCoordinate1 == xCoordinate5 && yCoordinate1 == yCoordinate5 ||
                xCoordinate1 == xCoordinate6 && yCoordinate1 == yCoordinate6 ||
                xCoordinate1 == xCoordinate7 && yCoordinate1 == yCoordinate7 ||
                xCoordinate2 == xCoordinate3 && yCoordinate2 == yCoordinate3 ||
                xCoordinate2 == xCoordinate4 && yCoordinate2 == yCoordinate4 ||
                xCoordinate2 == xCoordinate5 && yCoordinate2 == yCoordinate5 ||
                xCoordinate2 == xCoordinate6 && yCoordinate2 == yCoordinate6 ||
                xCoordinate2 == xCoordinate7 && yCoordinate2 == yCoordinate7 ||
                xCoordinate3 == xCoordinate4 && yCoordinate3 == yCoordinate4 ||
                xCoordinate3 == xCoordinate5 && yCoordinate3 == yCoordinate5 ||
                xCoordinate3 == xCoordinate6 && yCoordinate3 == yCoordinate6 ||
                xCoordinate3 == xCoordinate7 && yCoordinate3 == yCoordinate7 ||
                xCoordinate4 == xCoordinate5 && yCoordinate4 == yCoordinate5 ||
                xCoordinate4 == xCoordinate6 && yCoordinate4 == yCoordinate6 ||
                xCoordinate4 == xCoordinate7 && yCoordinate4 == yCoordinate7 ||
                xCoordinate5 == xCoordinate6 && yCoordinate5 == yCoordinate6 ||
                xCoordinate5 == xCoordinate7 && yCoordinate5 == yCoordinate7 ||
                xCoordinate6 == xCoordinate7 && yCoordinate6 == yCoordinate7)
            {
                direction = generateCpuDirection();
                movements(direction, &xCoordinate1, &yCoordinate1, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate2, &yCoordinate2, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate3, &yCoordinate3, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate4, &yCoordinate4, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate5, &yCoordinate5, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate6, &yCoordinate6, userChoice);


            }

            // Check if player has reached treasure, if true, end the program
            if (xCoordinate == xCoordinate7 && yCoordinate == yCoordinate7)
            {
                cout << "Congrats, you won!" << endl;
                endLoop = true;
            }
            // Check if enemy has caught player, if true, end the program
            else if (xCoordinate == xCoordinate1 && yCoordinate == yCoordinate1 ||
                xCoordinate == xCoordinate2 && yCoordinate == yCoordinate2 ||
                xCoordinate == xCoordinate3 && yCoordinate == yCoordinate3 ||
                xCoordinate == xCoordinate4 && yCoordinate == yCoordinate4 ||
                xCoordinate == xCoordinate5 && yCoordinate == yCoordinate5 ||
                xCoordinate == xCoordinate6 && yCoordinate == yCoordinate6)
            {
                cout << "Tough, you lost" << endl;
                endLoop = true;
            }

            // Create characters for each object (enemy - T, user - G, treasure - X)
            normalBoard[xCoordinate][yCoordinate] = 'G';
            normalBoard[xCoordinate1][yCoordinate1] = 'T';
            normalBoard[xCoordinate2][yCoordinate2] = 'T';
            normalBoard[xCoordinate3][yCoordinate3] = 'T';
            normalBoard[xCoordinate4][yCoordinate4] = 'T';
            normalBoard[xCoordinate5][yCoordinate5] = 'T';
            normalBoard[xCoordinate6][yCoordinate6] = 'T';
            normalBoard[xCoordinate7][yCoordinate7] = 'X';

            // Update the normal board with objects added
            createNormalBoard(normalBoard);
        }

    }
    else
    {
        // Initialize objects and variables
        bool endLoop = false;
        char hardBoard[ROW3][COL3];

        // This is used to randomize the numbers
        srand(time(0));

        // Initialize board with hard dimensions
        for (int i = 0; i < ROW3; i++)
        {
            for (int j = 0; j < COL3; j++)
            {
                hardBoard[i][j] = '.';
            }
        }

        // Generate coordinates for player
        int xCoordinate = 0;
        int yCoordinate = 0;

        // Generate coordinates for first enemy
        int xCoordinate1 = 10;
        int yCoordinate1 = 10;

        // Generate coordinates for second enemy
        int xCoordinate2 = 12;
        int yCoordinate2 = 12;

        // Generate coordinates for third enemy
        int xCoordinate3 = 11;
        int yCoordinate3 = 11;

        // Generate coordinates for fourth enemy
        int xCoordinate4 = 13;
        int yCoordinate4 = 13;

        // Generate coordinates for fifth enemy
        int xCoordinate5 = 14;
        int yCoordinate5 = 14;

        // Generate coordinates for sixth enemy
        int xCoordinate6 = 15;
        int yCoordinate6 = 15;

        // Generate coordinates for seventh enemy
        int xCoordinate7 = 16;
        int yCoordinate7 = 16;

        // Generate coordinates for eight enemy
        int xCoordinate8 = 17;
        int yCoordinate8 = 17;

        // Generate coordinates for ninth enemy
        int xCoordinate9 = 18;
        int yCoordinate9 = 18;

        // Generate coordinates for tenth enemy
        int xCoordinate10 = 19;
        int yCoordinate10 = 19;

        // Generate coordinates for treasure
        int xCoordinate11 = 20;
        int yCoordinate11 = 20;

        // Create characters for each object (enemy - T, user - G, treasure - X)
        hardBoard[xCoordinate][yCoordinate] = 'G';
        hardBoard[xCoordinate1][yCoordinate1] = 'T';
        hardBoard[xCoordinate2][yCoordinate2] = 'T';
        hardBoard[xCoordinate3][yCoordinate3] = 'T';
        hardBoard[xCoordinate4][yCoordinate4] = 'T';
        hardBoard[xCoordinate5][yCoordinate5] = 'T';
        hardBoard[xCoordinate6][yCoordinate6] = 'T';
        hardBoard[xCoordinate7][yCoordinate7] = 'T';
        hardBoard[xCoordinate8][yCoordinate8] = 'T';
        hardBoard[xCoordinate9][yCoordinate9] = 'T';
        hardBoard[xCoordinate10][yCoordinate10] = 'T';
        hardBoard[xCoordinate11][yCoordinate11] = 'X';

        // Update the hard board with objects added
        createHardBoard(hardBoard);

        while (endLoop == false)
        {
            // Initialize objects and variables
            char direction;

            // Obtain user input for a movement
            cout << "The options are w,a,s,d(w, move up)(a, move left)(s, move down)(d, move right)" << endl;
            cout << "Enter your choice: " << endl;
            cin >> direction;

            // Initialize objects for the normal board (enemy, user, Cpu)
            hardBoard[xCoordinate][yCoordinate] = '.';
            hardBoard[xCoordinate1][yCoordinate1] = '.';
            hardBoard[xCoordinate2][yCoordinate2] = '.';
            hardBoard[xCoordinate3][yCoordinate3] = '.';
            hardBoard[xCoordinate4][yCoordinate4] = '.';
            hardBoard[xCoordinate5][yCoordinate5] = '.';
            hardBoard[xCoordinate6][yCoordinate6] = '.';
            hardBoard[xCoordinate7][yCoordinate7] = '.';
            hardBoard[xCoordinate8][yCoordinate8] = '.';
            hardBoard[xCoordinate9][yCoordinate9] = '.';
            hardBoard[xCoordinate10][yCoordinate10] = '.';
            hardBoard[xCoordinate11][yCoordinate11] = '.';

            // Execute user movement
            movements(direction, &xCoordinate, &yCoordinate, userChoice);

            // Obtain random direction for Cpu1 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate1, &yCoordinate1, userChoice);

            // Obtain random direction for Cpu2 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate2, &yCoordinate2, userChoice);

            // Obtain random direction for Cpu3 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate3, &yCoordinate3, userChoice);

            // Obtain random direction for Cpu4 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate4, &yCoordinate4, userChoice);

            // Obtain random direction for Cpu5 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate5, &yCoordinate5, userChoice);

            // Obtain random direction for Cpu6 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate6, &yCoordinate6, userChoice);

            // Obtain random direction for Cpu7 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate7, &yCoordinate7, userChoice);

            // Obtain random direction for Cpu8 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate8, &yCoordinate8, userChoice);

            // Obtain random direction for Cpu9 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate9, &yCoordinate9, userChoice);

            // Obtain random direction for Cpu10 and execute movement
            direction = generateCpuDirection();
            movements(direction, &xCoordinate10, &yCoordinate10, userChoice);



            // Protect against overlapping on other enemy or treasure
            while (xCoordinate1 == xCoordinate2 && yCoordinate1 == yCoordinate2 ||
                xCoordinate1 == xCoordinate3 && yCoordinate1 == yCoordinate3 ||
                xCoordinate1 == xCoordinate4 && yCoordinate1 == yCoordinate4 ||
                xCoordinate1 == xCoordinate5 && yCoordinate1 == yCoordinate5 ||
                xCoordinate1 == xCoordinate6 && yCoordinate1 == yCoordinate6 ||
                xCoordinate1 == xCoordinate7 && yCoordinate1 == yCoordinate7 ||
                xCoordinate1 == xCoordinate8 && yCoordinate1 == yCoordinate8 ||
                xCoordinate1 == xCoordinate9 && yCoordinate1 == yCoordinate9 ||
                xCoordinate1 == xCoordinate10 && yCoordinate1 == yCoordinate10 ||
                xCoordinate1 == xCoordinate11 && yCoordinate1 == yCoordinate11 ||
                xCoordinate2 == xCoordinate3 && yCoordinate2 == yCoordinate3 ||
                xCoordinate2 == xCoordinate4 && yCoordinate2 == yCoordinate4 ||
                xCoordinate2 == xCoordinate5 && yCoordinate2 == yCoordinate5 ||
                xCoordinate2 == xCoordinate6 && yCoordinate2 == yCoordinate6 ||
                xCoordinate2 == xCoordinate7 && yCoordinate2 == yCoordinate7 ||
                xCoordinate2 == xCoordinate8 && yCoordinate2 == yCoordinate8 ||
                xCoordinate2 == xCoordinate9 && yCoordinate2 == yCoordinate9 ||
                xCoordinate2 == xCoordinate10 && yCoordinate2 == yCoordinate10 ||
                xCoordinate2 == xCoordinate11 && yCoordinate2 == yCoordinate11 ||
                xCoordinate3 == xCoordinate4 && yCoordinate3 == yCoordinate4 ||
                xCoordinate3 == xCoordinate5 && yCoordinate3 == yCoordinate5 ||
                xCoordinate3 == xCoordinate6 && yCoordinate3 == yCoordinate6 ||
                xCoordinate3 == xCoordinate7 && yCoordinate3 == yCoordinate7 ||
                xCoordinate3 == xCoordinate8 && yCoordinate3 == yCoordinate8 ||
                xCoordinate3 == xCoordinate9 && yCoordinate3 == yCoordinate9 ||
                xCoordinate3 == xCoordinate10 && yCoordinate3 == yCoordinate10 ||
                xCoordinate3 == xCoordinate11 && yCoordinate3 == yCoordinate11 ||
                xCoordinate4 == xCoordinate5 && yCoordinate4 == yCoordinate5 ||
                xCoordinate4 == xCoordinate6 && yCoordinate4 == yCoordinate6 ||
                xCoordinate4 == xCoordinate7 && yCoordinate4 == yCoordinate7 ||
                xCoordinate4 == xCoordinate8 && yCoordinate4 == yCoordinate8 ||
                xCoordinate4 == xCoordinate9 && yCoordinate4 == yCoordinate9 ||
                xCoordinate4 == xCoordinate10 && yCoordinate4 == yCoordinate10 ||
                xCoordinate4 == xCoordinate11 && yCoordinate4 == yCoordinate11 ||
                xCoordinate5 == xCoordinate6 && yCoordinate5 == yCoordinate6 ||
                xCoordinate5 == xCoordinate7 && yCoordinate5 == yCoordinate7 ||
                xCoordinate5 == xCoordinate8 && yCoordinate5 == yCoordinate8 ||
                xCoordinate5 == xCoordinate9 && yCoordinate5 == yCoordinate9 ||
                xCoordinate5 == xCoordinate10 && yCoordinate5 == yCoordinate10 ||
                xCoordinate5 == xCoordinate11 && yCoordinate5 == yCoordinate11 ||
                xCoordinate6 == xCoordinate7 && yCoordinate6 == yCoordinate7 ||
                xCoordinate6 == xCoordinate8 && yCoordinate6 == yCoordinate8 ||
                xCoordinate6 == xCoordinate9 && yCoordinate6 == yCoordinate9 ||
                xCoordinate6 == xCoordinate10 && yCoordinate6 == yCoordinate10 ||
                xCoordinate6 == xCoordinate11 && yCoordinate6 == yCoordinate11 ||
                xCoordinate7 == xCoordinate8 && yCoordinate7 == yCoordinate8 ||
                xCoordinate7 == xCoordinate9 && yCoordinate7 == yCoordinate9 || 
                xCoordinate7 == xCoordinate10 && yCoordinate7 == yCoordinate10 || 
                xCoordinate7 == xCoordinate11 && yCoordinate7 == yCoordinate11 ||
                xCoordinate8 == xCoordinate9 && yCoordinate8 == yCoordinate9 || 
                xCoordinate8 == xCoordinate10 && yCoordinate8 == yCoordinate10 || 
                xCoordinate8 == xCoordinate11 && yCoordinate8 == yCoordinate11 || 
                xCoordinate9 == xCoordinate10 && yCoordinate9 == yCoordinate10 || 
                xCoordinate9 == xCoordinate11 && yCoordinate9 == yCoordinate11 || 
                xCoordinate10 == xCoordinate11 && yCoordinate10 == yCoordinate11)
            {
                direction = generateCpuDirection();
                movements(direction, &xCoordinate1, &yCoordinate1, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate2, &yCoordinate2, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate3, &yCoordinate3, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate4, &yCoordinate4, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate5, &yCoordinate5, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate6, &yCoordinate6, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate7, &yCoordinate7, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate8, &yCoordinate8, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate9, &yCoordinate9, userChoice);

                direction = generateCpuDirection();
                movements(direction, &xCoordinate10, &yCoordinate10, userChoice);
            }

            // Check if player has reached treasure, if true, end the program
            if (xCoordinate == xCoordinate11 && yCoordinate == yCoordinate11)
            {
                cout << "Congrats, you won!" << endl;
                endLoop = true;
            }
            // Check if enemy has caught player, if true, end the program
            else if (xCoordinate == xCoordinate1 && yCoordinate == yCoordinate1 ||
                xCoordinate == xCoordinate2 && yCoordinate == yCoordinate2 ||
                xCoordinate == xCoordinate3 && yCoordinate == yCoordinate3 ||
                xCoordinate == xCoordinate4 && yCoordinate == yCoordinate4 ||
                xCoordinate == xCoordinate5 && yCoordinate == yCoordinate5 ||
                xCoordinate == xCoordinate6 && yCoordinate == yCoordinate6 ||
                xCoordinate == xCoordinate7 && yCoordinate == yCoordinate7 || 
                xCoordinate == xCoordinate8 && yCoordinate == yCoordinate8 || 
                xCoordinate == xCoordinate9 && yCoordinate == yCoordinate9 || 
                xCoordinate == xCoordinate10 && yCoordinate == yCoordinate10)
            {
                cout << "Tough, you lost" << endl;
                endLoop = true;
            }

            // Create characters for each object (enemy - T, user - G, treasure - X)
            hardBoard[xCoordinate][yCoordinate] = 'G';
            hardBoard[xCoordinate1][yCoordinate1] = 'T';
            hardBoard[xCoordinate2][yCoordinate2] = 'T';
            hardBoard[xCoordinate3][yCoordinate3] = 'T';
            hardBoard[xCoordinate4][yCoordinate4] = 'T';
            hardBoard[xCoordinate5][yCoordinate5] = 'T';
            hardBoard[xCoordinate6][yCoordinate6] = 'T';
            hardBoard[xCoordinate7][yCoordinate7] = 'T';
            hardBoard[xCoordinate8][yCoordinate8] = 'T';
            hardBoard[xCoordinate9][yCoordinate9] = 'T';
            hardBoard[xCoordinate10][yCoordinate10] = 'T';
            hardBoard[xCoordinate11][yCoordinate11] = 'X';

            // Update the normal board with objects added
            createHardBoard(hardBoard);
        }

    }

}