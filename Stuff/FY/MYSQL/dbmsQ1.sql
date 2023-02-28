show DATABASES;
USE dhiraj_birajdar;
SHOW TABLES;
-- Q 1) Create student table with following fields (roll no, name, address, student mo no, parents mo no, ssc, hsc, pincode)
--    A. select student name who is located on 411041.
--    B. select student record whose name is ram.
--    C. select student name, address, student mo no, where ssc marks is 60.
--    D. select parent mo no whose name is dhiraj.


CREATE TABLE student(roll_no INT(5) PRIMARY KEY NOT NULL,
name VARCHAR(20) NOT NULL,
address VARCHAR(20) NOT NULL,
student_mo_no BIGINT(10),
parents_mo_no BIGINT(10),
ssc INT(2) NOT NULL,
hsc INT(2) NOT NULL,
pin_code INT(6) NOT NULL);

DESC TABLE student;

INSERT INTO student VALUES(101,"xyz","dhayari",8888455445,7888755555,72,78,411010);
INSERT INTO student VALUES(102,"ram","narhe",8888455452,7855755555,60,65,411041);
INSERT INTO student VALUES(103,"dhiraj","dhayari",8888457545,7888751255,70,78,411010);

SELECT * FROM student;

SELECT name FROM student WHERE pin_code=411010;
SELECT * FROM student WHERE name='ram';
SELECT name,address,student_mo_no FROM student WHERE ssc=60;
SELECT parents_mo_no FROM student WHERE name='dhiraj';

