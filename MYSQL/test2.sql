show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- Q3. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Bill (billno, day, tableno, total)
-- Menu (dish_no, dish_desc, price)
-- The relationship between Bill and Menu is Many to Many with quantity as descriptive attribute.
-- Constraint: Primary key, price should be > 0.
-- Consider the above tables and execute the following queries:
-- 1. Display the tableno whose dish_desc is “Veg”.
-- 2. Display the special menu of Monday.
-- Q4. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display receipt which includes bill_no with Dish description, price, quantity and total amount of each menu.
-- 2. Find total amount collected by hotel on date 09/07/2019.
-- 3. Count number of menus of billno 301.
-- 4. Display menu details having price between 100 and 500.
-- 5. Display the tableno and day whose bill amount is zero.

create table bill(bno int primary key not null,day varchar(10),tbno int,total int);
insert into bill values(301,'monday',109,1120);
insert into bill values(302,'sunday',123,9120);
insert into bill values(303,'tuesday',122,4200);
insert into bill values(304,'monday',176,2210);
select * from bill;
create table menu(mno int primary key not null,ddes varchar(10), price int check(price>0),bno int references bill);
insert into menu values(101,'veg',200,301);
insert into menu values(102,'non-veg',300,303);
insert into menu values(103,'non-veg',400,301);
insert into menu values(104,'veg',250,301);
insert into menu values(105,'non-veg',800,302);
insert into menu values(106,'veg',600,304);    
select * from menu;
create table bm(bmno int primary key,ddate varchar(10),bno int references bill,mno int references menu);
insert into bm values(1,'12/02/10',301,102);
insert into bm values(2,'09/07/19',303,104);
insert into bm values(3,'02/06/11',302,101);
insert into bm values(4,'12/02/09',304,102);
select * from bm;
select tbno from menu,bill,bm where menu.mno=bm.mno and ddes='veg';
select ddes from bill,menu,bm where menu.mno=bm.mno and day='monday';
select sum(bill.total),menu.ddes,menu.price,bm.qunt from bill,menu,bm where bill.tbno=bm.bno and menu.mno=bm.mno group by menu.ddes,menu.price,bm.qunt;
select sum(total) from bill,menu,bm where bill.tbno=bm.bno and menu.mno=bm.mno and ddate='09/07/19';
select count(ddes) from bill,menu,bm where bill.tbno=bm.bno and menu.mno=bm.mno and bill.tbno=301;
select ddes,price from menu where price between 100 and 500;
select tbno,day from bill where total=0;