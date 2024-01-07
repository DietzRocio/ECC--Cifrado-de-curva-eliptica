#include "ecc.h"
#include <iostream>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>

ECPoint ECC::generateKeyPair() {
    // Implementación de la generación de claves en la curva elíptica NIST P-256
    // Inicializar la curva elíptica NIST P-256
    EC_GROUP *group = EC_GROUP_new_by_curve_name(NID_X9_62_prime256v1);

    // Crear la estructura de la clave privada
    EC_KEY *key = EC_KEY_new();
    EC_KEY_set_group(key, group);
    EC_KEY_generate_key(key);

    // Obtenemos las coordenadas de la clave pública
    const EC_POINT *publicKeyPoint = EC_KEY_get0_public_key(key);
    BIGNUM *x_bn = BN_new();
    BIGNUM *y_bn = BN_new();
    EC_POINT_get_affine_coordinates_GFp(group, publicKeyPoint, x_bn, y_bn, NULL);

    // Crea un objeto ECPoint con las coordenadas obtenidas
    ECPoint publicKey(BN_get_word(x_bn), BN_get_word(y_bn));

    // Liberamos recursos
    BN_free(x_bn);
    BN_free(y_bn);
    EC_KEY_free(key);
    EC_GROUP_free(group);

    return publicKey;
}

std::pair<ECPoint, int> ECC::encrypt(const ECPoint& publicKey, int message) {
    // Implementación del algoritmo de ElGamal para encriptar
    // Generar un número aleatorio k (debería ser único para cada mensaje)
    int k = 42; // Placeholder, deberías generar un valor único cada vez

    // Punto base (g) en la curva elíptica
    EC_GROUP *group = EC_GROUP_new_by_curve_name(NID_X9_62_prime256v1);
    const EC_POINT *g = EC_GROUP_get0_generator(group);

    // Calcula C1=k*g
    ECPoint c1 = scalarMultiply(ECPoint(g), k);

    // Calcula C2=P+k*publicKey, donde P es el mensaje como punto en la curva
    ECPoint messagePoint(message, message);
    ECPoint c2 = addPoints(messagePoint, scalarMultiply(publicKey, k));

    // Libera recursos
    EC_GROUP_free(group);

    return c1;
}

int ECC::decrypt(const ECPoint& c1, int c2, int privateKey) {
    // Implementación del algoritmo de ElGamal para desencriptar
     // Calcula P= c2-privateKey*c1
    ECPoint c1Neg = scalarMultiply(c1, -privateKey);
    ECPoint messagePoint = addPoints(ECPoint(c2, c2), c1Neg);

    // Recupera el mensaje de las coordenadas x o y
    int decryptedMessage = messagePoint.x; 
    return decryptedMessage;
}


// Otras funciones de la clase ECC


