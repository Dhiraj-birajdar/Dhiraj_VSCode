show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip2 Q3. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints.
-- Sales_order (ordNo, ordDate)
-- Client (clientNo, ClientName, addr)
-- The relationship between Client & Sales_order is one-to-many.
-- Constraints: - Primary Key, ordDate should not be NULL.
-- Consider the above tables and execute the following queries:
-- 1. Add column amount into Sales_order table with data type int.
-- 2. Delete the details of the clients whose names start with ‘A’ character.
-- Q4. Consider the above tables and execute the following queries:
-- 1. Delete sales order details of client whose name is “Patil” and order date is “09/08/2019”.
-- 2. Change order date of client_No ‘CN001’ to ‘18/03/2019’.
-- 3. Delete all sales_record having order date is before ‘10 /02/2018’.
-- 4. Display date wise sales_order given by clients.
-- 5. Update the address of client to “Pimpri” whose name is ‘Mr. Roy’.

create table client(cno varchar(10) primary key,cname varchar(20),addr varchar(20));
insert into client values('CN001','Abhay','Pune');
insert into client values('CN002','Patil','Pune');
insert into client values('CN003','Mr.Roy','Pimpri');
insert into client values('CN004','Raj','Mumbai');
select * from client;
create table sales_order(ordno int primary key,ordDate varchar(23) not null,cno varchar(10) references client on delete cascade);
insert into sales_order values(1,'23/06/2015','CN001');
insert into sales_order values(2,'09/03/2019','CN002');
insert into sales_order values(3,'09/08/2009','CN004');
insert into sales_order values(4,'09/08/2019','CN002');
select * from sales_order;
alter table sales_order add amount int;
delete from client where cname like'A%';

delete from sales_order where ordDate='09/08/2019' and cno in(select cno from client where cname='Patil');
update sales_order set ordDate='18/03/2019' where cno='CN001';
select ordDate,ordno,amount,cno from sales_order order by ordDate;
delete from sales_order where ordDate<'20/10/2019';
update client set addr='pimpri' where cname='Mr.Roy';