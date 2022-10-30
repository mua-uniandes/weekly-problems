#include <iostream>
#include <cmath>
#include<sstream> 
using namespace std;
string splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    int lista_numeros[4];
    int contador=0;
    string respuesta="";
    stringstream ss;
    int num;
    while (end != -1) {  
        ss << str.substr(start, end - start) << endl;
        ss>> num;
        lista_numeros[contador]=num;
        contador++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    ss << str.substr(start, end - start);
    ss>> num;
    lista_numeros[3]=num;
    int x1,x2,y1,y2;
    x1=lista_numeros[0];
    x2=lista_numeros[2];
    y1=lista_numeros[1];
    y2=lista_numeros[3];
    for(int i=0;i<3;i++){
        if(i==0){
                if(x1==x2||y1==y2){
                    respuesta=respuesta+""+to_string(1);
                }
                else{
                    respuesta=respuesta+""+to_string(2);
                }
            }
        else if(i==1){
                if(abs(x1-x2)==abs(y1-y2)){
                    respuesta=respuesta+" "+to_string(1);
                }
                else if((abs(x1-x2)%2==0)&&(abs(y1-y2)%2==1)){
                    respuesta=respuesta+" "+to_string(0);
                }
                else if((abs(x1-x2)%2==1)&&(abs(y1-y2)%2==0)){
                    respuesta=respuesta+" "+to_string(0);
                }
                else{
                    respuesta=respuesta+" "+to_string(2);
                }
            }
            else if(i==2){
                int restax=(abs(x1-x2));
                int restay=(abs(y1-y2));
                int resp=max(restax, restay);
                respuesta=respuesta+" "+to_string(resp);
                
            }
    }
    return respuesta;
}
int main()
{
    string numeros;
    getline(cin,numeros);
    cout << splitstr(numeros);
    return 0;
}