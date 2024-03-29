#ifndef POLYGONINPUTPARSER_H
#define POLYGONINPUTPARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "src/objects/Point2D.h"

class PolygonInputParser {
public:
    static std::vector <Point2D> parseFile (std::string fileName) {
        std::vector <Point2D> output;

        std::ifstream inp (fileName.c_str());
        if (inp.fail()) {
            std::cerr << "can't open input file: " << fileName << std::endl;
            return output;
        }

        int x, y;
        while (inp >> x >> y) {
            output.push_back(Point2D (x, y));
        }

        return output;
    }
};

#endif // POLYGONINPUTPARSER_H
