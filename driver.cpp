#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  bool finished = false;
  string input;
  string username;
  string password;

  cout << endl;
  cout << "Welcome to the super secret email server." << endl;

  while(!finished){
    cout << "What would you like to do? Enter the number of your selected option." << endl;
    cout << "1.) Log In" << endl;
    cout << "2.) Register" << endl;
    cout << "3.) Quit" << endl;
    cin >> input;

    if (input == "1"){
      bool login = true;
      bool auth = false;
      int count = 0;
      while(login && count < 3){
        cout << endl;
        cout << "Your username?" << endl;
        cin >> username;

        cout << "Password?" << endl;
        cin >> password;

        //Check if user is in system
        //auth = authenticate(username,passord);
        if(auth){

        }
        else{
          count++;
          cout << endl;
          cout << "Invalid log in." << endl;
          cout << "You have used " << count << " of 3 attempts." << endl;
          cout << endl;
        }
      }
    }
    else if(input == "2"){

    }
    else if (input == "3") {
      finished = true;
      cout << endl;
      cout << "Bye bye!" << endl;
      cout << endl;
    }
    else{
      cout << endl;
      cout << "Your input did not match any of the options." << endl;
      cout << "Please try again." << endl;
      cout << endl;
    }
  }
}
