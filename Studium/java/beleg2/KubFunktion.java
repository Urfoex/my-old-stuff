package belegzwei;

public interface KubFunktion {
	public void init(double a, double b, double c, double d);
	public double funktionswert(double x);
	public int anzahlNullstellen(double xunten, double xoben);
	// die reellwertigen Nullstellen im Intervall [xunten...xoben] 
	// werden berechnet
	// gueltige Rueckgabewerte sind 0, 1, 2 und 3 
	// bei unendlich vielen Nullstellen wird 0 zurueckgegeben
	public double nullstelleNr(int i);
	// liefert die i-te Nullstelle (Wert fuer x) aufsteigend sortiert
	// existiert diese Nullstelle nicht, wird 0 zurückgegeben
	public KubFunktion differenziere();
	// liefert ein neues Objekt
	public KubFunktion integriere();
	// liefert null, wenn das Ergebnis nicht kubisch darstellbar ist
}
