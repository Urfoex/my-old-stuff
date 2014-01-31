#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>


class Memory{
public:
    Memory();
    void Check();
    void addMem( Memory *p);
    void delMem();
    double getSize(){return SIZE;};
    bool getCheck(){ return CHECK;};
private:
    bool check();
    Memory *next;
    Memory *previous;
    /*double Ram1;
    double Ram2;*/
    char Ram1;
    char Ram2;
    static bool CHECK;
    static double SIZE;
};

Memory *MemMaster = NULL;

double Memory::SIZE = 0;
bool Memory::CHECK = false;


Memory::Memory(){
    char temp( rand());
    Ram1 = temp;
    Ram2 = temp;
    next = NULL;
    previous = NULL;
    SIZE += sizeof( Memory);
}

void Memory::addMem( Memory *p){
    if( MemMaster == NULL){
        MemMaster = p;
        return;
    }
    static Memory *runner = MemMaster;
#ifdef DEBUG2
    static double counter = 0;
#endif
    runner->next = p;
    p->previous = runner;
    runner = p;
#ifdef DEBUG2
    std::cout << ++counter << "\t";
#endif
}

void Memory::delMem(){
    if( !MemMaster) return;
    Memory *runner = MemMaster;
    while( MemMaster->next){
        while( runner->next->next){ runner = runner->next;}
        MemMaster->SIZE -= sizeof( Memory);
        delete runner->next;
        runner->next = NULL;
        runner = runner->previous;
#ifdef DEBUG
        std::cout << "delMem";
#endif
    }
    MemMaster->SIZE -= sizeof( Memory);
    MemMaster->next = NULL;
    MemMaster->previous = NULL;
    delete MemMaster;
    MemMaster = NULL;
    std::cout << "delMemMaster\n";
}

bool Memory::check(){
    if( Ram1 != Ram2){
         return false;
    }
    return true;
}

void Memory::Check(){
    static Memory *runner1 = MemMaster;
    static Memory *runner2 = MemMaster;
    static Memory *runner3 = MemMaster;
    runner1 = MemMaster;
    runner2 = MemMaster;
    runner3 = MemMaster;

    while( true){
        if( runner1->check()){
            if( runner1->previous){
                if( runner1->next){
                    runner2 = runner1->previous;
                    runner3 = runner1->next;
                    runner2->next = runner3;
                    runner3->previous = runner2;
                    MemMaster->SIZE -= sizeof( Memory);
                    delete runner1;
#ifdef DEBUG
                    std::cout << "delCheck";
#endif
                    runner1 = runner3;
                    runner2 = NULL;
                    runner3 = NULL;
                }else{
                    runner2 = runner1->previous;
                    runner2->next = NULL;
                    MemMaster->SIZE -= sizeof( Memory);
                    delete runner1;
#ifdef DEBUG
                    std::cout << "delCheck";
#endif
                    runner1 = runner2;
                    runner2 = NULL;
                    runner3 = NULL;
                }
            }else{
                if( runner1->next){
                    runner2 = runner1->next;
                    MemMaster = runner2;
                    runner2->previous = NULL;
                    MemMaster->SIZE -= sizeof( Memory);
                    delete runner1;
#ifdef DEBUG
                    std::cout << "delCheck";
#endif
                    runner1 = runner2;
                    runner2 = NULL;
                    runner3 = NULL;
                }else{
                    runner1 = NULL;
                    runner2 = NULL;
                    runner3 = NULL;
                    MemMaster->SIZE -= sizeof( Memory);
                    MemMaster->next = NULL;
                    MemMaster->previous = NULL;
                    delete MemMaster;
                    std::cout << "no memerr found \t delMemMaster\n";
                    MemMaster = NULL;
                    return;
                }
            }
        }else{
            if( runner1->next){
                 runner1 = runner1->next;
                 CHECK = true;
            }else return;
        }
    }
}

int main( int argc, char *argv[]){
    double MEMORY = 1;
    double ROUNDS = 1;
    std::cout << "( " << sizeof( Memory) << ") pls choose amount of ram (MB): ";
    std::cin >> MEMORY;
    if( std::cin.fail()){
        std::cout << "you'r not right!\n";
        return 0;
    }
    if( MEMORY <= 0) MEMORY = 1.0 / 1024.0 / 1024.0;
    std::cout << sizeof( char) << '\t' << sizeof( long) << '\t' << sizeof( int) << '\t' << sizeof( short) << '\t' << sizeof( bool) << '\t' << sizeof( double) << '\n';
    std::cout << "( " << sizeof( Memory) << ") pls choose rounds: ";
    std::cin >> ROUNDS;
    if( std::cin.fail()){
        std::cout << "you'r not right!\n";
        return 0;
    }
    if( ROUNDS < 1) ROUNDS = 1;

    MEMORY *= 1024*1024;
    srand( time( 0) );

    for( double i = 0; i < ROUNDS; ++i){
        std::cout << "\nRound : " << i+1 << " of " << ROUNDS << std::endl;
        while( MemMaster->getSize() < MEMORY ){
            try{
                Memory *p = new Memory;
                MemMaster->addMem( p);
            }
            catch( std::bad_alloc&){
                std::cout << "memory: full\n";
                break;
            }
        }
        std::cout << std::fixed << std::setprecision(0) << MemMaster->getSize() << '\t' << MEMORY << std::endl;
        MemMaster->Check();
        std::cout << std::fixed << std::setprecision(0) << MemMaster->getSize() << '\t' << MEMORY << std::endl;
        if( MemMaster->getCheck()) break;
    }

    std::string StOp("");
    while( StOp.compare("St0p")){
        std::cout << "waiting for 'StOp' : ";
        std::cin >> StOp;
        while( std::cin.fail()){
            std::cout << "you'r not right!\n";
            std::cin.clear();
            std::cin.get();
            std::cout << "waiting for 'StOp' : ";
            std::cin >> StOp;
        }
    }

    MemMaster->delMem();
    MemMaster = NULL;

    return 0;
}
