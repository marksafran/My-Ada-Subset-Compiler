procedure Try is
   X : integer;
begin
   if true then
      null;
   else
      loop
         X := 1;
         exit when false;
      end loop;
   end if;
end;
