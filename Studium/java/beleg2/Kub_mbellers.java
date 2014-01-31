package belegzwei;

public class Kub_mbellers implements KubFunktion {

	private double x1 = Double.NaN, x2 = Double.NaN, x3 = Double.NaN;
	private double tx1 = Double.NaN, tx2 = Double.NaN, tx3 = Double.NaN;
	private double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	private int anzNst = 3;
	
	final public double nstAt( int i){
		switch(i){
			case 1:		return x1;
			case 2:		return x2;
			case 3:		return x3;
			default:	return Double.NaN;
		}
	}
	
	private void searchNullstellen(){
		if( a == 0 ){
			if( b == 0){
				if( c != 0)
					tx1 = -d / c; // lineare Funktion
				return;	// c == 0 && d == 0 -> unendlich, c == 0 && d != 0 -> keine
			}
			///////////////////////////
			// quadratische Funktion //
			///////////////////////////
			if(( c * c /( b * b * 4) - d / b) > 0){
				tx1 = -c /( b * 2.0) + Math.sqrt( c * c /( b * b * 4.0) - d / b);
				tx2 = -c /( b * 2.0) - Math.sqrt( c * c /( b * b * 4.0) - d / b);
			}else{
				if(( c * c /( b * b * 4) - d / b) == 0)
					tx1 = -c /( b * 2.0);
			}
			return;
		}
		if( d == 0){
			//////////////////////////////////
			// ausklammern -> Vereinfachung //
			//////////////////////////////////
			tx1 = 0.0;
			if( c == 0){
				if( b != 0)
					tx2 = -b / a;		// lineare Funktion
				return;
			}
			///////////////////////////
			// quadratische Funktion //
			///////////////////////////
			if(( b * b /( a * a * 4.0) - c / a) > 0){
				tx2 = -b /( a * 2.0) + Math.sqrt( b * b /( a * a * 4.0) - c / a);
				tx3 = -b /( a * 2.0) - Math.sqrt( b * b /( a * a * 4.0) - c / a);
			}else{
				if(( b * b /( a * a * 4.0) - c / a) == 0)
					tx2 = -b /( a * 2.0);
			}
			return;
		}
		///////////////////////////////////////
		// Nullstellenannaeherung mit Newton //
		///////////////////////////////////////
		newton();
		if( Double.isNaN( tx1))
			return;
		double test = funktionswert( tx1);
		if( Math.abs( test) > 0.00001){
			tx1 = Double.NaN;
			return;
		}
		//////////////////////////////////////////////
		// Polynomdivision -> quadratische Funktion //
		//////////////////////////////////////////////
		Kub_mbellers temp = new Kub_mbellers();
		temp.init(0, a, a * tx1 + b, a * tx1 * tx1 + b * tx1 + c);
		tx2 = temp.nstAt( 1);
		tx3 = temp.nstAt( 2);
	}
	
	private void newton(){
		double tempx1 = 0.0, tempx2 = 0.0;
		double trouble1 = 0.0, trouble2 = 0.0;
		KubFunktion tempDiff = differenziere();
		do{
			tempx1 = tempx2;
			trouble1 = funktionswert( tempx1);
			trouble2 = tempDiff.funktionswert( tempx1);
			if( trouble2 == 0){
				if( trouble1 == 0){
					tempx2 = tempx1;
					break;
				}
				trouble2 = 0.1;
			}
			tempx2 = tempx1 - trouble1 / trouble2; 
		}while( (( tempx2 - tempx1) > 0.00000000000001) || (( tempx2 - tempx1) < -0.00000000000001));
		tx1 = tempx2;
	}
	
	public int anzahlNullstellen( double xunten, double xoben) {
		int temp = 0;
		if( anzNst == 0) return 0;

		x3 = tx3;
		x2 = tx2;
		x1 = tx1;

		if( !Double.isNaN( tx3)){
			if( tx3 < xunten || tx3 > xoben){
				x3 = Double.NaN;
			}else
				++temp;
		}
		if( !Double.isNaN( tx2)){
			if( tx2 < xunten || tx2 > xoben){
				x2 = tx3;
				x3 = Double.NaN;
			}else
				++temp;
		}
		if( !Double.isNaN( tx1)){
			if( tx1 < xunten || tx1 > xoben){
				x1 = tx2;
				x2 = tx3;
				x3 = Double.NaN;
			}else
				++temp;
		}
		return temp;
	}

	public KubFunktion differenziere() {
		KubFunktion temp = new Kub_mbellers();
		temp.init( 0, 3.0 * a, 2.0 * b, c);
		return temp;
	}

	final public double funktionswert( double x) {
		return a * x * x * x + b * x * x + c * x + d; 
 	}

	public void init( double a, double b, double c, double d) {
		x1 = Double.NaN;
		x2 = Double.NaN;
		x3 = Double.NaN;
		tx1 = Double.NaN;
		tx2 = Double.NaN;
		tx3 = Double.NaN;
		anzNst = 3;
		
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;

		searchNullstellen();
		///////////////////////////////////////
		// Filtern von doppelten Nullstellen //
		///////////////////////////////////////
		if( !Double.isNaN( tx3)){
			if( tx3 == tx2 || tx3 == tx1)
				tx3 = Double.NaN;
			if( tx2 == tx1){
				tx2 = tx3;
				tx3 = Double.NaN;
			}
		}
		if( tx2 == tx1)
			tx2 = Double.NaN;
		sortNst();
		if( Double.isNaN( tx3)) --anzNst;
		if( Double.isNaN( tx2)) --anzNst;
		if( Double.isNaN( tx1)) --anzNst;
		x3 = tx3;
		x2 = tx2;
		x1 = tx1;
	}
	
	private void sortNst(){
		double temp = 0.0;
		if( !Double.isNaN( tx3)){
			if( tx3 < tx2){
				temp = tx2;
				tx2 = tx3;
				tx3 = temp;
			}
			if( tx3 < tx1){
				temp = tx1;
				tx1 = tx3;
				tx3 = temp;
			}
		}
		if( !Double.isNaN( tx2)){
			if( tx2 < tx1){
				temp = tx1;
				tx1 = tx2;
				tx2 = temp;
			}
		}
	}

	public KubFunktion integriere() {
		if( a != 0) return null;
		KubFunktion temp = new Kub_mbellers();
		temp.init( b/3, c/2, d, 0);
		return temp;
	}

	final public double nullstelleNr( int i) {
		if( !Double.isNaN( nstAt( i)))
			return nstAt( i);
		return 0.0;
	}
}
