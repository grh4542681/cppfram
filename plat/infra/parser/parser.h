#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "file.h"

#include "parser_return.h"

namespace parser {

class Parser {
public:
    Parser() { };
    virtual ~Parser() { };

    virtual ParserRet LoadString(std::string str) { return ParserRet::ESUBCLASS; }
    virtual ParserRet LoadFile(file::File& file) { return ParserRet::ESUBCLASS; }
    virtual ParserRet LoadFile(std::string str) { return ParserRet::ESUBCLASS; }

    virtual ParserRet StoreString(std::string& str) { return ParserRet::ESUBCLASS; }
    virtual ParserRet StoreFile(file::File& file) { return ParserRet::ESUBCLASS; }
    virtual ParserRet StoreFile(std::string str) { return ParserRet::ESUBCLASS; }
};

}

#endif
