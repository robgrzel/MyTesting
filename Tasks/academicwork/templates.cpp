//
// Created by robgrzel on 01.06.17.
//

#include "templates.h"


size_t file_lines_count( const char* pathFile ) {
    size_t        n = 0;
    std::string   line;
    std::ifstream myfile( pathFile );

    while ( std::getline( myfile, line ) ) ++n;

    return n;
}

size_t file_line_count( const char* pathFile, const char delim) {

    size_t            n = 0;
    std::string       line;
    std::stringstream stream;
    std::ifstream     myfile( pathFile );

    if (std::getline( myfile, line )) {
        stream.str( line );
        std::string item;
        while ( std::getline( stream, item, delim ) ) {
            if (!item.empty()) ++n;
        }
    }

    return n;
}