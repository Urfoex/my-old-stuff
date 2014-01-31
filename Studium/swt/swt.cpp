#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace::std;
#include "Klassen.h"

// addTail ? f�ge ein neues Element der Liste an
void addTail(NameDataSet* pNDS)
{
    // stelle sicher, dass der Zeigern von *pDNS 
    // ist, weil das zum letzten Listenelement wi
    pNDS->pNext = 0;
    // wenn die Liste leer ist, dann zeige einfac
    // mit dem Kopfzeiger auf den aktuellen Eintr
    // und fertig
    if (pHead == 0)
    {
        pHead = pNDS;
        return;
    }
    // ansonsten finde das letzte Element der Lis
    NameDataSet* pCurrent = pHead;
    while(pCurrent->pNext)
    {
        pCurrent = pCurrent->pNext;
    }
    // jetzt f�ge den aktuellen Eintrag diesem an
    pCurrent->pNext = pNDS;
}
// getData ? lies einen neuen Namen und eine
//           Sozialversicherungsnummer; gib null
//           zur�ck, wenn nichts mehr zu lesen ist
NameDataSet* getData()
{
    // neuer Eintrag, der zu f�llen ist
    NameDataSet* pNDS = new NameDataSet;
    // lies den Vornamen
    cout << "\nVorname:";
    cin >> pNDS->szFirstName;
    // wenn der Vorname ?ende? oder ?ENDE? ist...
    if ((strcmp(pNDS->szFirstName, "ende") == 0)
        ||
        (strcmp(pNDS->szFirstName, "ENDE") == 0))
    {
        // ... l�sche das immer noch leere Objekt ...
        delete pNDS;
        // ... gib eine null zur�ck f�r Eingabeende
        return 0;
    }
    // lies die �brigen Elemente
    cout << "Nachname:";
    cin >> pNDS->szLastName;
    cout << "Sozialversicherungsnummer:";
    cin >> pNDS->nSocialSecurity;
    // Zeiger auf n�chstes Element auf null setzen
    pNDS->pNext = 0;
    // gib die Adresse auf das neue Element zur�ck
    return pNDS;
}
// displayData ? Ausgabe des Datensatzes
//auf den pDNS zeigt
void displayData(NameDataSet* pNDS)
{
    cout << pNDS->szFirstName
         << " "
         << pNDS->szLastName
         << "/"
         << pNDS->nSocialSecurity
         << "\n";
}
int main(int nArg, char* pszArgs[])
{
    cout << "Lies Vornamen, Nachnamen und\n"
         << "Sozialversicherungsnummer\n"
         << "Geben Sie ?ende? als Vorname ein, um\n"
         << "das Programm zu beenden\n";
  // erzeuge (weiteres) NameDataSet-Objekt
  NameDataSet* pNDS;
  while (pNDS = getData())
  {
      // f�ge es an die Liste der
      // NameDataSet-Objekte an
      addTail(pNDS);
  }
  // um die Objekte anzuzeigen, iteriere durch die
  // Liste (stoppe, wenn die n�chste Adresse
  // null ist)
  cout << "Entries:\n";
  pNDS = pHead;
  while(pNDS)
  {
      // Anzeige des aktuellen Eintrags
      displayData(pNDS);
      // gehe zum n�chsten Eintrag
      pNDS = pNDS->pNext;
  }
  return 0;
}
