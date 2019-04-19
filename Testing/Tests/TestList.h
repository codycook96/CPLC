#ifndef TESTLIST_H
#define TESTLIST_H

#include "TestBench.h"

#include "Database.h"
#include "Types.h"
#include "Datum.h"

namespace Testing {

        void TypeEquality(TestBench& tb);
        void TypeComparison(TestBench& tb);
        //void TypeCasting(TestBench& tb);
        void TypeIDAccept(TestBench& tb);
        //void TypeSetGet(TestBench& tb);



}

#endif