#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map> 
#include <thread>  
#include "json.hpp"
#include <fstream>
namespace fs = std::filesystem;
using json = nlohmann::json;



//funciones-------------------------------------------------------------------------
void printbanner(){

    std::cout<<
    R"(
            _______ _________ _         _______   _______  _______  _______  _______ 
            (  ____ \\__   __/( \      (  ____ \ (  ___  )(  ____ )(  ____ \(  ___  )
            | (    \/   ) (   | (      | (    \/ | (   ) || (    )|| (    \/| (   ) |
            | (__       | |   | |      | (__     | |   | || (____)|| |      | (___) |
            |  __)      | |   | |      |  __)    | |   | ||     __)| | ____ |  ___  |
            | (         | |   | |      | (       | |   | || (\ (   | | \_  )| (   ) |
            | )      ___) (___| (____/\| (____/\ | (___) || ) \ \__| (___) || )   ( |
            |/       \_______/(_______/(_______/ (_______)|/   \__/(_______)|/     \|
             _       _________ _______  _______  _______                            
            ( (    /|\__   __// ___   )(  ____ \(  ____ )                           
            |  \  ( |   ) (   \/   )  || (    \/| (    )|                           
            |   \ | |   | |       /   )| (__    | (____)|                           
            | (\ \) |   | |      /   / |  __)   |     __)                           
            | | \   |   | |     /   /  | (      | (\ (                              
            | )  \  |___) (___ /   (_/\| (____/\| ) \ \__                           
            |/    )_)\_______/(_______/(_______/|/   \__/
    )";
    std::cout<< "---------------------------------Coded by: Marelo Folcarelli------"<<std::endl;
    std::cout<< "----------------------------------------version: 0.1.0------------"<<std::endl;
}

//funciones--------------------------------------------------------------------------------

int main(){

 
 std::ifstream file("archive_types.json");
 json data = json::parse(file) ; 
 std::cout << "[DEBUG] JSON items cargados: " << data.size() << std::endl;
  


 //variables===============================================================================
 std::string route;
 std::unordered_map<std::string , std::string >extensionMap;
 //extensionMap[element.key()] = element.value();
 
 std::string category ; 

 //variables===============================================================================
 
 printbanner();

 std::cout << "[+]enter the route that u want to organize [the archives has to be in a mother/main carpet]:";
 getline( std::cin ,route/*_string*/ );

    //bucle para recorrer todos los archivos de la ruta
    for(const auto& entry2 : fs::directory_iterator(route)){

        //guardar tipo de archivo del archivo iterado en la actualidad 
        std::string extension = entry2.path().extension().string();
        std::cout << "[DEBUG] Archivo: " << entry2.path().filename().string() << " | Extension: " << extension << std::endl;

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