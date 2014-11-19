-- proc.ada
procedure main is
   procedure nest is
      procedure inner is
         procedure innest is
         begin
             nest;   -- call parent  (needs patch)
             inner;  -- call grandparent  (needs patch)
         end;
      begin
         innest; -- call child
      end;
  begin
      inner;  -- call child
  end;
  procedure outer is
  begin
      null;
  end;
begin
  nest; -- call child
end;
