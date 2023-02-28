create table employee(emp_id integer primary key not null,emp_name varchar2(30),address varchar2(30));
/
create table investment(inv_no integer primary key not null,inv_name varchar2(30),inv_date date,inv_amount integer,emp_id1 integer references employee(emp_id));
/
insert into employee values(1,'amit','bramati');
insert into employee values(2,'amol','pune');
insert into employee values(3,'rahul','satara');
insert into employee values(4,'suresh','sangali');
/
insert into investment values(101,'Fund','25-Jan-2019',30000,1);
insert into investment values(102,'mutual funds','25-Jan-2019',30000,2);
insert into investment values(103,'mutual funds','25-Jan-2019',30000,3);
insert into investment values(104,'RBI Taxable Bonds','25-Jan-2019',30000,4);
/
update investment set inv_name='mutual funds' where inv_no=103;
/
select * from employee;
select * from investment;
/
-- creating procedure --
create or replace procedure pros1 as cursor cur2
is select emp_id, emp_name, address from
investment , Employee where investment.emp_id1=employee.emp_id and inv_name = 'mutual funds';
c cur2%rowtype;
begin
open cur2;
dbms_output.put_line('--**-- Details of Employees invested amount in Mutual Fund --**--');
loop
fetch cur2 into c;
exit when cur2%notfound;
dbms_output.put_line('Employee          Id : '||c.emp_id);
dbms_output.put_line('Employee    Name : '||c.emp_name);
dbms_output.put_line('Employee Address : '||c.address);
end loop;
close cur2;
end;
/
--calling program----
begin
pros1;
end;
/
set SERVEROUTPUT on;
