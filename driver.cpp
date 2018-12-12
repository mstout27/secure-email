#include <iostream>
#include <cstdlib>
#include <string>
//#include <sql.c>
#include <stdio.h>


using namespace std;







int main(){
  bool loggedin = false;
  int input;
  string username;
  string password;

  for(;;){
    
    cout << "\nWelcome to the super secret email server." << endl;

    while(!loggedin){
      cout << "What would you like to do? Enter the number of your selected option." << endl;
      cout << "1.) Log In" << endl;
      cout << "2.) Register" << endl;
      cin >> input;

      if (input == 1){
        bool login = true;
        bool auth = false;
        int count = 0;
        while(login && count < 3){
          cout << "\nYour username?" << endl;
          cin >> username;

          cout << "Password?" << endl;
          cin >> password;

          //Check if user is in system
          //auth = authenticate(username,passord);
          if(auth){
            loggedin = true;
          }
          else{
            count++;
            cout << "\nInvalid log in." << endl;
            cout << "You have used " << count << " of 3 attempts.\n" << endl;
          }
        }
      }

      else if(input == 2){

        cout << "Enter your new username" << endl;
        cin >> username;
        //username cannot have ;- etc
        //username cannot already match another username in the table

        cout << "Enter your new password" << endl;
        cin >> password;
        //password cannot have ;- etc
        //hash username w/ password, use salsa20?
        
        //-> INSERT INTO Users(Username, Password)
        loggedin = true;

      }
      else{
        cout << "\nYour input did not match any of the options.\n" << endl;
        cout << "Please try again.\n" << endl;
      }

    }

    while(loggedin){
      cout << "What would you like to do? Enter the number of your selected option." << endl;
      cout << "1.) Send a message" << endl;
      cout << "2.) View messages" << endl;
      cout << "3.) Log out" << endl;
      cin >> input;

      if(input == 1){
          
      }

      else if(input == 2){

      }

      else if(input == 3){
        loggedin = false;
      }

      else{
        cout << "\nYour input did not match any of the options.\n" << endl;
        cout << "Please try again.\n" << endl;
      }

    }
  }

}
