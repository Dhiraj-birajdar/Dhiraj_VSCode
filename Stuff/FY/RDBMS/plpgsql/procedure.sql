create procedure pro1(inout p1 text) as $$
begin
raise notice 'procedure parameter : % ',p1;
end $$
language plpgsql;
\df
call pro1('procedure is working :)');