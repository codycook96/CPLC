#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>
#include <unordered_map> 
#include <iostream>
#include <typeinfo>
#include <limits>
#include <any>

#include "Data.h"

enum TYPE_ID{
    TYPE_ANY = 1,
        //x3
        TYPE_ANY_DERIVED = 3,
        //x2 
        TYPE_ANY_ELEMENTARY = 2,
            //x2
            TYPE_ANY_MAGNITUDE = 4,
                //x2
                TYPE_ANY_NUM = 8,
                    //x2
                    TYPE_ANY_INT = 16,
                        //x2
                        TYPE_SINT = 32,
                        //x19
                        TYPE_INT = 304,
                        //x23
                        TYPE_DINT = 368,
                        //x29
                        TYPE_LINT = 464,
                        //x31
                        TYPE_USINT = 496,
                        //x37
                        TYPE_UINT = 592,
                        //41
                        TYPE_UDINT = 656,
                        //43
                        TYPE_ULINT = 688,
                    //x17
                    TYPE_ANY_REAL = 136,
                        //x17
                        TYPE_REAL = 2312,
                        //x19
                        TYPE_LREAL = 2584,
                //x13
                TYPE_TIME = 52,
            //x5
            TYPE_ANY_BIT = 10,
                //x13
                TYPE_BOOL = 130,
                //x17
                TYPE_BYTE = 170,
                //x19
                TYPE_WORD = 190,
                //x23
                TYPE_DWORD = 230,
                //x29
                TYPE_LWORD = 290,
            //x7
            TYPE_ANY_STRING = 14,
                //x13
                TYPE_STRING = 182,
                //x17
                TYPE_WSTRING = 238,
            //x11
            TYPE_ANY_DATE = 22,
                //x13
                TYPE_DATE = 286,
                //x17
                TYPE_DATE_AND_TIME = 374,
                //x19
                TYPE_TIME_OF_DAY = 418,
};

class ANY{
    public:
        virtual ~ANY() = 0;

        template <typename T>
        ANY(T v): value(v){}

        ANY(const ANY& other);
        ANY& operator=(const ANY& other);

    protected:
        DATA value;
        
    /*
    template <typename T>
    void set(T v){
        value.set(v);
    }
    template <typename T>
    T get(){
        return value.get<T>();
    }
    */
};

class ANY_DERIVED : ANY{
    public:
        virtual ~ANY_DERIVED() = 0;
        template <typename T>
        ANY_DERIVED(T v): ANY(v){}
};

class ANY_ELEMENTARY : public ANY{
    public:
        virtual ~ANY_ELEMENTARY() = 0;
        template <typename T>
        ANY_ELEMENTARY(T v): ANY(v){}
};

class ANY_MAGNITUDE : public ANY_ELEMENTARY{
    public:
        virtual ~ANY_MAGNITUDE() = 0;
        template <typename T>
        ANY_MAGNITUDE(T v): ANY_ELEMENTARY(v){}
};

class ANY_NUM : public ANY_MAGNITUDE{
    public:
        virtual ~ANY_NUM() = 0;
        template <typename T>
        ANY_NUM(T v): ANY_MAGNITUDE(v){}
};

class ANY_INT : public ANY_NUM{
    public:
        virtual ~ANY_INT() = 0;
        template <typename T>
        ANY_INT(T v): ANY_NUM(v){}
};

class ANY_REAL : public ANY_NUM{
    public:
        virtual ~ANY_REAL() = 0;
        template <typename T>
        ANY_REAL(T v): ANY_NUM(v){}
};

class ANY_BIT : public ANY_ELEMENTARY{
    public:
        virtual ~ANY_BIT() = 0;
        template <typename T>
        ANY_BIT(T v): ANY_ELEMENTARY(v){}
};

class ANY_STRING : public ANY_ELEMENTARY{
    public:
        virtual ~ANY_STRING() = 0;
        template <typename T>
        ANY_STRING(T v): ANY_ELEMENTARY(v){}
};

class ANY_DATE : public ANY_ELEMENTARY{
    public:
        virtual ~ANY_DATE() = 0;
        template <typename T>
        ANY_DATE(T v): ANY_ELEMENTARY(v){}
};

