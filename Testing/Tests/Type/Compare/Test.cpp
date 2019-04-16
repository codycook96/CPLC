/*  Test Name:  Type Checking Test
 *  
 *  Purpose:    Verify the type checking functionality: ensuring that
 *              types are properly created, strings return their proper 
 *              type ID's, and types are properly compared 
 *              
 *  Results:    See Results.txt for test results   
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <any>
#include <unordered_map> 
#include <functional>

#include "Type.h"
#include "Database.h"

const char* types_c[] = { 
"ANY", "ANY_DERIVED", "ANY_ELEMENTARY", "ANY_MAGNITUDE", "ANY_NUM", "ANY_INT", 
"SHORT_INT", "INT", "DINT", "LINT", "USINT", "UINT", "UDINT", "ULINT", 
"ANY_REAL", "REAL", "LREAL", "TIME", "ANY_BIT", "BOOL", "BYTE", "WORD", "DWORD",
"LWORD", "ANY_STRING", "STRING", "WSTRING", "ANY_DATE", "DATE", "DATE_AND_TIME",
"TIME_OF_DAY"
};

//std::vector<std::string> types_s(types_c, std::end(types_c));

struct DUMMY_ADDER{
    DUMMY_ADDER(ANY_INT* o, std::vector<ANY_INT*> i): out(o), in(i){}
    ANY_INT* out;
    std::vector<ANY_INT*> in;
    void exec(){
        unsigned long long int result = 0;
        for(unsigned int i = 0; i < in.size(); i++){
            result += in.at(i)->value.get<unsigned long long int>();
        }
        out->value.set<unsigned long long int>(result);
    }
};

/*
ANY_INT* dummy_add(ANY_INT* a, ANY_INT* b){
    unsigned long long int result = a->value.get<unsigned long long int>() + b->value.get<unsigned long long int>();
    a->value.set<unsigned long long int>(result);
    return a;
}
*/

/*
void dummy_add(ANY_INT* a, ANY_INT* b){
    //std::cout << tA.type().name() << std::endl;
    //std::cout << typeid(SINT*).name() << std::endl;

    std::cout << a->value.cast<unsigned long long int>() << std::endl;
    std::cout << b->value.cast<unsigned long long int>() << std::endl;

    //temp.value = a->value + b->value;

    //if(temp.value < a->value || temp.value < b->value){
    //    throw(std::string("[Error] Function-Addition: addition overflow"));
    //}
    //a->value = temp.value;
}

void caller(std::function<void()>, std::any a, std::any b){

}


template <typename T>
T cast(const std::any& A){
    return std::any_cast<SINT*>(A);
}
*/

