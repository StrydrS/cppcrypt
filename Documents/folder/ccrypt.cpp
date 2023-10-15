#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h> 
#include <fstream>
#include <stdlib.h>

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

    // if/else statements check for user input and calls the appropriate function
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


// function converts password given in Encrypt or Decrypt to a seed for the srand() function
  int passwordToNum(string password) {

    //defines local variables to be used in passwordToNum
    string pass = password;
    int passSeed = 0;
    int len = pass.size();

    // char array with each letter of the alphabet
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // unsigned int array with values 10-36, to assign value to each letter of the alphabet
    const unsigned int letter_to_value[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
    
    // nested for loop, iterates the 26 letters of the alphabet as well as the length of the password string. Adds value of the letter to passSeed, which is passed back to the original calling function
    for(int j = 0; j < 26; j++) {
      for(int i = 0; i < len; i++) {
        if(pass[i] = alphabet[j]) {
          passSeed += letter_to_value[j];
        }
      }
    }

  return passSeed;

  }

  // function converts the file uploaded to an array, each letter filling an index of the array
  string fileToVector(fstream& file) { 

    vector<char> message;
    char c;

    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    const unsigned int letter_to_value[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
    
    while(file.get(c)){
       for(int j = 0; j < 26; j++) {
        if(tolower(c)==alphabet[j]) {
          message.push_back(c);
        }
       }
    }

    for(int i = 0; i < message.size(); i++) {
          cout << message[i] << endl;
        }
    return 0;
  }

  void encrypt() {

        string fileName;
        fstream file;
        string password;
        int passSeed;
        vector<char> message;

        cout << "Type the name of the file you wish to encrypt. For example, \"text.exe\"" << endl;
        cin >> fileName;
        cout << "Type the password you want to use to decrypt the file." << endl;
        cin >> password;

        passSeed = passwordToNum(password);

        srand(passSeed);

        fileToVector(file);


        file.open(fileName);

        if(file.is_open()) {
          
        }
        file << "Writing to the file";
        file.close();
        
    }

  void decrypt() {

    cout << "decrypt";

    
  }