#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <iterator>
#include <vector>
#include <algorithm>

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
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    ' ', '!', '@', '#', '$', '%', '^', '&' , '*', '(', ')', ',', '.', '/', ':', ';', '[', ']', '-', '+', '|', '0', '1', '2', '3','4', '5', '6', '7', '8', '9'};

    // unsigned int array with values 10-67, to assign value to each letter of the alphabet
    const unsigned int letter_to_value[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67};
    
    // nested for loop, iterates the 26 letters of the alphabet as well as the length of the password string. Adds value of the letter to passSeed, which is passed back to the original calling function
    for(int i = 0; i < len; i++) {
      for(int j = 0; j < 57; j++) {
        if(pass[i] == alphabet[j]) {
          passSeed += letter_to_value[j];
        }
      }
    }

  return passSeed;

  }

  // function converts the file uploaded to an array, each letter filling an index of the array
  vector<char> fileToVector(string fileName) { 
     
    vector<char> message;
    char c;

     fstream file(fileName);
     if(file.is_open()) {
      while(file.get(c)) {
        c = tolower(c, locale());
        message.push_back(c);
          }
        }
        else {
            cout << "file did not open";
          }

        file.close();


    return message;

    }

  vector<string> fileToNumVector(string fileName) {
    vector<string> message;
    string indigo;

    fstream file(fileName);
    if(file.is_open()) { 
      while(getline(file, indigo)) {
        message.push_back(indigo);
      }
    }

    return message;
  }

  vector<int> randomNums(int passSeed) {
        
        int randomSeed;
        vector<int> randomNumbers;

        srand(passSeed);
        randomSeed = rand();

        for(int i = 0; i < 57; i++) {
          randomNumbers.push_back(rand());
        }


        return randomNumbers;

  }

   void decrypt() {

    string password;
    string fileName;
    vector<int> randomNumbers;
    vector<string> fileNum;
    int passSeed; 
    vector<int> fileNumInt;

    cout << "Type the name of the file you wish to decrypt. For example, \"text.txt" << endl;
    cin >> fileName;
    cout << "Type the password you want to use to decrypt the file." << endl;
    cin >> password;

    passSeed = passwordToNum(password);

    randomNumbers = randomNums(passSeed);

    fileNum = fileToNumVector(fileName);

    for(int i = 0; i < fileNum.size(); i++) {
      fileNumInt.push_back(stoi(fileNum[i]));
      cout << fileNumInt[i] << endl;
    }

    
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    ' ', '!', '@', '#', '$', '%', '^', '&' , '*', '(', ')', ',', '.', '/', ':', ';', '[', ']', '-', '+', '|', '0', '1', '2', '3','4', '5', '6', '7', '8', '9'};

    string answer;

    for(int z = 0; z < fileNumInt.size(); z++) {
      for(int q = 0; q < randomNumbers.size(); q++) {
        if(randomNumbers[q] == fileNumInt[z]) {
          answer += alphabet[q];
        }
      }
    }

    cout << answer;

    
  }
  
  void encrypt() {

    // defines local variables to be used by the encrypt function
        string fileName;
        string password;
        int passSeed;
        vector<int> encrypted;
        vector<char> message;
        vector<int> randomNumbers;

        char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    ' ', '!', '@', '#', '$', '%', '^', '&' , '*', '(', ')', ',', '.', '/', ':', ';', '[', ']', '-', '+', '|', '0', '1', '2', '3','4', '5', '6', '7', '8', '9'};


        // prompts user for input for fileName and password
        cout << "Type the name of the file you wish to encrypt. For example, \"text.exe\"" << endl;
        cin >> fileName;
        cout << "Type the password you want to use to decrypt the file." << endl;
        cin >> password;

        // sets the value of the integer passSeed to the value returned by the passwordToNum function
        passSeed = passwordToNum(password);

        message = fileToVector(fileName);

        randomNumbers = randomNums(passSeed);
        
        //iterates each letter of the message
        for(int j = 0; j < message.size(); j++) { 
          //iterates each letter of the alphabet
          for(int q = 0; q < 57; q++) {
          // if the letter of the message is equal to the letter of the alphabet, add randomNums[q] to the end of the vector
            if(message[j] == alphabet[q]) {
              encrypted.push_back(randomNumbers[q]);
            }
          }
        }

        ofstream outputFile("./output.txt");
        ostream_iterator<int> output_iterator(outputFile, "\n");
        copy(encrypted.begin(), encrypted.end(), output_iterator);

        char anz;
        cout << "File has been encrypted. output.txt is your encrypted file. Restart the program and decrypt? y or n";
        cin >> anz;
        if(anz == 'y') { 
          decrypt();
        }
        else if(anz == 'n') {
          cout << "exiting the program.";
        }
        else { 
          cout << "invalid input. exiting program";
        }

    }

 