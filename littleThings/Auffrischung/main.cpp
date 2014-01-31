#include <iostream>
#include <string>
#include <cstring> // -> A_4::A5
#include <climits> // -> A_2::A2 , A_4::A5
#include <cfloat>  // -> A_2::A3
#include <cmath>   // -> A_3::A4
#include <cstdlib> // -> A_3::A6 , A_3::A7
#include <iomanip> // -> A_4::A3

namespace DBLCRS{
    void DBLCRS(unsigned short int VAR){
        for( unsigned short int i = 0; i < VAR; ++i) std::cout << "#";
        std::cout << '\n';
    }
}

namespace A_1{
    void A4(void);
    void A6(void);

    void A4(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 1:4 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "Name: \t Max Mustermann\n";
        std::cout << "Adresse: Musterstraße 1\n";
        std::cout << "\t 12334 Musterstadt\n";
        std::cout << "Tel: \t 01234/567890\n";
        std::cout << "E-Mail:  Mustermann@Musterstadt.de\n\n";
    }

    void A6(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 1:6 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "******* Telefonverzeichnis *******\n\n";
        std::cout << "    E = Neuen Eintragerstellen\n";
        std::cout << "    L = Eintrag löschen\n";
        std::cout << "    S = Telefonnummer suchen\n";
        std::cout << "    A = Alle Einträge anzeigen\n";
        std::cout << "    B = Programm beenden\n\n";
        std::cout << "Ihre Wahl: \n\n";
    }
}

namespace A_2{
    void A2(void);
    void A3(void);
    void A8(void);

    void A2(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 2:2 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "Wertebereich char - wchar_t\n\n";
        std::cout << "char:\n";
        std::cout << "  min: " << CHAR_MIN << '\n';
        std::cout << "  max: " << CHAR_MAX << '\n' << '\n';
        std::cout << "wchar_t:\n";
        std::cout << "  min: " << WCHAR_MIN << '\n';
        std::cout << "  max: " << WCHAR_MAX << '\n' << '\n';
    }

    void A3(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 2:3 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "*** DOUBLE ***\n\n";
        std::cout << "Speicherplatz: " << sizeof(double) << '\n';
        std::cout << "MAX: " << DBL_MAX << '\n';
        std::cout << "MIN: " << DBL_MIN << '\n';
        std::cout << "Genauigkeit: " << DBL_DIG << '\n' << '\n';
    }

    void A8(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 2:8 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "ASCII 66: " << char(66) << '\n';
        std::cout << "ASCII 98: " << char(98) << '\n' << '\n';
    }
}

namespace A_3{
    void A4(void);
    void A6(void);
    void A7(double VAR);

    void A4(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 3:4 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "Ihre Gleitpunktzahl (GPZ): ";
        double GPZ(0.0);
        std::cin.clear();
        std::cin >> GPZ;
        while( std::cin.fail()){
            std::cout << "! Eingabefehler !\n";
            std::cin.clear();
            while( !std::cin.eof()){ std::cin.get();};
            'ERROR'
            std::cout << "Ihre Gleitpunktzahl (GPZ): ";
            std::cin >>GPZ;
        }
        while( !std::cin.eof()){ std::cin.get();};
        'ERROR'
        std::cin.clear();

        std::cout << "Ihre GPZ: " << GPZ << '\n';
        std::cout << "sin( GPZ): " << sin( GPZ) << '\n';
        std::cout << "cos( GPZ): " << cos( GPZ) << '\n' << '\n';
    }

    void A6(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 3:6 ##\n";
        DBLCRS::DBLCRS(17);
        signed long long Initiator(0), R1(0), R2(0) ;
        std::cout << "Initiator: ";
        std::cin.clear();
        std::cin >> Initiator;
        while( std::cin.fail()){
            std::cout << "! Fehleingabe !\n";
            std::cin.clear();
            while( !std::cin.eof()){ std::cin.get();};
            'ERROR'
            std::cout << "Initiator: ";
            std::cin >> Initiator;
        }
        std::cin.clear();
        while( !std::cin.eof()){ std::cin.get();};
        'ERROR'
        std::cout << "Initiator mit " << Initiator << " initialisiert\n";
        std::srand( Initiator);
        R1 = std::rand();
        std::cout << "Random 1: " << R1 << '\n';
        R2 = std::rand();
        std::cout << "Random 2: " << R2 << '\n';
        std::cout << "Diff: ";
        if( (R2-R1) < 0) std::cout << (R1 - R2);
        else std::cout << (R2 - R1);
        std::cout << '\n' << '\n';
    }

