PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE users (id integer primary key autoincrement, name text, password text);


CREATE TABLE messages (sender text, receiver text, message text);


COMMIT;