show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip8 Q12. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Book (Book_no, title, author, price, year_published)
-- Customer (cid, cname, addr)
-- Relation between Book and Customer is Many to Many with quantity as
-- descriptive attribute.
-- Constraint: Primary key, price should be >0.
-- Consider the above tables and execute the following queries:
-- 1. Display the name of book whose author is “Mr. Gadhave”.
-- 2. Add column EMailId into customer table.
-- Q13. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display customer details from 'Mumbai'.
-- 2. Display author wise details of book.
-- 3. Display customer name that has purchased more than 3 books.
-- 4. Display book names having price between 100 and 200 and published year is 2019.
-- 5. Update the title of book to “DBMS” whose author is “Mr. Talore”

create table book(bno int primary key,title varchar(10),author varchar(20),price int check(price>0),yp int);
insert into book values(101,'dreams','mr.Raj',150,2017);
insert into book values(102,'life','mr.Raghav',100,2019);
insert into book values(103,'rt story','mr.Gadhave',190,2011);
insert into book values(104,'Dad','dr.Sam',200,2001);
insert into book values(105,'Struggle','mr.Raj',250,2017);
insert into book values(106,'Joker','Mr. Talore',230,2011);
select * from book;
create table customer(cid int primary key,cname varchar(20),addr varchar(20),bno int references book);
insert into customer values(1,'Abhay','pune',101);
insert into customer values(2,'Sam','Mumbai',102);
insert into customer values(3,'Raghav','pimpri',103);
insert into customer values(4,'Abhay','mumbai',104);
insert into customer values(5,'Ganesh','Nashik',105);
select * from customer;
create table customerbook(bcid int primary key,bno int references book,cid int references customer);
insert into customerbook values(11,101,1);
insert into customerbook values(12,102,2);
insert into customerbook values(13,101,3);
insert into customerbook values(14,103,1);
insert into customerbook values(15,106,4);
select * from customerbook;
select title from book where author='mr.Gadhave';
alter table customer add emailID varchar(20);
select * from customer where addr='mumbai';
select author,title from book order by author;
select count(book.bno),cname from customer,book,customerbook where customer.cid=customerbook.cid and book.bno=customerbook.bno and book.bno>3 group by cname;
select book.title from book,customer,customerbook where customer.cid=customerbook.cid and book.bno=customerbook.bno and yp=2019 and price between 100 and 200;
update book set title='DBMS' where author='Mr. Talore';