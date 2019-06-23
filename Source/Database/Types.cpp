#include "Types.h"

std::vector<std::pair<std::string, TYPE_ID>> TYPE_LABELS = {
    {"TYPE_ANY", TYPE_ANY},
    {"TYPE_ANY_DERIVED", TYPE_ANY_DERIVED},
    {"TYPE_ANY_ELEMENTARY", TYPE_ANY_ELEMENTARY},
    {"TYPE_ANY_MAGNITUDE", TYPE_ANY_MAGNITUDE},
    {"TYPE_ANY_NUM", TYPE_ANY_NUM},
    {"TYPE_ANY_INT", TYPE_ANY_INT},
    {"TYPE_SINT", TYPE_SINT},
    {"TYPE_INT", TYPE_INT},
    {"TYPE_DINT", TYPE_DINT},
    {"TYPE_LINT", TYPE_LINT},
    {"TYPE_USINT", TYPE_USINT},
    {"TYPE_UINT", TYPE_UINT},
    {"TYPE_UDINT", TYPE_UDINT},
    {"TYPE_ULINT", TYPE_ULINT},
    {"TYPE_ANY_REAL", TYPE_ANY_REAL},
    {"TYPE_REAL", TYPE_REAL},
    {"TYPE_LREAL", TYPE_LREAL},
    {"TYPE_TIME", TYPE_TIME},
    {"TYPE_ANY_BIT", TYPE_ANY_BIT},
    {"TYPE_BOOL", TYPE_BOOL},
    {"TYPE_BYTE", TYPE_BYTE},
    {"TYPE_WORD", TYPE_WORD},
    {"TYPE_DWORD", TYPE_DWORD},
    {"TYPE_LWORD", TYPE_LWORD},
    {"TYPE_ANY_STRING", TYPE_ANY_STRING},
    {"TYPE_STRING", TYPE_STRING},
    {"TYPE_WSTRING", TYPE_WSTRING},
    {"TYPE_ANY_DATE", TYPE_ANY_DATE},
    {"TYPE_DATE", TYPE_DATE},
    {"TYPE_DATE_AND_TIME", TYPE_DATE_AND_TIME},
    {"TYPE_TIME_OF_DAY", TYPE_TIME_OF_DAY}
};

TYPE::TYPE(): id(TYPE_ANY){}

TYPE::TYPE(TYPE_ID _id): id(_id){}

TYPE::TYPE(std::string label): id(Label2ID(label)){}

TYPE::TYPE(const TYPE& t): id(t.id){}

bool TYPE::accepts(const TYPE& other){
    return (other.id % id) == 0; 
}

bool TYPE::equals(const TYPE& other){
    return id == other.id; 
}

TYPE_ID TYPE::getID(){
    return id;
}

std::string TYPE::getLabel(){
    return ID2Label(id);
}

std::string TYPE::ID2Label(TYPE_ID id){
    for(unsigned int i = 0; i < TYPE_LABELS.size(); i++){
        if(id == TYPE_LABELS.at(i).second){
            return TYPE_LABELS.at(i).first;
        }
    }   
    return "";
}

TYPE_ID TYPE::Label2ID(std::string label){
    for(unsigned int i = 0; i < TYPE_LABELS.size(); i++){
        if(label == TYPE_LABELS.at(i).first){
            return TYPE_LABELS.at(i).second;
        }
    } 
    return TYPE_ANY;
}


ANY::~ANY(){}
ANY::ANY(const ANY& other): value(other.value){}
ANY& ANY::operator=(const ANY& other){
    value = other.value;
    return *this;
}

ANY_DERIVED::~ANY_DERIVED(){}

ANY_ELEMENTARY::~ANY_ELEMENTARY(){}

ANY_MAGNITUDE::~ANY_MAGNITUDE(){}

ANY_NUM::~ANY_NUM(){}

ANY_INT::~ANY_INT(){}

ANY_REAL::~ANY_REAL(){}

ANY_STRING::~ANY_STRING(){}

ANY_DATE::~ANY_DATE(){}

ANY_BIT::~ANY_BIT(){}

