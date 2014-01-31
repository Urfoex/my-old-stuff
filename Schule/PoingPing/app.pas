program main;

uses crt;

var i:integer;
var ballx,bally,x,y,loli,lola:integer;

begin

	clrscr;
    WriteLn('*-------------------*');
	WriteLn('*-Ultimate-PongPing-*');
	WriteLn('*-------------------*');
	WriteLn;
	writeln;
	(*writeln('Use "D" and "L" to move the paddle.');*)
	writeln;
	writeln;

	for i:=3 downto 1 do
	begin
		writeln('The game will start in ',i,'seconds');
		delay(1000);
	end;

	clrscr;
	bally:=12;
	ballx:=3;
	x:=1;
	y:=1;
	loli:=12;
	lola:=12;

	while not (ballx=1) do
	begin
		
		if(bally=2) then y:=y*(-1);
		if(bally=23) then y:=y*(-1);

		if(ballx=79) then x:=x*(-1);
		if(ballx=2) then x:=x*(-1);

		if(keypressed) then halt;

		(*textcolor(black);
		gotoxy(ballx-1,bally);
		write('*');
		gotoxy(ballx+1,bally);
		write('*');
		gotoxy(ballx,bally-1);
		write('*');
		gotoxy(ballx,bally+1);
		write('*');
		gotoxy(ballx-1,bally-1);
		write('*');
		gotoxy(ballx-1,bally+1);
		write('*');
		gotoxy(ballx+1,bally-1);
		write('*');
		gotoxy(ballx+1,bally+1);
		write('*');

		gotoxy(80,bally-1);
		write('[');
		gotoxy(80,bally+1);
		write('[');
		gotoxy(1,bally-1);
		write(']');
		gotoxy(1,bally+1);
		write(']');*)

		clrscr;
		
		textcolor(white);
		gotoxy(ballx,bally);
		write('*');


		if(x<0) then
		begin
			textcolor(green);
			gotoxy(1,bally);
			write(']');
			loli:=bally;
			textcolor(red);
			gotoxy(80,lola);
			write('[');
		end;

		if(x>0) then
		begin
			textcolor(red);
			gotoxy(80,bally);
			write('[');
			lola:=bally;
			textcolor(green);
			gotoxy(1,loli);
			write(']');
			end;

		textcolor(yellow);
		gotoxy(1,1);
		for i:=1 to 80 do
		begin
			write('-');
		end;
		
		gotoxy(1,24);
		for i:=1 to 80 do
		begin
			write('-');
		end;
		
		delay(48);

		ballx:=ballx+x;
		bally:=bally+y;

	end;
	
end.
