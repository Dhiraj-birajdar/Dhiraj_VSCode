show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip4 Q8. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Patient (PCode, Name, Addr, Disease)
-- Bed (Bed_No, RoomNo, loc)
-- Relationship: - There is one-one relationship between patient and bed.
-- Constraints: - Primary key, RoomNo must be greater than Bed_No, Addr should not be null.
-- Consider the above tables and execute the following queries:
-- 1. Display the details of patients who are from “Pimple Gurav”.
-- 2. Delete the details of patient whose Bed_No is 1 and RoomNo is 105.
-- Q9. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display the count of patient room wise.
-- 2. Display the names of patients who are admitted in room no 101.
-- 3. Display the disease of patient whose bed_No is 1.
-- 4. Display the room_no and bed_no of patient whose name is “Mr Roy”.
-- 5. Give the details of Patient who is admitted on 2nd flr in roomno 102.

create table patient(pcode int primary key,name varchar(20) not null,addr varchar(20),disease varchar(10));
insert into patient values(11,'Raghav','pimple gurav','listeria');
insert into patient values(12,'Abhay','pune','norovirus');
insert into patient values(13,'Mr.Roy','mumbai','cholera');
insert into patient values(14,'Sachin','pimple gurav','dengue');
insert into patient values(15,'Priya','nashik','listeria');
select * from patient;
create table bed(bno int primary key,rno int not null,loc varchar(10) not null,pcode int references patient on delete cascade);
insert into bed values(1,105,'pune',11);
insert into bed values(2,102,'2nd floor',12);
insert into bed values(3,103,'4th floor',13);
insert into bed values(4,104,'1st floor',11);
insert into bed values(5,105,'3rd floor',14);
insert into bed values(6,106,'2nd floor',15);
select * from bed;
select * from patient where addr='pimple gurav';
select * from patient,bed where patient.pcode=bed.pcode and bno=1 and rno=105;
select count(patient.pcode) from patient,bed where patient.pcode=bed.pcode group by rno;
select name from patient,bed where patient.pcode=bed.pcode and rno=102;
select disease from patient,bed where patient.pcode=bed.pcode and bno=1;
select rno,bno from patient,bed where patient.pcode=bed.pcode and name='Mr.Roy';
select * from patient,bed where patient.pcode=bed.pcode and loc='2nd floor' and rno=102;