SINT::SINT(): ANY_INT((signed char) 0){}
SINT::SINT(signed char v): ANY_INT(v){}
signed char SINT::get(){ return value.get<signed char>(); }
void SINT::set(signed char v){ value.set(v); }

INT::INT(): ANY_INT((short int) 0){}
INT::INT(short int v): ANY_INT(v){}

DINT::DINT(): ANY_INT((int) 0){}
DINT::DINT(int v): ANY_INT(v){}

LINT::LINT(): ANY_INT((long long int) 0){}
LINT::LINT(long long int v): ANY_INT(v){}

USINT::USINT(): ANY_INT((unsigned char) 0){}
USINT::USINT(unsigned char v): ANY_INT(v){}

UINT::UINT(): ANY_INT((unsigned short int) 0){}
UINT::UINT(unsigned short int v): ANY_INT(v){}

UDINT::UDINT(): ANY_INT((unsigned int) 0){}
UDINT::UDINT(unsigned int v): ANY_INT(v){}

ULINT::ULINT(): ANY_INT((unsigned long long int) 0){}
ULINT::ULINT(unsigned long long int v): ANY_INT(v){}

REAL::REAL(): ANY_REAL((float) 0.0){}
REAL::REAL(float v): ANY_REAL(v){}
//float REAL::get(){ return 0.0; /*return value.get<float>();*/ }

LREAL::LREAL(): ANY_REAL((double) 0.0){}
LREAL::LREAL(double v): ANY_REAL(v){}
double LREAL::get(){ return value.get<double>(); }
void LREAL::set(double v){ value.set(v); }

BOOL::BOOL(): ANY_BIT((bool) false){}
BOOL::BOOL(bool v): ANY_BIT(v){}

BYTE::BYTE(): ANY_BIT((unsigned char) 0){}
BYTE::BYTE(unsigned char v): ANY_BIT(v){}

WORD::WORD(): ANY_BIT((unsigned short int) 0){}
WORD::WORD(unsigned short int v): ANY_BIT(v){}

DWORD::DWORD(): ANY_BIT((unsigned int) 0){}
DWORD::DWORD(unsigned int v): ANY_BIT(v){}

LWORD::LWORD(): ANY_BIT((unsigned long long int) 0){}
LWORD::LWORD(unsigned long long int v): ANY_BIT(v){}



/*
TYPE::~TYPE(){}

template <typename T>
ANY<T>::~ANY<T>(){}

template <typename T>
ANY_DERIVED<T>::~ANY_DERIVED<T>(){}

template <typename T>
ANY_ELEMENTARY<T>::~ANY_ELEMENTARY<T>(){}

template <typename T>
ANY_MAGNITUDE<T>::~ANY_MAGNITUDE<T>(){}

template <typename T>
ANY_NUM<T>::~ANY_NUM<T>(){}

template <typename T>
ANY_INT<T>::~ANY_INT<T>(){}

template <typename T>
ANY_REAL<T>::~ANY_REAL<T>(){}

SINT::SINT(): ANY_INT<signed char>(){
}

INT::INT(): ANY_INT<short>() {
    type_id = TYPE_INT;
}
*/

