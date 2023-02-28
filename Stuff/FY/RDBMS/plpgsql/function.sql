create table property(
    pno int primary key,
    des varchar(20) not null,
    area varchar(20) not null,
    rate int check(rate > 0)
);
insert into property
values(101, 'vegr', 'nashik', 1030000);
insert into property
values(102, 'tr', 'Pune', 100000);
insert into property
values(103, 'vbh', 'pune', 1030000);
insert into property
values(104, 'vsdr', 'mumbai', 20000);
insert into property
values(105, 'hjjr', 'nashik', 10000);
select *
from property;
-------------------------------------------------------------------
CREATE or REPLACE FUNCTION pro(desi varchar) RETURNS varchar as $ar$
DECLARE ar property.area %type;
BEGIN
select area into ar
from property
where des = desi;
return ar;
end;
$ar$ LANGUAGE plpgsql;
--select pro('tr');
---------------------------------------------------------------
create or REPLACE FUNCTION fn(INTEGER) returns VARCHAR AS 'DECLARE
p alias for $1;
rat property.rate%type;
BEGIN
select rate into rat from property where pno=p;
return rat;
end;' LANGUAGE 'plpgsql';
select fn(101);
---------------------------------------------------------------------
CREATE or REPLACE FUNCTION hi(name text) RETURNS text AS $hi$
declare begin -- raise log 'hello,%',name;
    return raise log 'hello,%',name;
end;
$hi$ LANGUAGE plpgsql;

select hi('dhiraj');
----------------------+
drop FUNCTION hi;-----|
----------------------+
CREATE OR REPLACE FUNCTION totalRecords ()
RETURNS integer AS $total$
declare
	total integer;
BEGIN
   SELECT count(*) into total FROM property;
   RETURN total;
END;
$total$ LANGUAGE plpgsql;

select totalRecords();
-------------------------------
create or replace function forloop(nam varchar(8),no integer) returns void as $forloop$
declare
counter integer;
begin
for counter in 0..no by 2 loop
raise notice 'counter : %,  %',counter,nam;
end loop;
-- return counter;
end;
$forloop$
language plpgsql;

select forloop();

drop function forloop(nam varchar(8));
-----------------------------------------------------
create or replace function grle(in a int,in b int,in c int,out hi int,out lo int) as
'begin
hi := greatest(a,b,c);
lo:=least(a,b,c);
end;'
language 'plpgsql';
----------------------------
create or replace function grle(in a int,in b int,in c int,out hi int,out lo int) as $g$
begin
hi := greatest(a,b,c);
lo:=least(a,b,c);
end; $g$
language plpgsql;

drop function grle;

select grle(10,7,4);