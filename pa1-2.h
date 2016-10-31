//  pa1.h
//  Magic Squares Generator


#ifndef pa1_h
#define pa1_h

//*Method to check for the Magic Square size based on user input
int checkMagicSize(){
    int n; //represents user's input
    //This keeps the while loop running if the user enters an invalid input
    bool invalid = true;
    std::cout << "Enter the size of a magic square: ";
    std::cin >> n;
    
    while(invalid){
        //checks if n is an odd number between 3 and 15
        if((std::cin) && n >=3 && n <= 15 && n % 2 != 0){
            break;
        }
        //any other value would cause this loop to keep running, however, the clear and ignore prevents the user from entering strings or anything besides an integer
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std:: cout << "\nPlease enter an odd number between 3 and 15.\n" << std::endl;
            
        std::cout << "Enter the size of a magic square: ";
        std::cin >> n;
    }
   
    return n;
}




//Method that checks for the sum of the magic square
void checkSums(int* magicSquare[], int n){
    //variables for checking sum(R = row, C = column, D = diagonal)
    int sumR = 0;
    int sumC = 0;
    int sumD = 0; //First diagonal
    int sumDTwo = 0; //This is for the second diagonal sum
    
    
    //Checks the sum of the rows of the square, [x] -> rows [y]-> columns
    std::cout << "Checking the sums of every row: ";
    for(int x = 0; x < n; x++){
        sumR = 0;
        for(int y = 0; y < n; y++){
            sumR += magicSquare[x][y]; //[x][y] index indicates the sum across/each row
        }
        //prints out sum for each row
        std::cout << sumR << " ";
    }
    std::cout << "\n";
    
    //Checks the sum of the columns of the square
    std::cout << "Checking the sums of every column: ";
    for(int x = 0; x < n; x++){
        sumC = 0;
        for(int y = 0; y < n; y++){
            sumC += magicSquare[y][x]; //[y][x] index indicates the sum downwards/each column
        }
        //prints out sum for each column
        std::cout << sumC << " ";
    }
    std::cout << "\n";
    
    
    //Checks the sum of the first diagonal of the square
    std::cout << "Checking the sums of every diagonal: ";
    for(int x = 0; x < n; x++){
        sumD += magicSquare[x][x];
    }
    
    //Checks the sum of the second diagonal of the square
    for(int x = 0; x < n; x++){
        sumDTwo += magicSquare[x][n - x - 1];
    }
    
    std::cout << sumD << " " << sumDTwo << "\n";
    
}




//**Generation of the Magic Squares
//Method that will create 3 magic squares by taking in the user's chosen #
void createMagicSquare(int n){
    //**Declares the 2D array's size based on user input
    int** magicSquare1 = new int*[n];
    int** magicSquare2 = new int*[n];
    int** magicSquare3 = new int*[n];
    //initializes each element within the array itself based on the user's input
    for(int i = 0; i < n; i++){
        magicSquare1[i] = new int[n];
        magicSquare2[i] = new int[n];
        magicSquare3[i] = new int[n];
        for(int j = 0; j < n; j++){
            magicSquare1[i][j] = 0;
            magicSquare2[i][j] = 0;
            magicSquare3[i][j] = 0;
        }
    }
    
    
    //Variables used for the generation of the Magic Square
    int row = 0;
    int column = n / 2;
    
    //Starting point of the Magic Square
    magicSquare1[row][column] = 1;
    //This portion of the method creates the Magic Square
    for(int count = 2; count <= n*n; count++){
        row--;
        column++;
        
        //Conditions if the row/column is either above the size of n, or below 0
        if(row < 0){
            row += n;
        }
        if (row >= n){
            row -= n;
        }
        if(column >= n){
            column -= n;
        }
        if(column < 0){
            column += n;
        }
        
        //Fills in the Magic Squares while checking for the conditions above again
        if(magicSquare1[row][column] == 0){
            magicSquare1[row][column] = count;
        }
        else{
            row += 2;
            column -= 1;
            if(row < 0){
                row += n;
            }
            if (row >= n){
                row -= n;
            }
            if(column >= n){
                column -= n;
            }
            if(column < 0){
                column += n;
            }
            magicSquare1[row][column] = count;
        }
        
    }
    
    //Rotates first magic square to get the second magic square
    int temp;
    
    for (int i = 0; i < n / 2; i++){
        for (int j = 0; j < (n - i - 1); j++){
            //switches around the edges of the magic square
            temp = magicSquare1[i][j];
            magicSquare2[i][j] = magicSquare1[j][n - i - 1];
            magicSquare2[j][n - i - 1] = magicSquare1[n - i - 1][n - j - 1];
            magicSquare2[n - i - 1][n - j - 1] = magicSquare1[n - j - 1][i];
            magicSquare2[n - j - 1][i] = temp;
        }
        //Sets the middle value equal to the first magic square, since its the same
        magicSquare2[(n-1)/2][(n-1)/2]=magicSquare1[(n-1)/2][(n-1)/2];
    }
    //Rotates the second magic square to get the third magic square
    for (int i = 0; i < n / 2; i++){
        for (int j = 0; j < (n - i - 1); j++){
            //switches around the edges of the magic square
            temp = magicSquare2[i][j];
            magicSquare3[i][j] = magicSquare2[j][n - i - 1];
            magicSquare3[j][n - i - 1] = magicSquare2[n - i - 1][n - j - 1];
            magicSquare3[n - i - 1][n - j - 1] = magicSquare2[n - j - 1][i];
            magicSquare3[n - j - 1][i] = temp;
        }
        //Sets the middle value equal to the first magic square, since its the same
        magicSquare3[(n-1)/2][(n-1)/2]=magicSquare2[(n-1)/2][(n-1)/2];
    }
    
    
    
    //Prints out Magic Square #1
    std::cout << "\nMagic Square #1 is: " << "\n" << std::endl;
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            std::cout << magicSquare1[row][column] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
    //calls in checkSums() method
    checkSums(magicSquare1, n);
    
    
    //Prints out Magic Square #2
    std::cout << "\nMagic Square #2 is: " << "\n" << std::endl;
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            std::cout << magicSquare2[row][column] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
    //calls in checkSums() method
    checkSums(magicSquare2, n);
    
    
    
    //Prints out Magic Square #3
    std::cout << "\nMagic Square #3 is: " << "\n" << std::endl;
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            std::cout << magicSquare3[row][column] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
    //calls in checkSums() method
    checkSums(magicSquare3, n);
    
    
    
    //Deletes the arrays from memory once it is already used to free up space
    for(int i = 0; i < n; i++){
        delete[] magicSquare1[i];
        delete[] magicSquare2[i];
        delete[] magicSquare3[i];
    }
    delete[] magicSquare1;
    delete[] magicSquare2;
    delete[] magicSquare3;
}


#endif /* pa1_h */
