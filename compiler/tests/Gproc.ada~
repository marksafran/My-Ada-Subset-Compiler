-- proc.ada

procedure Main is
   A, B : integer;
   procedure Inner (X : in out integer; Y : in integer) is
      Z : integer;
   begin
      X := 2;
      Z := 3;
   end;
   procedure Nest is
      procedure Inner is
         procedure Innner is
         begin
            Nest;
            Inner;
         end;
      begin
         Innner;
      end;
   begin
      Inner;
   end;
   procedure Outer is
   begin
      null;
   end;

begin
   Inner (A, 5 + 4);
   Inner (B, 8);
   Nest;
end;
