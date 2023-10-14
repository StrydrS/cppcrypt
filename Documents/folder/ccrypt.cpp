#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h> 

using namespace std;

int main () { 


    // defines variables to be used throughout the program

    string userChoice;
    string choiceLower;
    void encrypt();
    void decrypt();

    //prompts user for initial input, encrypt or decrypt

    cout << "Welcome to the CPPCrypt, an encryption and decryption program" << endl;
    cout << "To begin, type \"encrypt\" or \"decrypt\":";
    cin >> userChoice;

    // converts user input to all lowercase for comparison

    transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

    if(userChoice == "encrypt") {
      encrypt();
    }
    else if(userChoice == "decrypt") {
      decrypt();
    }
    else {
      cout << "Invalid input. Please type \"encrypt\" or \"decrypt\".";
      main();
    }


    return 0;
    
}

  void encrypt() {
        cout << "encrypt";
        cout << "ppbutt";
        
    }

  void decrypt() {

    cout << "decrypt";

    
  }