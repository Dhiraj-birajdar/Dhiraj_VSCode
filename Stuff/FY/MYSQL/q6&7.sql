show DATABASES;
USE dbms_practical1;
SHOW TABLES;
-- slip3 Q6. Consider the following entities and their relationships. Create a RDB in 3 NF with
-- appropriate data types and Constraints.
-- Hospital (hno ,hname , city, Est_year, addr)
-- Doctor (dno , dname , addr, Speciality)
-- The relationship between Hospital and Doctor is one - to – Many
-- Constraints: - Primary Key, Est_year should be greater than 1990.
-- Consider the above tables and execute the following queries:
-- 1. Delete addr column from Hospital table.
-- 2. Display doctor name, Hospital name and specialty of doctors from “Pune City” .
-- Q7. Consider the above tables and execute the following queries:
-- 1. Display the names of the hospitals which are located at “Pimpri” city.
-- 2. Display the names of doctors who are working in “Birla” Hospital and city
-- name is “Chinchwad”.
-- 3. Display the specialty of the doctors who are working in “Ruby” hospital.
-- 4. Give the count of doctor’s hospital wise which are located at “Pimple Gurav”.
-- 5. Update an address of Doctor to “Pimpri” whose hospital is “Ruby clinic”.

create table hospital(hno int primary key,hname varchar(20),city varchar(20),est_year numeric(4) check(est_year>1990),addr varchar(20));
insert into hospital values(101,'balaji','pune',1993,'kharadi road');
insert into hospital values(103,'vedant','mumbai',1993,'dharavi');
insert into hospital values(104,'ruby','pimpri',1993,'kharadi road');
insert into hospital values(105,'birla','chinchwad',1993,'tyr');
insert into hospital values(106,'qw','pune',1993,'kalptaru');
select * from hospital;
create table doctor(dno int primary key,dname varchar(20),addr1 varchar(20),speciality varchar(20),hno int references hospital on delete cascade);
insert into doctor values(1,'dr.joshi','pune','skin',104);
insert into doctor values(2,'dr.mane','nashik','surgeon',103);
insert into doctor values(3,'dr.patil','pune','gynecologist',101);
insert into doctor values(4,'dr.Raghav','pune','skin',105);
insert into doctor values(5,'dr.Abhay','mumbai','internist',104);
insert into doctor values(6,'dr.joshi','pune','surgeon',106);
insert into doctor values(7,'dr.Riya','pune','skin',103);
insert into doctor values(8,'dr.Gawade','pune','head',104);
select * from doctor;
select dname,hname,speciality from doctor,hospital where doctor.hno=hospital.hno and city='pune';
select hname from hospital,doctor where doctor.hno=hospital.hno and city='pimpri';
select dname from doctor,hospital where doctor.hno=hospital.hno and hname='birla' and city='chinchwad';
select speciality from hospital,doctor where doctor.hno=hospital.hno and hname='ruby';
select hname,count(dno) from doctor,hospital where doctor.hno=hospital.hno and addr='kharadi road' group by hname;
update doctor set addr1='pimpri' where hno in(select hno from hospital where hname='ruby');
-- alter table hospital drop column addr1; (ERROR 1091 (42000): Can't DROP 'addr1'; check that column/key exists);
