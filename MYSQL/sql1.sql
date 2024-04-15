show databases;
create schema if not exists college;
drop schema if exists test;
use college;
show tables;
select * from student;
alter table student add column gender char;
select * from world.city limit 10;
select database();
select now();
desc world.city;
create table India as select * from world.city where countrycode= "IND";
create view mh as select * from india where district = "maharashtra";
select * from mh;
select * from india order by population desc;
select max(population) from india;
select id, avg(population) from india group by id;
select * from world.city where countrycode = (select countrycode from world.city where name = "new york");

use sakila;
show tables;
select * from actor limit 10;
select * from actor_info limit 10;
select * from film limit 10;
select release_year, count(film_id) from sakila.film group by release_year;
select count(film_id) from sakila.film where release_year = 2006;
select countrycode , count(name) from world.city group by countrycode;
select countrycode , count(name) from world.city group by countrycode having countrycode = "ind" or countrycode = "Usa"  ;
select count(id) from college.india;
select avg(population) from world.city;


 


