#include <qtextstream.h>
#include <qfile.h>
#include <qlabel.h>
#include <qstring.h>


void Form3::pushButton1_clicked()
{
    if((lineEdit1->text()!="Name" && lineEdit1->text()!="") && (lineEdit2->text()!="Vorname" && lineEdit2->text()!="") &&  (lineEdit3->text()!="Passwort" && lineEdit3->text()!="") &&  (lineEdit4->text()!="Kontonummer" && lineEdit4->text()!=""))
    {
	lineEdit8->setText("");
	QFile file(lineEdit4->text());
	
	if(!file.open(IO_ReadWrite | IO_Translate))
	{}
                else
                {
	     QTextStream in(&file);
	     in.setEncoding(QTextStream::UnicodeUTF8);
	     if(lineEdit1->text()==in.readLine() && lineEdit2->text()==in.readLine() && lineEdit3->text()==in.readLine())
	     {
	    	Beguenstigter->setEnabled(TRUE);
		QString sGuthaben=("0");
		
		lineEdit10->setText(in.readLine());
		sGuthaben=lineEdit10->text();
		iGuthaben=sGuthaben.toULong();
		
		groupBox2->setEnabled(FALSE); 
	    }
	     file.close();
	 }         
    }
    else
	lineEdit8->setText("Fehler bei der Eingabe.");
}


void Form3::pushButton2_clicked()
{
        if((lineEdit5->text()!="Name" && lineEdit5->text()!="") && (lineEdit6->text()!="Vorname" && lineEdit6->text()!="") && (lineEdit7->text()!="Kontonummer" && lineEdit7->text()!=""))
    {
	    lineEdit8->setText("");
	    QFile file(lineEdit7->text());
	
	if(!file.open(IO_ReadWrite | IO_Translate))
	{}
                else
                {
	    QTextStream in2(&file);
	     in2.setEncoding(QTextStream::UnicodeUTF8);
	       if(lineEdit5->text()==in2.readLine() && lineEdit6->text()==in2.readLine())
	     {
		   lineEdit12->setText(in2.readLine());
		   lineEdit11->setText(in2.readLine());
		   
		   QString sBeguguthaben=("0");
		
		sBeguguthaben=lineEdit11->text();
		iBeguguthaben=sBeguguthaben.toULong();
		
	    	Beguenstigter->setEnabled(FALSE);
		groupBox3->setEnabled(TRUE);
	    }
	       file.close();
	 }
    }
    else
	lineEdit8->setText("Fehler bei der Eingabe.");
}



void Form3::pushButton3_clicked()
{
    QString sBetrag=("0");
    sBetrag=lineEdit8->text();
    iBetrag=sBetrag.toLong();
   
    if(iBetrag>iGuthaben || iBetrag<0)
    {
	lineEdit8->setText("Dieser Betrag ist nicht überweisbar.");
	pushButton3->setEnabled(FALSE);
    }
    else
    {
	iGuthaben=iGuthaben-iBetrag;
	iBeguguthaben=iBeguguthaben+iBetrag;
	QString sBeguguthaben;
	QString sGuthaben;
	
	sGuthaben.setNum(iGuthaben);
	sBeguguthaben.setNum(iBeguguthaben);
	
	lineEdit10->setText(sGuthaben);
	lineEdit11->setText(sBeguguthaben);
	
	pushButton3->setEnabled(FALSE);
	 QFile file(lineEdit4->text());
	
	if(!file.open(IO_ReadWrite | IO_Translate))
	{}
                else
                {
	    QTextStream out(&file);
	     out.setEncoding(QTextStream::UnicodeUTF8);
	     out << lineEdit1->text();
	     out << "\n";
	     out << lineEdit2->text();
	     out << "\n";
	     out << lineEdit3->text();
	     out << "\n";
	     out << lineEdit10->text();
	 }
	file.close();
	
	QFile file2(lineEdit7->text());
	
	if(!file2.open(IO_ReadWrite | IO_Translate))
	{}
                else
                {
	    QTextStream out2(&file2);
	     out2.setEncoding(QTextStream::UnicodeUTF8);
	     out2 << lineEdit5->text();
	     out2 << "\n";
	     out2 << lineEdit6->text();
	     out2 << "\n";
	     out2 << lineEdit12->text();
	     out2 << "\n";
	     out2 << lineEdit11->text();
	 }
	file2.close();
	
	lineEdit8->setText("Der Betrag wurde erfolgreich überwiesen.");
	lineEdit8->setReadOnly(TRUE);
	pushButton3->setEnabled(FALSE);
    }
}

void Form3::lineEdit8_textChanged( const QString & )
{
    pushButton3->setEnabled(TRUE);
}
