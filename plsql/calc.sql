set serveroutput on;
declare
a number;
b number;
op char(3);
begin
op:=&op;
a:=&a;
b:=&b;
case op 
when '+' then dbms_output.put_line('SUM ='||to_char(a+b));
when '-' then dbms_output.put_line('SUB ='||to_char(a-b));
when '*' then dbms_output.put_line('MUL ='||to_char(a*b));
when '/' then dbms_output.put_line('SUM ='||to_char(a/b));
end case;
 end;
/