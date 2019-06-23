#include "Database.h"

void Database::add(TYPE t, std::string varName){
    ANY* var;
    switch(t.id){
        case TYPE_SINT:  {
                var = new SINT();
                //SINT* var = new SINT();
                //std::pair<ANY*, TYPE_ID> dataPair = make_pair(var, id);
                //data.insert(std::pair<std::string, std::pair<ANY*, TYPE_ID>>(varName, dataPair);
            }   
            break;
        case TYPE_INT: {
                var = new INT();
                //INT* var = new INT();
                //data.insert(std::pair<std::string, ANY*>(varName, var));
            }
            break;
        case TYPE_BOOL: {
                var = new BOOL();
                //BOOL* var = new BOOL();
                //data.insert(std::pair<std::string, ANY*>(varName, var));
            }
            break; 
        default:

            break;
    }
    std::pair<TYPE, ANY*> dataPair(t, var);
    data.insert(std::pair<std::string, std::pair<TYPE, ANY*>>(varName, dataPair));

}

TYPE Database::getType(std::string varName){
    if(data.find(varName) == data.end()){
        std::cout << "No such data exists" << std::endl;
    }
    
    return data.at(varName).first;
}