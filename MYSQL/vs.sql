-- Active: 1710342347852@@127.0.0.1@3306@college
SET autocommit = "off";

SET autocommit = "on";

SELECT * FROM india LIMIT 10;

CREATE TABLE mhcopy AS SELECT * FROM mh LIMIT 10;

SHOW TABLES;

SELECT * FROM mhcopy;

INSERT INTO mhcopy ( SELECT * FROM mh WHERE population < 1000000 );

DELETE FROM mhcopy WHERE population < 1000000;

SELECT * FROM mh WHERE name LIKE "%e";

DESC mh;

ROLLBACK;

COMMIT;