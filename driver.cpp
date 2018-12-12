#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int callback(void *outputPtr, int argc, char **argv, char **azColName){
    int i;
    vector<string> *list = reinterpret_cast<vector<string>*>(outputPtr);
    list->push_back(argv[1]);
    return 0;
}

//1 = login
//2 = register
int main(){
  sqlite3* db;
  char *zErrMsg = 0;
  int rc;
  rc = sqlite3_open("mail.db", &db);
  int connected = 1;

  while(connected){

    int loggedIn = 0;
    string name;
   /* State - logged out */
    while(!loggedIn && connected){
      cout << "\nWelcome to the super secret email server." << endl;
      int selection;

      cout << "What would you like to do? Enter the number of your selected option." << endl;
      cout << "1.) Log In" << endl;
      cout << "2.) Register" << endl;
      cout << "3.) Quit" << endl;
      cin >> selection;


      
      if( rc ){
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          sqlite3_close(db);
          return 1;
      };
      
      /* Login */
      if(selection == 1){

        cout << "What is your login name?"<< endl;
        cin >> name;

        string password;
        cout << "Thank you "<< name << ".  What is your password?" << endl;
        cin >> password;
          
        string sql = "SELECT * FROM users where name='" + name + "' and password='" + password + "'";
        vector<string> results;
          
        rc = sqlite3_exec(db, sql.c_str(), callback, &results, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else{
            if (!results.empty()){
                cout << "Welcome " << results[0] << endl;
                loggedIn = 1;
            }
            else {
                cout << "Not a valid name/password combo.  Try again." << endl;
              
            }
        }
      }

      /* Register */
      if(selection == 2){
        string name;
        cout << "What is your new login name?"<< endl;
        cin >> name;

        /* Check for special characters */
        while((name.find(';')!= string::npos) || (name.find('-')!=string::npos) || (name.find('"')!=string::npos)){
          cout << "Username cannot contain special characters. Please try again."  << endl;
          cin >> name;
        }

        /* Check for duplicate username */
        string checkDupe = "select * from users;";
        vector<string> users;
        rc = sqlite3_exec(db, checkDupe.c_str(), callback, &users, &zErrMsg);
        while(count(users.begin(), users.end(), name)){
          cout << "Username taken, please pick a different username." << endl;
          cin >> name;
        }
        
     
        string password;
        cout << "What is your new password?" << endl;
        cin >> password;
        //encrypt that shiiiiiiiit
        string sql = "INSERT INTO users (name, password) VALUES ('" + name + "','" + password + "');";
        vector<string> results;
          
        rc = sqlite3_exec(db, sql.c_str(), callback, &results, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else{
          if (results.empty()){
            cout << "Welcome new user" << name << endl;
            loggedIn = 1;
          }
          else {
            cout << "Not a valid name/password combo.  Try again." << endl;
          }
        }
      }

      /* Quit */
      if(selection == 3){
        cout << "We hope to see you again!" << endl;
        connected = 0;
      }
    }

  /* State - logged in */
    while(loggedIn){
      cout << "What would you like to do? Enter the number of your selected option." << endl;
      int selection2;
      cout << "1.) View all users" << endl;
      cout << "2.) Send a message" << endl;
      cout << "3.) View messages" << endl;
      cout << "4.) Log out" << endl;
      cout << "5.) Disconnect" << endl;
      cin >> selection2;

      /* View users */
      if(selection2 == 1){
        string sql = "select * from users;";
        vector<string> userLog;
        rc = sqlite3_exec(db, sql.c_str(), callback, &userLog, &zErrMsg);
        
        for (vector<string>::const_iterator i = userLog.begin(); i != userLog.end(); ++i)
          cout << *i << endl;
      }

      /* Send message to user */
      else if(selection2 == 2){
        string receiver;
        cout << "Choose a user to send to." << endl;
        cin >> receiver;

        string sendMessage;
        cout << "Type the message to send." << endl;
        cin >> sendMessage;
        string send = "INSERT INTO messages VALUES('" + name + "','" + receiver + "','" + sendMessage + "');";

        vector<string> sentLog;
        rc = sqlite3_exec(db, send.c_str(), callback, &sentLog, &zErrMsg);
        cout << "Message sent." << endl;

      }

      /* View received messages */
      else if(selection2 == 3){
        string view = "select sender, message from messages where receiver = '" + name + "';";

        vector<string> recdLog;
        rc = sqlite3_exec(db, view.c_str(), callback, &recdLog, &zErrMsg);
        
        for (vector<string>::const_iterator i = recdLog.begin(); i != recdLog.end(); ++i)
          cout << *i << endl;
        
      }

      /* Log out */
      else if(selection2 == 4){
        loggedIn = 0;
      }

      /* Disconnect */
      else if(selection2 == 5){
        cout << "We hope to see you again!" << endl;
        loggedIn = 0;
        connected = 0;
      }

      else{
        cout << "\nYour input did not match any of the options.\nPlease try again." << endl;
      }
    }
  
  }

  sqlite3_close(db);
  return 0;
}
  