// NameDataSet ? speichere Vorname, Name und
//               Sozialversicherungsnummer
class NameDataSet
{
    public:
        char szFirstName[128];
        char szLastName [128];
        int nSocialSecurity;
        // der Verweis auf das nächste Listenelem
        NameDataSet* pNext;
};
// der Zeiger auf den ersten Eintrag der Liste
NameDataSet* pHead = 0;