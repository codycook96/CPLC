#include "Database.h"

void Database::add(TYPE_ID id, std::string varName){
    ANY* var;
    switch(id){
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
    std::pair<ANY*, TYPE_ID> dataPair(var, id);
    data.insert(std::pair<std::string, std::pair<ANY*, TYPE_ID>>(varName, dataPair));

}

TYPE_ID Database::type(std::string varName){
    return data.at(varName).second;
}