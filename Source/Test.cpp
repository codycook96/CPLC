#include <iostream>
#include <string>
#include <vector>

#include "Parser.h"
#include "Engine.h"
#include "Block.h"
#include "Rung.h"
#include "Ladder.h"

int main(){

    bool rungIn = false;
    bool contact1 = false;
    bool contact2 = false;
    bool coil = false;

    //NOC* noc = new NOC(&contact1, &rungIn);

    /*
    NOC noc1(&rungIn, &contact1);
    NCC ncc1(noc1.wire(), &contact2);
    SET out1(ncc1.wire(), &coil);

    rungIn = true;
    std::cout << "--" << rungIn << "--[" << contact1 << "]--" << *noc1.wire() << "--[" << contact2 << "]--" << *ncc1.wire() << "--(" << coil << ")" << std::endl;
    contact1 = true; noc1.exec(); ncc1.exec(); out1.exec();
    std::cout << "--" << rungIn << "--[" << contact1 << "]--" << *noc1.wire() << "--[" << contact2 << "]--" << *ncc1.wire() << "--(" << coil << ")" << std::endl;
    contact1 = false; contact2 = true; noc1.exec(); ncc1.exec(); out1.exec();
    std::cout << "--" << rungIn << "--[" << contact1 << "]--" << *noc1.wire() << "--[" << contact2 << "]--" << *ncc1.wire() << "--(" << coil << ")" << std::endl;
    contact1 = true; noc1.exec(); ncc1.exec(); out1.exec();
    std::cout << "--" << rungIn << "--[" << contact1 << "]--" << *noc1.wire() << "--[" << contact2 << "]--" << *ncc1.wire() << "--(" << coil << ")" << std::endl;
    */

    //Rung r1;
    Ladder lad1;
    lad1.addDigitalTag("Howdy");
    lad1.addDigitalTag("Hello");
    lad1.addDigitalTag("Howdy");
    std::cout << lad1.getDigitalTag("Howdy") << std::endl;
    lad1.setDigitalTag("Howdy", true);
    std::cout << lad1.getDigitalTag("Howdy") << std::endl;


    return 0;
}