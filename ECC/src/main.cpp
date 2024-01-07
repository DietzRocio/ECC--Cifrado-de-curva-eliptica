#include "ecc.h"
#include <iostream>
using namespace std; 

int main (){
    // Pruebas y ejemplos de uso
    ECPoint publicKey = ECC::generateKeyPair();

    cout<<"Clave pública generada: ("<< publicKey.x<<", "<< publicKey.y<<")"<< std::endl;

    int mensajeOriginal = 123;

    // Encriptar el mensaje
    auto cifrado = ECC::encrypt(publicKey, mensajeOriginal);
    cout<<"Mensaje original: "<<mensajeOriginal << endl;
    cout<<"Cifrado C1: (" <<cifrado.x<< ", " <<cifrado.y<<")"<< endl;

    // Desencriptar el mensaje
    int mensajeDesencriptado = ECC::decrypt(cifrado, mensajeOriginal, 42); // Aquí asumimos que k=42
    cout<<"Mensaje desencriptado: "<<mensajeDesencriptado<<endl;

    // Pruebas adicionales
    int otroMensaje = 456;

    auto otroCifrado = ECC::encrypt(publicKey, otroMensaje);
    cout <<"Mensaje 2: " << otroMensaje << endl;
    cout <<"cifrado C1: (" << otroCifrado.x << ", " << otroCifrado.y << ")" << endl;

    int otroDesencriptado = ECC::decrypt(otroCifrado, otroMensaje, 42);
    cout<<"mensaje desencriptado 2: "<<otroDesencriptado<<endl;

    return 0;}