#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map> 
#include <thread>  
#include "json.hpp"
#include <fstream>
namespace fs = std::filesystem;
using json = nlohmann::json;







int main(int argc, char* argv[]){

 
 std::ifstream file("archive_types.json");
 json data = json::parse(file) ; 
 std::cout << "JSON items cargados: " << data.size() << std::endl;
  


 //variables===============================================================================
 //std::string route;
 std::unordered_map<std::string , std::string >extensionMap;
 //extensionMap[element.key()] = element.value();
 
 std::string category ; 

 //variables===============================================================================
 
    if(argc < 2){
        
        std::cerr << "No route provided.\n";
      return 1;
    }

std::string route = argv[1];

    //bucle para recorrer todos los archivos de la ruta
    for(const auto& entry2 : fs::directory_iterator(route)){

        //guardar tipo de archivo del archivo iterado en la actualidad 
        std::string extension = entry2.path().extension().string();
        std::cout << "[+] Archivo: " << entry2.path().filename().string() << " | Extension: " << extension << std::endl;

        bool found = false;
        //bucle pa comparar la si son compatibles con las extensiones posibles
        //for(for auto& element : data.items()){

            

            //identificar extension
            for(auto& [key , value] : data.items()){
              
                for(auto& ext : value){
                    if(extension == ext.get<std::string>() ){
                        found = true ;
                        category = key;
                     break;
                    }
                }

                if(found){
                  
                    break;  

                }
            }
            //verificar si ya existe una carpeta organizadora  
            if (found){

                std::string newfolder = route + "/" + category; 

                if(!fs::exists(newfolder)){
                    fs::create_directory(newfolder);
                            
                }
                
                    
                
                std::string namefile = entry2.path().filename().string();
 
                //mover ruta porfinnnnnnnnnnnn
                fs::rename(
                    entry2.path(),
                     
                    route + "/" + category + "/" + namefile

                );
                
            }        
                                          
            else{
                //error de no fucking compatibilidad ._____.
                std::cerr << "[!]Type: ERROR :this type of archive is not compatible with our program"  << std::endl; 

            }       
 
        //}
    
      
    }
    //ya es todo we
    std::cout << "success" ;

    return 0 ; 
}