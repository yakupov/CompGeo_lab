#ifndef POLYGONINPUTPARSER_H
#define POLYGONINPUTPARSER_H

#include <vector>
#include <string>
#include <fstream>
#include "src/objects/Point2D.h"

class PolygonInputParser {
public:
    static std::vector <Point2D> parseFile (std::string fileName) {
        std::vector <Point2D> output;

        std::ifstream inp (fileName.c_str());

        while (inp.peek() != EOF) {
            int x, y;
            inp >> x >> y;

            output.push_back(Point2D (x, y));
        }

        output.pop_back();
        return output;
    }
};

#endif // POLYGONINPUTPARSER_H