/*
GenericType::GenericType(GenericType* p, std::string l): parent(p), label(l) {}

GenericType::GenericType(std::string l): label(l) {
        parent = nullptr;
}

GenericType::GenericType(const GenericType& gt): parent(gt.parent), label(gt.label) {}



bool GenericType::operator==(const GenericType& rhs) const {
    return this == &rhs;
}


bool GenericType::operator>=(const GenericType& rhs) const {
    if (this == &rhs){
        return true;
    }
    GenericType* pi = (GenericType*) &rhs;
    //std::cout << "pi: " << pi << ", this: " << this << std::endl;
    while(pi != nullptr){
        if(this == pi){
            return true;
        }
        pi = pi->parent;
        //std::cout << "pi: " << pi << ", this: " << this << std::endl;
    }

    return false;
}

bool GenericType::operator<=(const GenericType& rhs) const {
    if (this == &rhs){
        return true;
    }
    GenericType* pi = (GenericType*) this;
    //std::cout << "pi: " << pi << ", other: " << other << std::endl;
    while(pi != nullptr){
        if(&rhs == pi){
            return true;
        }
        pi = pi->parent;
        //std::cout << "pi: " << pi << ", other: " << other << std::endl;
    }

    return false;
}


bool GenericType::operator>(const GenericType& rhs) const {
    if(this == &rhs)
        return false;
    
    return *this >= rhs;
}

bool GenericType::operator<(const GenericType& rhs) const {
    if(this == &rhs)
        return false;

    return *this <= rhs;
}

TypeList::TypeList(){
    initialize();
}






void TypeList::initialize(){
    //Initialize Generic Types
    GenericType* ANY = new GenericType("ANY");
    GenericType* ANY_DERIVED = new GenericType(ANY, "ANY_DERIVED");
    GenericType* ANY_ELEMENTARY = new GenericType(ANY, "ANY_ELEMENTARY");
    GenericType* ANY_MAGNITUDE = new GenericType(ANY_ELEMENTARY, "ANY_MAGNITUDE");
    GenericType* ANY_NUM = new GenericType(ANY_MAGNITUDE, "ANY_NUM");
    GenericType* ANY_INT = new GenericType(ANY_NUM, "ANY_INT");
    GenericType* ANY_REAL = new GenericType(ANY_NUM, "ANY_REAL");
    GenericType* ANY_BIT = new GenericType(ANY_ELEMENTARY, "ANY_BIT");
    GenericType* ANY_STRING = new GenericType(ANY_ELEMENTARY, "ANY_STRING");
    GenericType* ANY_DATE = new GenericType(ANY_ELEMENTARY, "ANY_DATE");

    //Initialize Types
    //Type<>* = new Type<>(, "", std::numeric_limits<>().min(), std::numeric_limits<>().max(), 0);
    Type<short>* SINT = new Type<short>(ANY_INT, "SINT", std::numeric_limits<signed char>().min(), std::numeric_limits<signed char>().max(), 0);
    Type<short>* INT = new Type<short>(ANY_INT, "INT", std::numeric_limits<short>().min(), std::numeric_limits<short>().max(), 0);
    Type<int>* DINT = new Type<int>(ANY_INT, "DINT", std::numeric_limits<int>().min(), std::numeric_limits<int>().max(), 0);
    Type<long long>* LINT = new Type<long long>(ANY_INT, "LINT", std::numeric_limits<long long>().min(), std::numeric_limits<long long>().max(), 0);
    Type<unsigned short>* USINT = new Type<unsigned short>(ANY_INT, "USINT", std::numeric_limits<unsigned char>().min(), std::numeric_limits<unsigned char>().max(), 0);
    Type<unsigned short>* UINT = new Type<unsigned short>(ANY_INT, "UINT", std::numeric_limits<unsigned short>().min(), std::numeric_limits<unsigned short>().max(), 0);
    Type<unsigned int>* UDINT = new Type<unsigned int>(ANY_INT, "UDINT", std::numeric_limits<unsigned int>().min(), std::numeric_limits<unsigned int>().max(), 0);
    Type<unsigned long long>* ULINT = new Type<unsigned long long>(ANY_INT, "ULINT", std::numeric_limits<unsigned long long>().min(), std::numeric_limits<unsigned long long>().max(), 0);
    Type<float>* REAL = new Type<float>(ANY_REAL, "REAL", std::numeric_limits<float>().min(), std::numeric_limits<float>().max(), 0.0);
    Type<double>* LREAL = new Type<double>(ANY_REAL, "LREAL", std::numeric_limits<double>().min(), std::numeric_limits<double>().max(), 0.0);
    
    //Add Generic Types
    addType(ANY);
    addType(ANY);
    addType(ANY_DERIVED);
    addType(ANY_ELEMENTARY);
    addType(ANY_MAGNITUDE);
    addType(ANY_NUM);
    addType(ANY_INT);
    addType(ANY_REAL);
    addType(ANY_BIT);
    addType(ANY_STRING);
    addType(ANY_DATE);
    
    //Add Types
    addType((GenericType*) (SINT));
    addType((GenericType*) (INT));
    addType((GenericType*) (DINT));
    addType((GenericType*) (LINT));
    addType((GenericType*) (USINT));
    addType((GenericType*) (UINT));
    addType((GenericType*) (UDINT));
    addType((GenericType*) (ULINT));
    addType((GenericType*) (REAL));
    addType((GenericType*) (LREAL));
}

bool TypeList::addType(GenericType* gt){
    if(types.count(gt->label) == 0){
        types.insert(std::pair<std::string, GenericType*>(gt->label, gt));
        return true;
    }
    return false;
}







void TypeList::derive(DerivedType dt){
    return;
}

bool TypeList::accepts(int IDA, int IDB){
    if(IDA == 1){
        return true;
    }
    else if(IDA == 3){
        return IDB % 2 == 1 && IDB != 1;
    }
    else{
        return IDB % IDA == 0; 
    }
    return false;
}

bool TypeList::accepts(std::string labelA, std::string labelB){
    int a = types[labelA];
    int b = types[labelB];

    if(a == 1){
        return true;
    }
    else if(a == 3){
        return b % 2 == 1 && b != 1;
    }
    else{
        return b % a == 0; 
    }
    return false;
}

bool TypeList::equal(int IDA, int IDB){
    return IDA == IDB;
}

bool TypeList::equal(std::string labelA, std::string labelB){
    int a = types[labelA];
    int b = types[labelB];

    return a == b;
}

void TypeList::addTypes(){
    types.insert(std::pair<std::string,int>("ANY", ANY));
    types.insert(std::pair<std::string,int>("ANY_DERIVED", ANY_DERIVED));
    types.insert(std::pair<std::string,int>("ANY_ELEMENTARY", ANY_ELEMENTARY));
    types.insert(std::pair<std::string,int>("ANY_MAGNITUDE", ANY_MAGNITUDE));
    types.insert(std::pair<std::string,int>("ANY_NUM", ANY_NUM));
    types.insert(std::pair<std::string,int>("ANY_INT", ANY_INT));
    types.insert(std::pair<std::string,int>("SHORT_INT", SHORT_INT));
    types.insert(std::pair<std::string,int>("INT", INT));
    types.insert(std::pair<std::string,int>("DINT", DINT));
    types.insert(std::pair<std::string,int>("LINT", LINT));
    types.insert(std::pair<std::string,int>("USINT", USINT));
    types.insert(std::pair<std::string,int>("UINT", UINT));
    types.insert(std::pair<std::string,int>("UDINT", UDINT));
    types.insert(std::pair<std::string,int>("ULINT", ULINT));
    types.insert(std::pair<std::string,int>("ANY_REAL", ANY_REAL));
    types.insert(std::pair<std::string,int>("REAL", REAL));
    types.insert(std::pair<std::string,int>("LREAL", LREAL));
    types.insert(std::pair<std::string,int>("TIME", TIME));
    types.insert(std::pair<std::string,int>("ANY_BIT", ANY_BIT));
    types.insert(std::pair<std::string,int>("BOOL", BOOL));
    types.insert(std::pair<std::string,int>("BYTE", BYTE));
    types.insert(std::pair<std::string,int>("WORD", WORD));
    types.insert(std::pair<std::string,int>("DWORD", DWORD));
    types.insert(std::pair<std::string,int>("LWORD", LWORD));
    types.insert(std::pair<std::string,int>("ANY_STRING", ANY_STRING));
    types.insert(std::pair<std::string,int>("STRING", STRING));
    types.insert(std::pair<std::string,int>("WSTRING", WSTRING));
    types.insert(std::pair<std::string,int>("ANY_DATE", ANY_DATE));
    types.insert(std::pair<std::string,int>("DATE", DATE));
    types.insert(std::pair<std::string,int>("DATE_AND_TIME", DATE_AND_TIME));
    types.insert(std::pair<std::string,int>("TIME_OF_DAY", TIME_OF_DAY));
}
*/