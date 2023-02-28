show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip1 Q2.Consider the following entities and their relationships. Create a RDB in 3 NF with appropriate data types and Constraints.
-- Emp(eno ,ename ,designation ,salary, Date_Of_Joining)
-- Dept(dno,dname ,loc)
-- The relationship between Dept & Emp is one-to-many.
-- Constraints: - Primary Key, ename should not be NULL, salary must be greater than 0.
-- Consider the above tables and Execute the following queries:
-- 1. Add column phone_No into Emp table with data type int.
-- 2. Delete the details of Employee whose designation is ‘Manager’.
-- Q3. Consider the above database and execute the following queries: [25 Marks]
-- 1. Display the count of employees department wise.
-- 2. Display the name of employee who is ‘Manager’ of “Account Department”.
-- 3. Display the name of department whose location is “Pune” and “Mr. Advait” is working in it.
-- 4. Display the names of employees whose salary is greater than 50000 and department is “Quality”.
-- 5. Update Dateofjoining of employee to ‘15/06/2019’ whose department is ‘computer science’ and name is “Mr. Roy’.
create table dept(dno int primary key,
 dname varchar(20),
 loc varchar(10));
 insert into dept values(101,'computer','pune');
 insert into dept values(102,'computer science','mumbai');
 insert into dept values(103,'Quqlity','mumbai');
 insert into dept values(104,'Account','mumbai');
 select * from dept;
 create table emp(eno int primary key,
ename varchar(20),
designation varchar(20),
salary int,
date_of_joining varchar(20),dno int,
 foreign key(dno) references dept(dno));
 insert into emp values(1,'Mr. Advait','Assistant',54000,'23/03/2002',101);
 insert into emp values(2,'Mr. Roy','ceo',50000,'15/01/2019',102);
 insert into emp values(3,'Mr. Abhay','manager',60000,'10/06/2013',103);
 insert into emp values(4,'Mr. Raghav','manager',420000,'01/03/2003',104);
 select * from emp;
 select count(emp.dno),dname from emp,dept where emp.dno=dept.dno group by dname;
select ename from emp,dept where emp.dno=dept.dno and designation='manager' and dname='Account';
select dname from emp,dept where emp.dno=dept.dno and loc='pune' and ename='Mr. Advait';
select ename from emp,dept where emp.dno=dept.dno and salary>50000 and dname='Quqlity';
update emp set date_of_joining='15/06/2019' where ename='Mr. Roy' and dno=(select dno from dept where dname='computer science');
alter table emp add phone_no int;
 Delete from emp where designation='manager';
 select * from emp;







create table dept(dno int primary key,
 dname varchar(20),
 loc varchar(10));
 insert into dept values(101,'computer','pune');
 insert into dept values(102,'computer science','mumbai');
 insert into dept values(103,'Quqlity','mumbai');
 insert into dept values(104,'Account','mumbai');
 select * from dept;
 create table emp(eno int primary key,
ename varchar(20),
designation varchar(20),
salary int,dno int,
 foreign key(dno) references dept(dno));
 insert into emp values(1,'Mr. Advait','Assistant',54000,101);
 insert into emp values(2,'Mr. Roy','ceo',50000,102);
 insert into emp values(3,'Mr. Abhay','manager',60000,103);
 insert into emp values(4,'Mr. Raghav','manager',420000,104);