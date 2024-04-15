-- Active: 1710342347852@@127.0.0.1@3306@college
SHOW TABLES;

CREATE TABLE voter (
    id int PRIMARY KEY, name VARCHAR(50), age int CHECK (age > 18)
);

ALTER TABLE voter ADD CONSTRAINT check_age CHECK (age >= 18);

ALTER TABLE voter DROP CONSTRAINT voter_chk_1;

INSERT INTO voter (name, age) VALUES ("ram", 18), ("sham", 54);

ALTER TABLE voter DROP PRIMARY KEY;

DESC voter;

ALTER TABLE voter MODIFY COLUMN id int AUTO_INCREMENT;

SELECT * FROM voter;

-- add default VALUES
CREATE TABLE emp (
    id int PRIMARY KEY, name VARCHAR(50) NOT NULL DEFAULT "john doe", salary float
);

ALTER TABLE emp MODIFY COLUMN id int AUTO_INCREMENT;

ALTER TABLE emp ALTER COLUMN salary SET DEFAULT 0.0;

DESC emp;

INSERT INTO emp (name, salary) VALUES ("kane", 8);

SELECT * FROM emp;

UPDATE emp SET salary = 233 WHERE id = 2;

SELECT "hello world" AS string;

SELECT 1 AS c1, 2 AS c2;

DELIMITER / /

create Function addNum(a int, b int) returns int reads 
sql data 
begin 
declare
	SUM int;
	SET
	    SUM = (
	        SELECT *
	        FROM emp
	        WHERE
	            id = a
	    ) + (
	        SELECT *
	        FROM emp
	        WHERE
	            id = b
	    );
	RETURN SUM;
end
// 

create Function addition(a int, b int) returns int 
no sql -- anothor option DETERMINISTIC 
begin 
declare
	SUM int;
	SET SUM = a + b;
	RETURN SUM;
end
// 

DELIMITER;

SELECT addition (3, 5) AS SUM;

SELECT addNum (1, 5) AS salary_sum;