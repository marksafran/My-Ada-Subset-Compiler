--nestElsif.ada

procedure main is
        a,b:integer;
begin
        if a = 2 then
	   if b = a then
	      a := 5;
	      write(a);
	   else
	      b := 10;
	      write(b);
	   end if;
        elsif b < a then
           a := b;
	   read(a);
        elsif a < b then
           null;
	   read(b);
        else
	   a := b * 2 * a;
           write(a+b);
        end if;
end;

