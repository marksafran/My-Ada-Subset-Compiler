-- procWB.ada
procedure main is
   a : integer;
   procedure upper is
   begin
       null;
   end;
   procedure nest is
      bbb : boolean;
       procedure inner is
           procedure innest is
           begin
              a := 5;   -- big walkback to get a's base
              upper;    -- must walkback static links here
           end;
       begin
          innest;
          bbb := true;  --one walkback
       end;
   begin
       bbb := false;  -- local access
       upper;  --call sibling (get caller's static link)
       inner;  --call child
   end;
begin
   nest;
end;
