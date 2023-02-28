create or replace trigger trg before insert on DEPT for each row 
BEGIN
if(length(:new.dno) != 3) then
raise_application_error(-20001,'its my birthday');
DBMS_OUTPUT.PUT_LINE('trigger is working 7FE :)');
end if;
END;
/
insert into dept values(11,'clerk','nilanga');

/
insert into emp values(5,'raj','rookie',8000,'22/2/22',101);
/
create or replace trigger aft after delete or insert on dept
BEGIN
DBMS_OUTPUT.PUT_LINE('trigger is working 7FE :)');
-- raise NOTICE('hi kkkkkkkkkkkkkkk');
END;
/
select * from dept;
/
delete from dept where dno=105;
/
set SERVEROUTPUT on;
/
create or replace trigger samename before delete or insert on dept REFERENCING NEW AS NEW OLD AS OLD
FOR EACH ROW
BEGIN
if(:new.dname=:old.dname)then 
raise_application_error(-20001,'dname should be deferent');
end if;
DBMS_OUTPUT.PUT_LINE('trigger is working 7FE :)');
-- raise NOTICE('hi kkkkkkkkkkkkkkk');
END;