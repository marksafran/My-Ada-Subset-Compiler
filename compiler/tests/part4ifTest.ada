procedure main is
   a, b : integer;
   c : boolean;

begin
   loop
      a := 5;
      exit;
      b := a;
   end loop;

   c := true;

   if a = b then
      b := a + a;
      if b = a then
         b := a + a;
      else
         a := 4;
         b := a + 2 + a;
      end if;
   else
        b := b * b * 2;
   end if;

   b := 2;
end;
