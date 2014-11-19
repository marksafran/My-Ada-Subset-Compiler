procedure main is             --ck3D.ada
   type w is array(0..2) of integer;
   type ranger is range 0 .. 44;
--   type rec is record
--      A : w;
--      X : ranger;
--   end record;
   x : w;
   a, b : integer;
   c, e, ffff, h : integer;
--   x : boolean;       --duplicate id should not be inserted in symTab
   procedure helper is
      a : integer;  --this id okay because new scope
      bad, error : exception;
      procedure Nest is
         a : ranger;  -- this one is also ok
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
