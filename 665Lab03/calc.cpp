#include "calc.hpp"
#include <cassert>

void EECS::Manager::parse( const char * filepath){
    std::ifstream in_stream( filepath);
    
    // this->scanner = new EECS::Scanner(&in_stream);
    // this->parser = new EECS::Parser(*scanner, *this);

    std::cout << "gettin' ready to parse!!!211!\n";
    parser->parse();
    return;

}

int main(const int argc, const char *argv[] ){
    assert(argc > 1);

    EECS::Manager manager( argv[1]);
    manager.parse( argv[1]);
}