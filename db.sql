PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE users (id integer primary key autoincrement, name text, password text);

INSERT INTO "users" VALUES(2,'matt','SuperSecure00');
INSERT INTO "users" VALUES(3,'kyle','SuperSecure01');

CREATE TABLE messages (sender text, receiver text, message text);


COMMIT;