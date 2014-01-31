package belegdrei;

public interface Katalog {
	public void loescheKataloginhalt();
	/* Diese Methode erzeugt einen leeren Katalog */
	
	public boolean importiereTeilkatalog(String datei);
	/* Diese Methode liest die Artikel in der angegebenen
	 * Datei und fuegt sie dem bisherigen Kataloginhalt hinzu.
	 * Im Erfolgsfall wird der Wert true zurueckgegeben, 
	 * falls jedoch die Datei vorhanden war oder nicht das 
	 * richtige Format hatte, wird false zurueckgegeben. Wird 
	 * import eine bereits existierende Artikelnummer eingelesen
	 * so wird der bisherige Preis durch den neuen 
	 * ueberschrieben.
	 */
	
	public int zeigeMinimalenPreis(int praefix);
	/* Diese Methode extrahiert den minimalen Preis aller
	 * Artikel, die mit der angegebenen Nummer beginnen.
	 */
	
	public int zeigeMaximalenPreis(int praefix);
	/* Analog fuer den maximalen Preis */
	
	public int zeigeDurchschnittspreis(int praefix);
	/* Berechnet den Durchschnittspreis für die Artikel
	 * beginnend mit den angegebenen Ziffern 
	 */
}
