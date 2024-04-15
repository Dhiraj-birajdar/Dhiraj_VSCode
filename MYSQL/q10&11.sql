show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip7 Q10. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Room (roomno, desc, rate)
-- Guest (gno, gname, no_of_days)
-- The relationship between Room and Guest is One to One.
-- Constraint: Primary key, no of days should be > 0.
-- Consider the above tables and execute the following queries:
-- 1. Update the rate of room to 5000 whose type is “AC”.
-- 2. Display the name of guest who is staying 2 days in roomno 101.
-- Q11. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display room details according to its rates in ascending order.
-- 2. Display the roomno in which “Mr. Advait” is staying for 7 days.
-- 3. Find no. of AC rooms.
-- 4. Find names of guest with maximum room charges.
-- 5. Display guest wise halt days.

create table room(rno int primary key,des varchar(20),rate int);
insert into room values(101,'A/C',1500);
insert into room values(102,'Non A/C',750);
insert into room values(103,'A/C',2000);
insert into room values(104,'Non A/C',1200);
select * from room;
create table guest(gno int primary key,gname varchar(20),nod int);
insert into guest values(101,'Mr.Bharat',3);
insert into guest values(102,'Mr.Nilesh',4);
insert into guest values(103,'Mr.Advait',7);
insert into guest values(104,'Miss.Sapana',2);
select * from guest;
update room set rate=5000 where des='A/C';
select gname from room,guest where nod=2 and rno=101;
select des,rate from room order by des asc;
select rno from room,guest where room.rno=guest.gno and gname='Mr.Advait' and nod=7;
select count(rno) from room where des='A/C';
select gname from room,guest where guest.gno=room.rno and rate=(select max(rate) from room);
Select gname,nod from guest Order by gname;
