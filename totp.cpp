#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdint>
#include <liboath/oath.h>
#include <cctype>
#include <vector>

class TOTP {
private:
    uint8_t decoded_secret[20];
    size_t decoded_secret_len;
    unsigned long time_step;
    time_t t0;

    // Decode Base32-encoded secret and store it in decoded_secret
    void decode_base32_secret(const std::string &base32_secret) {
        // Implement Base32 decoding
        const std::string base32_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
        std::vector<uint8_t> buffer;

        for (size_t i = 0, index = 0; i < base32_secret.size(); ) {
            uint8_t curr_byte = 0, bits_remaining = 8;

            while (bits_remaining) {
                size_t value = base32_chars.find(toupper(base32_secret.at(i++)));
                if (value == std::string::npos) {
                    continue;
                }

                uint8_t bits_to_write = std::min(5, bits_remaining);
                bits_remaining -= bits_to_write;
                curr_byte |= (value & ((1 << bits_to_write) - 1)) << bits_remaining;

                if (bits_remaining == 0) {
                    buffer.push_back(curr_byte);
                } else {
                    bits_remaining -= 5 - bits_to_write;
                    curr_byte |= value >> bits_to_write;
                }
            }
        }

        decoded_secret_len = std::min(buffer.size(), sizeof(decoded_secret));
        std::copy(buffer.begin(), buffer.begin() + decoded_secret_len, decoded_secret);
    }

public:
    TOTP(const std::string &base32_secret, unsigned long time_step = 30, time_t t0 = 0)
        : time_step(time_step), t0(t0) {
        decode_base32_secret(base32_secret);
    }

    // Generate TOTP token based on the decoded secret, time step, and current Unix timestamp
    uint64_t generate_totp() {
        time_t current_time = time(NULL);
        uint64_t counter = (current_time - t0) / time_step;

        unsigned int totp;
        oath_hotp_generate(decoded_secret, decoded_secret_len, counter, 6, 0, 0, &totp);

        return totp;
    }
};

int main() {
    std::string base32_secret;
    std::cout << "Enter your Base32-encoded shared secret: ";
    std::cin >> base32_secret;

    TOTP totp(base32_secret);

    uint64_t totp_token = totp.generate_totp();
    std::cout << "Your TOTP token is: " << std::setw(6) << std::setfill('0') << totp_token << std::endl;

    return 0;
}