class SINT : public ANY_INT{
    public:
        SINT();
        SINT(signed char v);
        signed char get();
        void set(signed char v);
};

class INT : public ANY_INT{
    public:
        INT();
        INT(short int v);
};

class DINT : public ANY_INT{
    public:
        DINT();
        DINT(int v);
};

class LINT : public ANY_INT{
    public:
        LINT();
        LINT(long long int v);
};

class USINT : public ANY_INT{
    public:
        USINT();
        USINT(unsigned char v);
};

class UINT : public ANY_INT{
    public:
        UINT();
        UINT(unsigned short int v);
};

class UDINT : public ANY_INT{
    public:
        UDINT();
        UDINT(unsigned int v);
};

class ULINT : public ANY_INT{
    public:
        ULINT();
        ULINT(unsigned long long int v);
};

class REAL : public ANY_REAL{
    public:
        REAL();
        REAL(float v);
};

class LREAL : public ANY_REAL{
    public:
        LREAL();
        LREAL(double v);
        //LREAL& operator=(const LREAL &other);

        double get();
        void set(double v);
};

class BOOL : public ANY_BIT{
    public:
        BOOL();
        BOOL(bool v);
};

class BYTE : public ANY_BIT{
    public:
        BYTE();
        BYTE(unsigned char v);
};

class WORD : public ANY_BIT{
    public:
        WORD();
        WORD(unsigned short int v);
};

class DWORD : public ANY_BIT{
    public:
        DWORD();
        DWORD(unsigned int v);
};

class LWORD : public ANY_BIT{
    public:
        LWORD();
        LWORD(unsigned long long int v);
};


/*
template<typename T>
struct t_type { static void id() { } };

template<typename T>
size_t type_id() { return reinterpret_cast<size_t>(&t_type<T>::id); }

template<typename T1, typename T2>
bool type_accepts(T1* type1, T2* type2){
    return std::is_base_of<T1, T2>::value;
}

template<typename T1, typename T2>
bool type_equals(T1* type1, T2* type2){
    return typeid(T1) == typeid(T2);
}


class TYPE{
    public:
        virtual ~TYPE() = 0;
    //protected:
        TYPE_ID type_id;
};

template <typename T>
struct ANY : TYPE{
    virtual ~ANY() = 0;
    //typedef T type;
    T value;
};

template <typename T>
struct ANY_DERIVED : ANY<T>{
    virtual ~ANY_DERIVED() = 0;
};

template<typename T>
struct ANY_ELEMENTARY : ANY<T>{
    virtual ~ANY_ELEMENTARY() = 0;
};

template <typename T>
struct ANY_MAGNITUDE : ANY_ELEMENTARY<T>{
    virtual ~ANY_MAGNITUDE() = 0;
    
    static T lowerBound(){
        return std::numeric_limits<T>::min(); 
    };
    static T upperBound(){
        return std::numeric_limits<T>::max();
    }
    static T initialValue(){
        return 0;
    };
    
};

template <typename T>
struct ANY_NUM : ANY_MAGNITUDE<T>{
    virtual ~ANY_NUM() = 0;
};

template <typename T>
struct ANY_INT : ANY_NUM<T>{
    virtual ~ANY_INT() = 0;
};

template <typename T>
struct ANY_REAL : ANY_NUM<T>{
    virtual ~ANY_REAL() = 0;
};

template <typename T>
struct ANY_BIT : ANY_ELEMENTARY<T>{
    virtual ~ANY_BIT() = 0;
};

template <typename T>
struct ANY_STRING : ANY_ELEMENTARY<T>{
    virtual ~ANY_STRING() = 0;
};

template <typename T>
struct ANY_DATE : ANY_ELEMENTARY<T>{
    virtual ~ANY_DATE() = 0;
};

struct SINT : ANY_INT<signed char>{
    SINT();
    //SINT(signed char val);
};

struct INT : ANY_INT<short>{
    INT();
    //SINT(signed char val);
};
*/


