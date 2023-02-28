create or replace function fncurs() returns integer as $c$
declare
--declaring cursor
curs cursor for select * from property;
-- rec property%rowtype;
rec property%rowtype;
n integer:=50000;
begin
--opening crusor
open curs;
loop
-- fetch the table row inside the loop
fetch curs into rec;
update property set rate = n where pno=rec.pno;
n:=n+5000;
-- check if there is no record
-- exit from loop when record not found 
if not found then
exit;
end if;
raise notice 'hi %',rec;
end loop;
close curs;
return 1;
end; $c$
language plpgsql;

select fncurs();

create or replace function square(n int) returns int as $$
begin
return n*n;
end;$$
language plpgsql;

select square(10);