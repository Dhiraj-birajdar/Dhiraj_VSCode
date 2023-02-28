create or replace PROCEDURE pro1(p1 in out text) AS
BEGIN
raise notice 'pro para : %',p1;
-- dbms_output.PUT_LINE('procedure is working '||p1);
END;
/
CREATE OR REPLACE PROCEDURE greetings 
AS 
BEGIN 
   dbms_output.put_line('Hello World!');
END;
/
execute greetings;