/*
enum TypeID{
    ANY = 1,
        //x3
        ANY_DERIVED = 3,
        //x2 
        ANY_ELEMENTARY = 2,
            //x2
            ANY_MAGNITUDE = 4,
                //x2
                ANY_NUM = 8,
                    //x2
                    ANY_INT = 16,
                        //x2
                        SHORT_INT = 32,
                        //x19
                        INT = 304,
                        //x23
                        DINT = 368,
                        //x29
                        LINT = 464,
                        //x31
                        USINT = 496,
                        //x37
                        UINT = 592,
                        //41
                        UDINT = 656,
                        //43
                        ULINT = 688,
                    //x17
                    ANY_REAL = 136,
                        //x17
                        REAL = 2312,
                        //x19
                        LREAL = 2584,
                //x13
                TIME = 52,
            //x5
            ANY_BIT = 10,
                //x13
                BOOL = 130,
                //x17
                BYTE = 170,
                //x19
                WORD = 190,
                //x23
                DWORD = 230,
                //x29
                LWORD = 290,
            //x7
            ANY_STRING = 14,
                //x13
                STRING = 182,
                //x17
                WSTRING = 238,
            //x11
            ANY_DATE = 22,
                //x13
                DATE = 286,
                //x17
                DATE_AND_TIME = 374,
                //x19
                TIME_OF_DAY = 418,
};

//Add Derived Types Later

template <typename T>
struct DerivedType{
    std::string baseType;
    int dimension; 
    T upperBound;
    T lowerBoundl 
    T defaultValue;
    std::unordered_map<std::string, int> enumlist;
};






struct GenericType{
    GenericType* parent;
    std::string label;
    GenericType(GenericType* p, std::string l);
    GenericType(std::string l);
    GenericType(const GenericType& gt);

    bool operator==(const GenericType& rhs) const;
    bool operator>=(const GenericType& rhs) const;
    bool operator<=(const GenericType& rhs) const;
    bool operator>(const GenericType& rhs) const;
    bool operator<(const GenericType& rhs) const;

};

template <typename T>
struct Type : GenericType {
    T lowerBound;
    T upperBound;
    T initialValue;

    Type(GenericType* p, std::string l, T lB, T uB, T iV) :  GenericType(p, l), lowerBound(lB), upperBound(uB), initialValue(iV){}
    //Type(std::string l, T lB, T uB, T iV) :  GenericType(l), lowerBound(lB), upperBound(uB), initialValue(iV){}

};

template <typename T>
struct DerivedEnumType:Type<T>{
    std::unordered_map<std::string, int> enumlist;
};

template <typename T>
struct DerivedArrayType:Type<T>{
    std::vector<T> array;
};

template <typename T>
struct DerivedSubrangeType:Type<T>{

};

class TypeList{
    private:
        std::unordered_map<std::string, GenericType*> types;
        //std::unordered_map<std::string, Type*> types;
        void initialize();
        
        //std::unordered_map<int, DerivedType> derived;

    public:
        TypeList();
        bool addType(GenericType* gt);
        //Type* string2type(std::string label);

        
        GenericType* operator[](const std::string& ind) const{
            return types[ind];
        }
        
        
        template <typename T>
        Type<T>* operator[](const std::string& ind){
            return (Type<T>*) types[ind];
        }
        
        //test
        
        template <typename T>
        Type<T>* type(std::string ind){
            return (Type<T>*) types[ind];
        }
        



        //GenericType* generic(std::string);
        //
        //template <typename T>
        //Type<T>* type(std::string);
        //Add derived types later
        //void derive(DerivedType dt);
        //void deriveEnum(std::string);

        //Check if type a accepts type b
        //bool accepts(int a, int b);
        //bool accepts(std::string s_a, std::string s_b);

        //Check if type a equals type b
        //bool equal(int a, int b);
        //bool equal(std::string s_a, std::string s_b);
};



struct BYTE{

};




struct DATE{
    int year;
    int mon;
    int day;
};

struct TIME{
    int hour;
    int min;
    int sec;
    int msec;
};

struct DATE_AND_TIME{
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
    int msec;
};
*/


#endif