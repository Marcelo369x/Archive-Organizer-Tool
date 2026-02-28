#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib> 
namespace fs = std::filesystem;


//funciones-------------------------------------------------------------------------
void printbanner(){

    std::cout<<
    R"(
            _______ _________ _         _______   _______  _______  _______  _______ 
\033[31     (  ____ \\__   __/( \      (  ____ \ (  ___  )(  ____ )(  ____ \(  ___  )[0m
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
    std::cout<< "----------------------------------------version: 0.0.0------------"<<std::endl;
}
/*void FileOrganizer(int fi, auto froute){
    string FileNames[]={"word","Sounds","textos","c++ codes","python codes","html codes","rar files","images","zip files","pdfs files","powerpoint","excel","","","","",""}
        if(!exist(FileNames[fi])){

            fs::create_directory(FileNames[fi]);
    
        }
}*/
//funciones--------------------------------------------------------------------------------

int main(){
 //variables===============================================================================
 /*fs::path*/std::string route;
 std::string ArchiveTypes[]={".docx",".mp3",".txt",".cpp",".py", ".html",".rar",".jpg",".zip",".pdf",".pptx",".xlsx"};
 std::string FilesNames[]={"word","Sounds","textos","c++ codes","python codes","html codes","rar files","images","zip files","pdfs files","powerpoint","excel"};
 
 //variables===============================================================================
 
 printbanner();

 std::cout << "[+]enter the route that u want to organize [the archives has to be in a mother/main carpet]:";
 getline( std::cin ,route/*_string*/ );
    //bucle para recorrer todos los archivos de la ruta
    for(const auto& entry2 : fs::directory_iterator(route)){

        //guardar tipo de archivo del archivo iterado en la actualidad 
        std::string extension = entry2.path().extension().string();
        
        //bucle pa comparar la si son compatibles con las extensiones posibles
        for(int i=0 ; i < 12 ; i++){

            //identificar extension
            if(extension == ArchiveTypes[i]){
              
                    //verificar si ya existe una carpeta organizadora                
                    
                     if(!fs::exists(route + "/" +FilesNames[i])){
                                fs::create_directory(route + "/" + FilesNames[i]);
                            
                        }
                
                    
                
                        std::string namefile = entry2.path().filename().string();
 
                        //mover ruta porfinnnnnnnnnnnn
                        fs::rename(
                            entry2.path(),
                            route + "/" + FilesNames[i] + "/" + entry2.path().filename().string()
                            
                        );
                        break;

            }                                
            else{
                //error de no fucking compatibilidad ._____.
                std::cerr << "[!]Type: ERROR :this type of archive is not compatible with our program" ; 

            }
 
        }
    
      
    }
    //ya es todo we
    std::cout << "success" ;

    return 0 ; 
}