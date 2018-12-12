#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"
#include "picosha2.h"

using namespace std;

int main() {
  // std::string msg = "HELLO WORLD";
 	string msg = "Reeeeee";
 	string key = "THISISMYKEY";
 	cout << "message to send: " << msg << endl;
 	string encrypted_msg = encrypt(msg, key);
 	cout << "encrypted message: " << encrypted_msg << endl;
 	string decrypted_msg = decrypt(encrypted_msg, key);
 	cout << "decrypted message: " << decrypted_msg << endl;

  string password = "kyle";
  string hash = picosha2::hash256_hex_string(password);
  cout << hash << endl;

  return 0;
}
