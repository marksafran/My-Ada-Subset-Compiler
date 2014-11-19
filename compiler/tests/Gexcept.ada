-- exctest2.txt
procedure E_test is
t, big : integer;
outside_limits : exception;

begin
   read(t);
   big := 10;
   if t > big then
      raise outside_limits;
   end if;
   write(t);

   exception
      when numeric_error => null;
      when outside_limits => t := big;
      when others => t:= 0;
end;

