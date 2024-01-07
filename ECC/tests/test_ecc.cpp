//usando google test
#include "gtest/gtest.h"
#include "../ecc.h"

TEST(ECCKeyGeneration, GeneratesKeyPair) {
    ECPoint publicKey = ECC::generateKeyPair();
    // Asegúrate de que la clave pública se haya generado correctamente
    ASSERT_NE(publicKey.x, 0);
    ASSERT_NE(publicKey.y, 0);
}

TEST(ECCEncryption, EncryptsMessage) {
    ECPoint publicKey = ECC::generateKeyPair();
    int message = 123;

    ECPoint ciphertext = ECC::encrypt(publicKey, message);
    // Asegúrate de que el cifrado no sea el punto en el infinito
    ASSERT_NE(ciphertext.x, 0);
    ASSERT_NE(ciphertext.y, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
  por consola va lo siguiente una vez instalado google test;
  g++ -std=c++11 -o test_ecc tests/test_ecc.cpp ecc.cpp -lgtest -lgtest_main -pthread
  ./test_ecc
  
  Esto debería compilar y ejecutar las pruebas unitarias.
  Si todo está configurado correctamente, deberiamos
  ver la salida indicando si las pruebas pasaron o fallaron.
*/