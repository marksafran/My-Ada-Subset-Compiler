procedure Main is       --rel.ada
   X,Y,Z : integer;
begin                           --this is a test

   X := 5;
   Y := 6;
   Z := 7;
   X := X and Y;
   Y := X or Y;
   X := X = Y;
   Y := Z < Y;
   Z := Z <= X;
   X := Y > Z;
   Y := Z >= X;

   Y := not X;
   Z := - Y;
end;
