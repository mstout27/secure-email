# secure-email
Primary code located in driver.cpp.

Encrypted 'email' server, written in C++.  Creates a SQL database with two tables, one for users and another for messages.  Users can register with a username and password. Once logged in, a user can view all other users, send a message to a certain user, and view all received messages. 

Messages use private key encryption, so all messages are encrypted and decrypted with a key shared by the sender and the receiver.
Passwords are stored hashed in the database, using picoSHA2 SHA256 hash generator.
