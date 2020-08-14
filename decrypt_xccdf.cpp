#include "decrypt_xccdf.h"
/**sha256 복호화*/
char* decrypt(int key, char* encrypted_xml){
    char* decrypted_xml=(char*)malloc(sizeof(encrypted_xml)/sizeof(char));
    return sha256(key, encrypted_xml);
}