    void A7(double VAR){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 3:7 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "ceil(" << VAR << ") = " << std::ceil( VAR) << '\n' << '\n'; }

}

namespace A_4{
    void A1(void);
    void A2(void);
    void A3(void);
    void A4(void);
    void A5(void);

    void A1(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 4:1 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << std::showpos << 255 << "\t";
        std::cout << std::hex << std::uppercase << 255 << "\t";
        std::cout << std::hex << std::nouppercase << 255 << "\t";
        std::cout << std::dec << std::noshowpos << 255 << '\n' << '\n';
    }

    void A2(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 4:2 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << std::showpoint << 1.23f << "\t";
        std::cout << std::noshowpoint << 1.23f << "\t";
        std::cout << std::fixed << 1.23f << '\n' << '\n';
    }

    void A3(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 4:3 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << std::setprecision( 2) << 9.876f << "\t";
        std::cout << std::setprecision( 5) << 9.876f << "\t";
        std::cout << std::setprecision( 0) << 9.876f << '\n' << '\n';
    }

    void A4(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 4:4 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << "Geben Sie eine Gleitpunktzahl (GPZ) ein: ";
        double GPZ(0.0);
        std::cin.clear();
        std::cin >> GPZ;
        while( std::cin.fail()){
            std::cin.clear();
            std::cin.get();
            std::cout << "! Fehleingabe !\n";
            std::cout << "Geben Sie eine Gleitpunktzahl (GPZ) ein: ";
            std::cin >> GPZ;
        }
        std::cin.clear();
        std::cout << "Ihre GPZ: " << std::fixed << GPZ << '\n';
        std::cout << std::setprecision(2) << GPZ << "        ";
        std::cout << std::scientific << GPZ << '\n' << '\n';
    }

    void A5(void){
        DBLCRS::DBLCRS(17);
        std::cout << "## Aufgabe 4:5 ##\n";
        DBLCRS::DBLCRS(17);
        std::cout << std::left << std::setw(15) << "Dezimal" << std::setw(15) << "Oktal" << std::setw(15) << "Hexadezimal" << '\n';
        std::cout << std::left << std::setw(15) << std::dec << UINT_MAX << std::setw(15) << std::oct << UINT_MAX << std::setw(15) << std::uppercase << std::hex << UINT_MAX << '\n';
        std::cout << std::left << std::setw(15) << std::dec << -1 << std::setw(15) << std::oct << -1 << std::setw(15) << std::uppercase << std::hex << -1 << '\n' << '\n';
    }

}


int main(int argc, char *argv[]){
    if( argc == 1){ A_4::A5();}
    else{
        for( unsigned short int i = 1; i < argc; ++i){
            if(  !std::strcmp( argv[i], "1.4") ){ A_1::A4(); continue;}
            else{
                if( !std::strcmp( argv[i], "1.6")){ A_1::A6(); continue;}
                else{
                    if( !std::strcmp( argv[i], "2.2")){ A_2::A2(); continue;}
                    else{
                        if( !std::strcmp( argv[i], "2.3")){ A_2::A3(); continue;}
                        else{
                            if( !std::strcmp( argv[i], "2.8")){ A_2::A8(); continue;}
                            else{
                                if( !std::strcmp( argv[i], "3.4")){ A_3::A4(); continue;}
                                else{
                                    if( !std::strcmp( argv[i], "3.6")){ A_3::A6(); continue;}
                                    else{
                                        if( !std::strcmp( argv[i], "3.7")){ A_3::A7(1.42); A_3::A7(-1.65); A_3::A7(-1.42); A_3::A7(1.65); continue;}
                                        else{
                                            if( !std::strcmp( argv[i], "4.1")){ A_4::A1(); continue;}
                                            else{
                                                if( !std::strcmp( argv[i], "4.2")){ A_4::A2(); continue;}
                                                else{
                                                    if( !std::strcmp( argv[i], "4.3")){ A_4::A3(); continue;}
                                                    else{
                                                        if( !std::strcmp( argv[i], "4.4")){ A_4::A4(); continue;}
                                                        else{
                                                            if( !std::strcmp( argv[i], "4.5")){ A_4::A5(); continue;}
                                                            else{ std::cout << "falsche Aufgabe: " << argv[i] << '\n'; continue;}
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
