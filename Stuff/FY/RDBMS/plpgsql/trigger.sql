CREATE or REPLACE FUNCTION trg() RETURNS trigger AS $BODY$ BEGIN if NEW.pno > 110 THEN raise exception 'pno is greater than 110';
end if;
return NEW;
end;
$BODY$ language plpgsql;
create or replace TRIGGER tr BEFORE
insert
    or
update on property for each row EXECUTE procedure trg();
------trigger
insert into property values(112, 'hjjr', 'nashik', 10000);
-------------------

drop trigger tr;
select * from property;
----------------------

create or replace function r100() returns trigger as $$
begin 
if NEW.rate <0 or NEW.rate>100 THEN
raise exception 'rate should be 0 to 100';
end if;
end;$$
language 'plpgsql';


create or replace trigger r0 before insert on property for each row
EXECUTE procedure r100();



insert into property values(113, 'hjjr', 'nashik', 10000);













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
date_of_joining date,dno int,
 foreign key(dno) references dept(dno));
 insert into emp values(1,'Mr. Advait','Assistant',54000,'2002-03-24',101);
 insert into emp values(2,'Mr. Roy','ceo',50000,'2019-01-15',102);
 insert into emp values(3,'Mr. Abhay','manager',60000,'2013-06-10',103);

 insert into emp values(4,'Mr. Raghav','manager',420000,'2022-08-05',104);
 select * from emp;

 drop table emp;





 create or replace function date() returns trigger as $$
 begin
 if NEW.date_of_joining> now() THEN
 raise exception ' % date should not be greater than today',NEW.date_of_joining;
 end if;
 end; $$
 language 'plpgsql';

 create or replace trigger today before insert on emp for each row 
 EXECUTE procedure date();










 create or replace function c() returns int as $$
 declare
 n int;
 begin
 select count(*) into n from emp;
 raise notice 'count is %',n;
 return n;
 end;
 $$ language 'plpgsql';

 SELECT c();








 create or replace function ff(a int) returns void as $$
 declare
 na varchar(20);
 de text;
 sa integer;
-- ii record;
 begin
 --select into ii ename,designation,salary from emp where eno=a;
 select into na,de,sa ename,designation,salary from emp where eno=a;
raise log 'hi';
 --return na,de,sa;
raise notice 'name : % desi : % sal : %',na,de,sa;
--  return ii;
 end;$$
 language 'plpgsql';

 select ff(1);

 drop function ff(a int);








 create or replace function curs() returns int as $$
 declare
 q cursor for select * from dept where loc!='mumbai';
 rec record;
 begin
 open q;
 loop
 fetch q into rec;
 if not found THEN
 exit;
 end if;
 raise notice '% %',rec.dno,rec.dname;
 end loop;
 close q;
 return 1;
 end; $$
 language 'plpgsql';

 select curs();