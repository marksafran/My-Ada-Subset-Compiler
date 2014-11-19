procedure main is             --ck3.ada
   x : integer;
   a, b : integer;
   c, e, ffff, h : integer;
   x : boolean;       --duplicate id should not be inserted in symTab
   procedure helper is
      a : integer;  --this id okay because new scope

      procedure Nest is
         a : integer;  -- this one is also ok
         z : boolean;
      begin
         null;
      end;

   begin
       a := 3;
       c := 2;
   end;

begin
   helper;
   x := 5;

end;
