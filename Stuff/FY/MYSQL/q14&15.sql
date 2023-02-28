show DATABASES;
USE dbms_practical1;
SHOW TABLES;
--slip13 Q14. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints. [15 Marks]
-- Driver (driver_id, driver_name, address)
-- Car (license_no, model, year)
-- Relation between Driver and Car is Many to Many with date and time as
-- descriptive attribute.
-- Constraint: Primary key, driver_name should not be null.
-- Consider the above tables and execute the following queries:
-- 1. Display the name of driver whose license no is “DPU123”.
-- 2. Delete the details of car whose model is “swift”.
-- Q15. Consider the above tables and execute the following queries: [25 Marks]
-- 1. Display details of all persons who are driving ‘Alto’ car.
-- 2. Update model of car to “SUV300” whose manufactured year is 2019.
-- 3. Display car details manufactured before year 2000.
-- 4. In which day ‘Mr. Ram’ drives maximum number of cars.
-- 5. Display total number of drivers who drives car in each year
create table driver(did int primary key,dname varchar(10),addr varchar(10));
insert into driver values(101,'Raghav','pune');
insert into driver values(102,'ram','mumbai');
insert into driver values(103,'Abhay','pune');
insert into driver values(104,'Ganesh','Nanded');
insert into driver values(105,'Ritik','Nashik');
select * from driver;
create table car(lno varchar(10) primary key,model varchar(10),year int,did int references driver);
insert into car values('DPU123','alto',1987,101);
insert into car values('DPU781','SUV500',2019,103);
insert into car values('DPU231','swif',2001,105);
insert into car values('DPU018','ty12',1999,102);
insert into car values('DPU810','nh79',2001,104);
select * from car;
create table dc(dco int primary key,did int references driver,lno varchar(10) references car);
insert into dc values(301,101,'DPU123');
insert into dc values(302,102,'DPU781');
insert into dc values(303,103,'DPU123');
insert into dc values(304,101,'DPU018');
insert into dc values(305,105,'DPU810');
select * from dc;
select dname from driver,car,dc where driver.did=dc.did and car.lno=dc.lno and car.lno='DPU123';
select dname from driver,car,dc where driver.did=dc.did and car.lno=dc.lno and model='Alto';
update car set model='SUV300' where year=2019;
select count(car.model),dname from driver,car,dc where driver.did=dc.did and car.lno=dc.lno and dname='ram' group by dname;
select count(driver.did),year,dname from driver,car,dc where driver.did=dc.did and car.lno=dc.lno group by year,dname;
delete from car where model='swif';
