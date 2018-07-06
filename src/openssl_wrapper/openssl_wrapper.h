#ifndef OPENSSL_WRAPPER_H
#define OPENSSL_WRAPPER_H

#include <string>

void InitOpenSSL();

using PrivateKey = std::string;
using PublikKey = std::string;

PublikKey getPublic(const std::string &privKey, const std::string &password);

PrivateKey createRsaKey(const std::string &password);

std::string encrypt(const std::string &pubkey, const std::string &message);

std::string decrypt(const std::string &privkey, const std::string &password, const std::string &message);

#endif // OPENSSL_WRAPPER_H
