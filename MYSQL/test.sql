show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip9 Q3. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Property (pno, desc, area, rate)
-- Owner (owner_name, addr, phno)
-- The relationship between owner and Property is One to Many.
-- Constraint: Primary key, rate should be > 0
-- Consider the above tables and execute the following queries:
-- 1. Display area of property whose rate is less than 100000.
-- 2. Give the details of owner whose property is at “Pune” .
-- Q4. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display area wise property details.
-- 2. Display property owned by 'Mr.Patil' having minimum rate.
-- 3. Delete all properties from “pune” owned by “Mr. Joshi”.
-- 4. Update the phone Number of “Mr. Joshi” to 9922112233 who is having
-- property at “Uruli Kanchan”.
-- 5. Delete column address from Owner table.

create table property(pno int primary key,des varchar(20) not null,area varchar(20) not null,rate int check(rate>0));
insert into property values(101,'vegr','nashik',1030000);
insert into property values(102,'tr','Pune',100000);
insert into property values(103,'vbh','pune',1030000);
insert into property values(104,'vsdr','mumbai',20000);
insert into property values(105,'hjjr','nashik',10000);
select * from property;
create table powner(name varchar(20),addr varchar(20),phno varchar,pno int,foreign key(pno) references property(pno));
insert into powner values('Mr.Mane','Mumbai',1762386534,101);
insert into powner values('Mr.Patil','Mumbai',1762386534,102);
insert into powner values('Mr.Joshi','Pune',6892386534,103);
insert into powner values('Mr.Bhagat','Pune',6876783865,101);
insert into powner values('Mr.Abhay','Pune',6753386534,104);
select * from powner;
select area from property where rate>100000;
select * from powner where addr='Pune';
select area,des from property order by area;
select min(rate) from property,powner where property.pno=powner.pno and name='Mr.Patil';
delete from powner where addr='Pune' and name='Mr.Joshi';
update powner set phno=9922112233 where addr='Urali Kanchan';
Alter table powner drop column addr;












-- slip10 Q3. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Employee (emp_no, name, skill, payrate)
-- Position (posting_no, skill)
-- The relationship between Employee and Position is Many to Many with day and shift as
-- descriptive attribute.
-- Constraint: Primary key, payrate should be > 0.
-- Consider the above tables and execute the following queries:
-- 1. Display skill of employees name wise.
-- 2. Update the posting of employee to 220 whose skill is “Manager”.
-- Q4. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Find the names and rate of pay of all employees who has allocated a duty.
-- 2. Give employee number who is working at posting_no. 201, but don’t have the skill of waiter.
-- 3. Display a list of names of employees who have skill of chef and who has assigned a duty.
-- 4. Display shift wise employee details.
-- 5. Update payrate of employees to 20000 whose skill is waiter.

create table employee(eno int primary key,name varchar(20),skill varchar(20) not null,payrate int check(payrate>0));
insert into employee values(1,'Rghav','manager',23000);
insert into employee values(2,'Mane','waiter',23000);
insert into employee values(3,'Priya','ceo',23000);
insert into employee values(4,'Abhay','chef',23000);
select * from employee;
create table position(pno int primary key,skill varchar(20),eno int references employee);
insert into position values(201,'mg',1);
insert into position values(203,'ceo',2);
insert into position values(202,'wt',3);
insert into position values(205,'wdf',4);
insert into position values(204,'whd',2);
select * from position;
create table ep(epno int primary key,eno int references employee,pno int references position);
insert into ep values(11,1,201);
insert into ep values(12,2,202);
insert into ep values(13,2,203);
insert into ep values(14,3,202);
insert into ep values(15,1,204);
select * from ep;
select name,skill from employee order by name;
update position set pno=220 where skill='mg';
select name,payrate from employee;
select employee.name,employee.skill from employee,position,ep where employee.eno=ep.eno and position.pno=ep.pno and position.pno=201 and employee.skill not in('waiter');
select name from employee,position,ep where employee.eno=ep.eno and position.pno=ep.pno and employee.skill='chef';
select name,employee.skill from employee,position,ep where employee.eno=ep.eno and position.pno=ep.pno group by employee.skill,name;
update employee set payrate=20000 where skill='waiter';