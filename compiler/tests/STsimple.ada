procedure main is             --STsimple.ada
   type w is array(0..2) of integer;
   x : w;
   a, b : integer;
   c, e, ffff, h : integer;
   x : boolean;
   --duplicate id should
   --not be inserted in symTab

   procedure helper is
      a : integer;
      --this id okay because new scope

   begin
       a := 3;
       c := 2;
   end;

begin
   helper;
   x := 5;

end;
