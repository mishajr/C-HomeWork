#include <iostream>
#include <windows.h> 

using namespace std;

int main() {
 /*   cout << "Menu:" << endl;
    cout << "1. Print horizontal line" << endl;
    cout << "2. Print vertical line" << endl;

    char choice;
    cout << "Choose an option (1 or 2): ";
    cin >> choice;

    char symbol;
    cout << "Enter symbol: ";
    cin >> symbol;

    string speed;
    cout << "Enter speed (fast, normal, slow): ";
    cin >> speed;

    int delay;
    switch (speed[0]) {
    case 'f':
        delay = 100;
        break;
    case 'n':
        delay = 500; 
        break;
    case 's':
        delay = 1000; 
        break;
    default:
        cout << "Unknown speed" << endl;
      
    }

    switch (choice) {
    case '1':
        for (int i = 0; i < 20; ++i) {
            cout << symbol;
            cout.flush();
            Sleep(delay); 
        }
        cout << endl;
        break;
    case '2':
        for (int i = 0; i < 20; ++i) {
            cout << symbol << endl;
            Sleep(delay); 
        }
        break;
    default:
        cout << "Invalid choice" << endl;
  
    }

   */
    //================================================================================================

    //srand(time(0)); 

    //int userScore = 0;
    //int computerScore = 0;

    //cout << "Welcome to the Dice Game!" << endl;

    //char startGame;
    //cout << "Enter '1' to start the game: ";
    //cin >> startGame;

    //if (startGame == '1') {

    //    for (int i = 0; i < 3; ++i) {

    //        int userRoll1 = (rand() % 6) + 1;
    //        int userRoll2 = (rand() % 6) + 1;
    //        int userTotal = userRoll1 + userRoll2;
    //        cout << "You rolled: " << userRoll1 << " and " << userRoll2 << " (Total: " << userTotal << ")" << endl;
    //        userScore += userTotal;


    //        int computerRoll1 = (rand() % 6) + 1;
    //        int computerRoll2 = (rand() % 6) + 1;
    //        int computerTotal = computerRoll1 + computerRoll2;
    //        cout << "Computer rolled: " << computerRoll1 << " and " << computerRoll2 << " (Total: " << computerTotal << ")" << endl;
    //        computerScore += computerTotal;

    //        cout << "Your current score: " << userScore << endl;
    //        cout << "Computer's current score: " << computerScore << endl;
    //        cout << endl;
    //    }


    //    if (userScore > computerScore) {
    //        cout << "Congratulations! You win!" << endl;
    //    }
    //    else if (userScore < computerScore) {
    //        cout << "Computer wins. Better luck next time!" << endl;
    //    }
    //    else {
    //        cout << "It's a tie!" << endl;
    //    }
    //}
    //else {
    //    cout << "Exiting the game. Goodbye!" << endl;
    //}




    //================================================================================================

//
//const int SIZE = 10;
//int numbers[SIZE];
//
//int minNum, maxNum;
//
//
//
//
//srand(time(0));
//
//
//for (int i = 0; i < SIZE; ++i) {
//    numbers[i] = rand() % 100;
//}
//cout << "Array elements: ";
//for (int i = 0; i < SIZE; ++i) {
//    cout << numbers[i] << " ";
//}
//
//cout << endl;
//
//
//minNum = maxNum = numbers[0];
//
//
//
//for (int i = 1; i < SIZE; ++i) {
//    if (numbers[i] < minNum) {
//        minNum = numbers[i];
//    }
//    if (numbers[i] > maxNum) {
//        maxNum = numbers[i];
//    }
//}
//
//
//cout << "Minimum element: " << minNum << endl;
//cout << "Maximum element: " << maxNum << endl;
//
//
//
//


    //================================================================================================





   /* const int MONTHS = 12;
    int profits[MONTHS];


    cout << "Enter profits for each month:" << endl;
    for (int i = 0; i < MONTHS; ++i) {
        cout << "Month " << i + 1 << ": ";
        cin >> profits[i];
    }

    int startMonth, endMonth;
    cout << "Enter the range (start and end months): ";
    cin >> startMonth >> endMonth;

    if (startMonth < 1 || endMonth > MONTHS || startMonth > endMonth) {
        cout << "Invalid range." << endl;

    }

    int maxIndex = startMonth - 1, minIndex = startMonth - 1;
    for (int i = startMonth - 1; i < endMonth; ++i) {
        if (profits[i] > profits[maxIndex]) {
            maxIndex = i;
        }
        if (profits[i] < profits[minIndex]) {
            minIndex = i;
        }
    }


    cout << "Month with maximum profit in the range: " << maxIndex + 1 << endl;
    cout << "Month with minimum profit in the range: " << minIndex + 1 << endl;
*/


//================================================================================================


 /*   float arr[10]{ -1.23,3,7.12,17.19,2.9,19,8,4,-17.2,-2.5 };
    float sumM = 0;
    int minPos, maxPos;
    float max = arr[0], min = arr[0];
    float multyEven = 1;
    float SumMin = 1; 
    float sumMul =1;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (size_t i = 0; i < 10; i++)
    {
        if (arr[i]  < 0)
            sumM += arr[i];

    }
    
    for (size_t i = 0; i < 10; i++)
    {
        if (max < arr[i]){
            max = arr[i];
            maxPos = i;
       }
    }
    for (size_t i = 0; i < 10; i++)
    {
        if (min > arr[i]){
            min = arr[i];
            minPos = i;
        }
    }
        
    if (minPos<maxPos){
        for (int i = minPos; i < maxPos; i++)
        {
            sumMul *= arr[i];
            
        }
    }
    else {
        for (int i = maxPos; i < minPos; i++)
        {
            sumMul *= arr[i];

        }
    }
    for (size_t i = 0; i < 10; i++)
    {
        if (i%2 == 0)
        {
            multyEven *= arr[i];
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (arr[i] < 0) {
            firstNegativeIndex = i;
            break;
        }
    }


    for (int i = 10 - 1; i >= 0; --i) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
            break;
        }
    }


        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            SumMin += arr[i];
        }*/

   
   /* 
    cout << "sum minus = " << sumM << endl;
    cout << "multy from min to max position  : " << sumMul << endl;
    cout << "multy Even  : " << multyEven << endl;
    cout << "Sum of elements between first and last negative elements: " << SumMin << endl;


*/















}





















