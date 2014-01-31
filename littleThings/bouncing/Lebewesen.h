class Lebewesen
{
public:
	Lebewesen(unsigned short int iLeben=1,unsigned short int iSchaden=0);

	void setLeben( const unsigned short int& theValue );
	void setPosX( const unsigned short int& theValue );
	void setPosY( const unsigned short int& theValue );
	void setSchaden( const unsigned short int& theValue );
	void setTyp( bool theValue );
	short int getLeben() const;
	unsigned short int getPosX() const;
	unsigned short int getPosY() const;
	unsigned short int getSchaden() const;
	bool getTyp() const;
	
private:
	unsigned short int Schaden, PosX, PosY;
	short int Leben;
	bool Typ;									// 0-> freundlich  1-> aggressiv
};

Lebewesen::Lebewesen(unsigned short int iLeben,unsigned short int iSchaden)
{
	Leben=iLeben;
	Schaden=iSchaden;
	PosX=0;
	PosY=0;
	Typ=0;
}

short int Lebewesen::getLeben() const
{	return Leben; }

void Lebewesen::setLeben( const unsigned short int& theValue )
{	Leben = theValue; }

unsigned short int Lebewesen::getPosX() const
{	return PosX; }

void Lebewesen::setPosX( const unsigned short int& theValue )
{	PosX = theValue; }

unsigned short int Lebewesen::getPosY() const
{	return PosY; }

void Lebewesen::setPosY( const unsigned short int& theValue )
{	PosY = theValue; }

unsigned short int Lebewesen::getSchaden() const
{	return Schaden; }

void Lebewesen::setSchaden( const unsigned short int& theValue )
{	Schaden = theValue; }

bool Lebewesen::getTyp() const
{	return Typ; }

void Lebewesen::setTyp( bool theValue )
{	Typ = theValue; }
