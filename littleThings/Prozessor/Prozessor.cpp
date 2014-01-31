#include <iostream.h>

class Licht
{
public:
	bool schwarz;
	bool rot;
	bool blau;
	bool gruen;
	bool rotblau;
	bool rotgruen;
	bool blaugruen;
	bool weiss;
	Licht(bool s=1,bool r=0,bool b=0,bool g=0,bool rb=0,bool rg=0,bool bg=0,bool w=0);
	~Licht();


};

Licht::Licht(bool s,bool r,bool b,bool g,bool rb,bool rg,bool bg,bool w)
{
	schwarz=s;
	rot=r;
	blau=b;
	gruen=g;
	rotblau=rb;
	rotgruen=rg;
	blaugruen=bg;
	weiss=w;
}



class c_Light
{
public:
	c_Light(unsigned short hox=0);
	unsigned short hex;
};

c_Light::c_Light(unsigned short hx)
{
	hex=hx;
}

Licht::~Licht()
{
}



int main()
{
	Licht Laser;
	c_Light Faser(5);

	cout << Laser.schwarz << Laser.rot << Laser.blau << Laser.gruen << Laser.rotblau << Laser.rotgruen << Laser.blaugruen << Laser.weiss << endl;
	cout << Faser.hex << endl;


	return 0;
}