int main(){
    
    Database db;

    db.add(TYPE_SINT, "v1");
    db.add(TYPE_SINT, "v2");
    db.add(TYPE_SINT, "v3");
    db.add(TYPE_SncINT, "v4");
    
    SINT* v1 = db.link<SINT*>("v1");
    SINT* v2 = db.link<SINT*>("v2");
    SINT* v3 = db.link<SINT*>("v3");
    SINT* v4 = db.link<SINT*>("v4");
    v1->value.set<signed char>((signed char) 5);
    v2->value.set<signed char>((signed char) 10);
    v3->value.set<signed char>((signed char) 15);
    v4->value.set<signed char>((signed char) 20);
    std::cout << "v1: " << (int) v1->value.get<signed char>() << std::endl;
    std::cout << "v2: " << (int) v2->value.get<signed char>() << std::endl;
    std::cout << "v3: " << (int) v3->value.get<signed char>() << std::endl;
    std::cout << "v4: " << (int) v4->value.get<signed char>() << std::endl;
    
    ANY_INT* out; 
    out = db.link<ANY_INT*>("v1");

    std::vector<ANY_INT*> in;
    in.push_back(db.link<ANY_INT*>("v1"));
    in.push_back(db.link<ANY_INT*>("v2"));
    in.push_back(db.link<ANY_INT*>("v3"));
    in.push_back(db.link<ANY_INT*>("v4"));

   

    DUMMY_ADDER ADD(out, in);
    
    std::cout << "pre: v1: " << (int) v1->value.get<signed char>() << std::endl;
    ADD.exec();
    std::cout << "add1: v1: " << (int) v1->value.get<signed char>() << std::endl;
    ADD.exec();
    std::cout << "add2: v1: " << (int) v1->value.get<signed char>() << std::endl;
    ADD.exec();
    std::cout << "add3: v1: " << (int) v1->value.get<signed char>() << std::endl;
    ADD.exec();
    std::cout << "add4: v1: " << (int) v1->value.get<signed char>() << std::endl;
    ADD.exec();
    std::cout << "add5: v1: " << (int) v1->value.get<signed char>() << std::endl;
    

    //typedef std::variant<SINT*, INT*> TYPE;
    //std::variant<SINT*, INT*> TYPE;
    //static_assert(std::variant_size_v<decltype(TYPE)> == 2);
    
    //std::unordered_map<std::string, std::any> types;
     
    //std::unordered_map<std::string, std::any> types;

    //SINT* howdy = new SINT(5);
    //SINT* howdy1 = new SINT(100);
    //BOOL* bool1 = new BOOL(true);
    //DATA mysint((signed char) 1);
    //DATA myint((short) 500);
    //DATA mydint((int) 40000);
    //DATA mylint((long long) 3000000000);

    //std::cout << (int) mysint.out<signed char>() << std::endl;
    //std::cout << myint.out<short>() << std::endl;
    //std::cout << mydint.out<int>() << std::endl;
    //std::cout << mylint.out<long long>() << std::endl;

    //types.insert(std::pair<std::string, std::any>("howdy", howdy));
    //types.insert(std::pair<std::string, std::any>("howdy1", howdy1));
    //types.insert(std::pair<std::string, std::any>("bool1", bool1));

    //howdy->value = 100;
    //howdy1->value = 12;

    //std::cout << std::is_base_of<types["howdy"].type(), types["howdy1"].type()>::value << std::endl;

    //std::cout << (int) std::any_cast<ANY_INT*>(types["howdy"])->value.cast<signed char>() << std::endl;
    //std::cout << (int) std::any_cast<SINT*>(types["howdy"])->value << std::endl;
    //dummy_add(dynamic_cast<ANY_INT*>(types["howdy"]),dynamic_cast<ANY_INT*>(types["bool1"]));
    //std::cout << (int) std::any_cast<SINT*>(types["howdy"])->value << std::endl;
    
    //delete howdy1;
    //delete howdy;
    
    //int y = 2;

    //DATA d;
    //d.add("howdy",howdy);
    //SINT* s = d.get<SINT*>("howdy");
    //ANY_INT<signed char>* s2 = d.get<ANY_INT<signed char>*>("howdy");
    //std::cout << (int) types.at(0)->value << std::endl;
    //s2->value += 105;
    //std::cout << (int) types.at(1)->value << std::endl;
    //std::cout << (int) s2->lowerBound() << std::endl;

    //std::cout << std::get<SINT*>(types[0])->value << std::endl;
    //cast<SINT>(types.at(0), types.at(0).type());
    
    //std::cout << std::any_cast<types.at(0).type()>(types.at(0))->value << std::endl;

    //std::cout << ((int) SINT::upperBound) << " " << ((int) SINTs::lowerBound) << std::endl;

    /*
    try{
        //dummy_add(howdy, howdy1);
    }
    catch(std::string s){
        std::cout << s << std::endl;
    }
    catch(...){
        std::cout << "Exception occured" << std::endl;
    }
    */
    //std::cout << ((int) howdy->value) << std::endl;

    //std::cout << typeid(howdy).name() << std::endl;
    //std::cout << typeid(*howdy).name() << std::endl;

    //std::cout << "up: " << (int) howdy->upperBound() << ", low: " << (int) howdy->lowerBound() << std::endl; 
    //std::cout << "up: " << (int) howdy1->upperBound() << ", low: " << (int) howdy1->lowerBound() << std::endl; 

    //gig->isType(&howdy)

    //std::cout << "ANY_NUM: " << (dynamic_cast<ANY_INT*>(howdy) != nullptr) << std::endl;
    //std::cout << "ANY_INT: " << (dynamic_cast<ANY_INT*>(howdy) != nullptr) << std::endl;
    //std::cout << "SINT: " << (dynamic_cast<ANY_INT*>(howdy) != nullptr) << std::endl;
    //std::cout << "ANY_REAL: " << (dynamic_cast<ANY_REAL*>(howdy) != nullptr) << std::endl;
    //std::cout << type_id<SINT>() << " " << type_id<ANY_NUM>() << " " << std::endl;
    //std::cout << "ANY: " << any1->accepts(howdy) << std::endl;
    //std::cout << "REAL: " << real1->accepts(howdy) << std::endl;
    //std::cout << "howdyANY: " << howdy->accepts(any1) << std::endl;
    //std::cout << "howdyREAL: " << howdy->accepts(real1) << std::endl;


    //TypeList types;

    //std::cout << types["ANY_INT"]->parent->label << std::endl;
    
    //std::cout << types["REAL"]<float>->label << std::endl;
    //std::cout << types.type<float>("REAL")->lowerBound << std::endl;
    //std::cout << types.type<float>("REAL")->upperBound << std::endl;

    /*
    GenericType* tamu = new GenericType("tamu");
    GenericType college(*tamu);
    Type<int>* aggies = new Type<int>(tamu, "aggies", 0, 100, 0);
    Type<int>* howdy = new Type<int>(aggies, "howdy", 0, 10, 0);
    Type<double>* yall = new Type<double>(howdy, "yall", 0.0, 100.0, 0.0);
    
    std::cout << "aggies == aggies: " << (*aggies == *aggies) << std::endl;
    std::cout << "aggies >= aggies: " << (*aggies >= *aggies) << std::endl;
    std::cout << "aggies <= aggies: " << (*aggies <= *aggies) << std::endl;
    std::cout << "aggies > aggies: " << (*aggies > *aggies) << std::endl;
    std::cout << "aggies < aggies: " << (*aggies < *aggies) << std::endl;

    std::cout << "aggies == tamu: " << (*aggies == *tamu) << std::endl;
    std::cout << "aggies >= tamu: " << (*aggies >= *tamu) << std::endl;
    std::cout << "aggies <= tamu: " << (*aggies <= *tamu) << std::endl;
    std::cout << "aggies > tamu: " << (*aggies > *tamu) << std::endl;
    std::cout << "aggies < tamu: " << (*aggies < *tamu) << std::endl;

    std::cout << "aggies == howdy: " << (*aggies == *howdy) << std::endl;
    std::cout << "aggies >= howdy: " << (*aggies >= *howdy) << std::endl;
    std::cout << "aggies <= howdy: " << (*aggies <= *howdy) << std::endl;
    std::cout << "aggies > howdy: " << (*aggies > *howdy) << std::endl;
    std::cout << "aggies < howdy: " << (*aggies < *howdy) << std::endl;

    std::cout << "aggies == yall: " << (*aggies == *yall) << std::endl;
    std::cout << "aggies >= yall: " << (*aggies >= *yall) << std::endl;
    std::cout << "aggies <= yall: " << (*aggies <= *yall) << std::endl;
    std::cout << "aggies > yall: " << (*aggies > *yall) << std::endl;
    std::cout << "aggies < yall: " << (*aggies < *yall) << std::endl;

    
    std::cout << "Label: " << howdy.label << ", Index: " << howdy.index << ", Size: " << howdy.size;
    std::cout << ", UpperBound: " << howdy.upperBound << ", LowerBound: " << howdy.lowerBound;
    std::cout << ", Initial Value: " << howdy.initialValue << std::endl;
    */
    //TypeList types;
    /*
    //std::ofstream file;
    //file.open("Test_TypeChecking_Results.txt");
    int a, b;

    for(unsigned int i = 0; i < types_s.size(); i++){
        std::cout << types_s.at(i) << " accepts: " << std::endl;

        for(unsigned int j = 0; j < types_s.size(); j++){
            
            a = th.getID(types_s.at(i));
            b = th.getID(types_s.at(j));

            if(th.accepts(a, b)){
                std::cout << types_s.at(j) << ", ";
            }

        }

        std::cout << std::endl << std::endl;

    }
    */
}

