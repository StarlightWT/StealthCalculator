#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

int main() {
    //!Debug mode
    bool debug = false;
    if(!debug) FreeConsole();

    // Declare all variables
    char key;
    char i;
    int pressedKey = 0;
    int firstNumber = 0;
    int secondNumber = 0; 
    while(true)
    {
        for(i = 8; i <= 255; i++){
        if(GetAsyncKeyState(i) == -32767){
            key = i;
        //Key input translator
        switch(key)
        {
            case 107: //Plus
            switch(pressedKey)
            {
                case 1:
                firstNumber = firstNumber + secondNumber;
                secondNumber = 0;
                break;
                case 2:
                firstNumber = firstNumber - secondNumber;
                secondNumber = 0;
                break;
                case 3:
                firstNumber = firstNumber * secondNumber;
                secondNumber = 0;
                break;
                case 4:
                if(secondNumber = 0) secondNumber++;
                firstNumber = firstNumber / secondNumber;
                secondNumber = 0;
                break;
            }
            pressedKey = 1;
            break;
            case 109: //Minus
            switch(pressedKey)
            {
                case 1:
                firstNumber = firstNumber + secondNumber;
                secondNumber = 0;
                break;
                case 2:
                firstNumber = firstNumber - secondNumber;
                secondNumber = 0;
                break;
                case 3:
                firstNumber = firstNumber * secondNumber;
                secondNumber = 0;
                break;
                case 4:
                if(secondNumber = 0) secondNumber++;
                firstNumber = firstNumber / secondNumber;
                secondNumber = 0;
                break;
            }
            pressedKey = 2; 
            break;
            case 106: //Multiplication
            switch(pressedKey)
            {
                case 1:
                firstNumber = firstNumber + secondNumber;
                secondNumber = 0;
                break;
                case 2:
                firstNumber = firstNumber - secondNumber;
                secondNumber = 0;
                break;
                case 3:
                firstNumber = firstNumber * secondNumber;
                secondNumber = 0;
                break;
                case 4:
                if(secondNumber = 0) secondNumber++;
                firstNumber = firstNumber / secondNumber;
                secondNumber = 0;
                break;
            }
            pressedKey = 3;
            break;
            case 111: //Dividing
            switch(pressedKey)
            {
                case 1:
                firstNumber = firstNumber + secondNumber;
                secondNumber = 0;
                break;
                case 2:
                firstNumber = firstNumber - secondNumber;
                secondNumber = 0;
                break;
                case 3:
                firstNumber = firstNumber * secondNumber;
                secondNumber = 0;
                break;
                case 4:
                if(secondNumber = 0) secondNumber++;
                firstNumber = firstNumber / secondNumber;
                secondNumber = 0;
                break;
            }
            pressedKey = 4;
            break;
            case 96: //Add 0
            if(pressedKey > 0){
                secondNumber = secondNumber * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = firstNumber * 10;
            };
            break;
            case 97: //Add 1
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.1) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.1) * 10;
            };
            break;
            case 98: //Add 2
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.2) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.2) * 10;
            };
            break;
            case 99: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.3) * 10 +1; //Multiply the number by 10 resulting in a 0 being added to the end +1 because C++
            } else {
                firstNumber = (firstNumber + 0.3) * 10 +1;
            };
            break;
            case 100: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.4) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.4) * 10;
            };
            break;
            case 101: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.5) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.5) * 10;
            };
            break;
            case 102: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.6) * 10 +1; //Multiply the number by 10 resulting in a 0 being added to the end +1 because C++
            } else {
                firstNumber = (firstNumber + 0.6) * 10 +1;
            };
            break;
            case 103: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.7) * 10 +1; //Multiply the number by 10 resulting in a 0 being added to the end +1 because C++
            } else {
                firstNumber = (firstNumber + 0.7) * 10 +1;
            };
            break;
            case 104: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.8) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.8) * 10;
            };
            break;
            case 105: 
            if(pressedKey > 0){
                secondNumber = (secondNumber + 0.9) * 10; //Multiply the number by 10 resulting in a 0 being added to the end
            } else {
                firstNumber = (firstNumber + 0.9) * 10;
            };
            break;
            case 13:
            if(pressedKey > 0){
                int result = 0;

                switch (pressedKey) //Get the result
                {
                case 1: //Plus
                result = firstNumber + secondNumber;
                break;
                case 2: //Minus
                result = firstNumber - secondNumber;
                break;
                case 3: //Multiply
                result = firstNumber * secondNumber;
                break;
                case 4: //Divide
                if(secondNumber = 0) break;
                result = firstNumber / secondNumber;
                break;
                }

                //Save string to clipboard
                char str[21]; //define string
                sprintf(str, "%d", result); //Translate int to string
                if(result > 0){
                OpenClipboard(0); //Open clipboard
                EmptyClipboard(); //Clear it
                const size_t ln = strlen(str) + 1; //Get string length
                HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, ln); //Define h which allocates memory (?)
                memcpy(GlobalLock(h), str, ln); //Idfk
                GlobalUnlock(h); //Unlock... something
                SetClipboardData(CF_TEXT, h); //Set the clipboard data to the string
                CloseClipboard(); //Close the clipboard
                };

                //Debugging
                if(debug) {
                printf("FNV: ");
                printf("%d\n", firstNumber);
                printf("SNV: ");
                printf("%d\n", secondNumber);
                printf("PKV: ");
                printf("%d\n", pressedKey);
                printf("Result: ");
                printf("%d\n", result);
                }
                //Debugging end 

                //!Clear variables
                pressedKey = 0;
                firstNumber = 0;
                secondNumber = 0;
            }
        }
        }
        }
    }
    return 0;
    }