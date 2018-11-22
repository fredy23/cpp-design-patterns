#include <iostream>
#include <memory>
#include <string>

#include "message.hpp"
#include "rot47_encryption_strategy.hpp"
#include "xor_encryption_strategy.hpp"

int main()
{
    std::string text = "Read the code";
    Message message(text, std::make_unique<ROT47EncryptionStrategy>());

    std::cout << "Plain message content: " << message.getData() << '\n';

    std::cout << "Using ROT-47 encryption\n";
    message.encrypt();
    std::cout << "Encrypted message: " << message.getData() << '\n';

    message.decrypt();
    std::cout << "Decrypted message: " << message.getData() << '\n';

    std::string key = "supersecret";
    message.setEncryptionStrategy(std::make_unique<XOREncryptionStrategy>(key));

    std::cout << "Using XOR encryption with key \"" << key << "\"\n";
    message.encrypt();
    std::cout << "Encrypted message in hexidecimal: " << message.getHexData() << '\n';

    message.decrypt();
    std::cout << "Decrypted message: " << message.getData() << '\n';
}
