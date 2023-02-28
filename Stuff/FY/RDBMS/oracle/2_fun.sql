select * from dept;
select * from emp;
/
create or replace function dname(pn in int)
return varchar2 as
pm varchar2(100);
begin
select DNAME into pm from DEPT where DNO=pn;
if sql%found then return(pm);
else return null;
end if;
end;
/
drop FUNCTION fun;
/
DECLARE
a VARCHAR(20);
BEGIN
a:=dname(101);
dbms_output.put_line(a);
END;
/
-- create or replace function fun(pn in varchar)
-- return number as
-- pm number;
-- begin
-- select sum(price) into pm from Book where
-- publication = 'Navneet';
-- if sql%found then return(pm);
-- else return null;
-- end if;
-- end;
/
DECLARE
n varchar(12);
d varchar(12);
-- d date;
BEGIN
select ename,DATE_OF_JOINING into n,d from emp where eno=3;
dbms_output.put_line(n||' joined on '||d);
END;
/
create or replace FUNCTION postdep(n in varchar) return varchar as post emp.DESIGNATION%TYPE;
BEGIN
select DESIGNATION into post from emp where ename=n;
if sql%found then return(post);
else return('no data found :)');
end if;
END;
/
DECLARE
a varchar(20);
BEGIN
a:=postdep('Mr. Abhay');
dbms_output.put_line(a);
END;
/
-- 
create or replace FUNCTION dep(n in varchar) return varchar as dpart dept.DNAME%TYPE;
BEGIN
select dname into dpart from dept where dno=(select dno from emp where ename=n);
if sql%found then return(dpart);
else return null;
end if;
END;
/
DECLARE
a varchar(20);
BEGIN
a:=dep('Mr. Roy');
dbms_output.put_line(a);
END;
/

select dname from dept where dno=(select dno from emp where ename='Mr. Roy');
/
create or replace FUNCTION sumsal(m in VARCHAR) return number as sm number(8);
BEGIN
select SUM(emp.SALARY) into sm from emp where DESIGNATION=m;
return sm;
END;
/
DECLARE
a number(8);
BEGIN
a:=sumsal('manager');
dbms_output.put_line(a);
END;

/
