-- -- set SERVEROUTPUT on;
-- declare
-- a number:=5445;
-- b number;
-- c number;
-- d VARCHAR(20);
-- e VARCHAR(20):='Hello World !';
-- begin
-- d:='dhiraj birajdar';
-- -- a:=4;
-- b:=3;
-- c:=a+b;
-- dbms_output.put_line(e);
-- DBMS_OUTPUT.PUT_LINE('c = '||c);
-- DBMS_OUTPUT.PUT_LINE(c);
-- DBMS_OUTPUT.PUT_LINE('My name is '||d);
-- end;

declare
    l_today date := sysdate;
begin
    dbms_output.put_line(
           'today is '||to_char(l_today,'Day'));
exception when others then
    dbms_output.put_line(sqlerrm);
end;


DECLARE
-- rec RECORD;
cr EMP%ROWTYPE;
a int;
b varchar(5);
c varchar(1);
BEGIN
-- select * into a,b,c from emp where ID=1;
select * into cr from emp where ID=1;
dbms_output.PUT_LINE(cr.id);
dbms_output.PUT_LINE(cr.name);
dbms_output.PUT_LINE(cr.gender);
-- dbms_output.PUT_LINE(a);
-- dbms_output.PUT_LINE(b);
-- dbms_output.PUT_LINE(c);
-- dbms_output.PUT_LINE(a,b,c);
END;

select * from PROPERTY;
select * from LOGMNR_AGE_SPILL$;
drop table help;
select * from emp;

DECLARE
    quantity integer := 30;
BEGIN
    RAISE NOTICE 'Quantity here is %', quantity;  -- Prints 30
    quantity := 50;
    --
    -- Create a subblock
    --
    DECLARE
        quantity integer := 80;
    BEGIN
        RAISE NOTICE 'Quantity here is %', quantity;  -- Prints 80
        RAISE NOTICE 'Outer quantity here is %', outerblock.quantity;  -- Prints 50
    END;

    RAISE NOTICE 'Quantity here is %', quantity;  -- Prints 50

    RETURN quantity;
END;


















--continue from here 14-5-22
create FUNCTION geti(int) RETURN varchar(20) AS
DECLARE
n ALIAS for $1;
a VARCHAR(20);
BEGIN
SELECT into a AREA from PROPERTY where PNO=1;
RETURN a;
END;

DECLARE
ar VARCHAR(20);
BEGIN
ar:=geti(104);
dbms_output.PUT_LINE(ar);
END;