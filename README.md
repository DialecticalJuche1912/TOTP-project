# TOTP-project
This App uses a Time-based one-time password (TOTP) algorithm to implement 2 factor authentification for users to safeguard and access their resources 
and data safely, which helps to protect user accounts from unauthorized access. 
This is a simple Time-Based One-Time Password (TOTP) generator implemented in C++. 
It generates a 6-digit TOTP token based on a given Base32-encoded shared secret. 
The TOTP algorithm is built upon the HMAC-based One-Time Password (HOTP) algorithm, 
and this implementation follows the specifications of [RFC 6238 (TOTP)](https://www.rfc-editor.org/rfc/rfc6238) and [RFC 4226 (HOTP)](https://www.ietf.org/rfc/rfc4226.txt).

## Installation and useage:
1. C Compiler: Choose a C compiler such as GCC or Clang to compile the program.
2. Text Editor: Use a text editor such as Visual Studio Code or Sublime Text to write and edit the code.
3. liboath: Install the liboath library for TOTP support. Find installation instructions for your platform on the library's website.
4. Compile the program with your chosen C compiler and run the compiled program.
Depending on your compiler, this could look like `g++ -o totp totp.cpp -loath` and then run the code with `./totp` on the terminal
5. When prompted, enter your Base32-encoded shared secret.
6. The program will generate a TOTP token based on the provided shared secret and display it on the screen.

You can Open and view the project using the .zip file provided or at my [Github Repo](https://github.com/DialecticalJuche1912/TOTP-project).
Here's a [video demonstration](https://vimeo.com/846209083211) of this app.

### Functionalities
The TOTP generator program provides the following functionalities:

Decoding a Base32-encoded shared secret.
Generating a TOTP token based on the decoded secret, time step (default: 30 seconds), and current Unix timestamp.

### Libraries used: 
The following libraries are used in this program:

1. C++ libraries for input/output, formatting, time manipulation, and character manipulation: iostream, iomanip, ctime, cstdint, and cctype 
2. The liboath library, oath.h, which provides functions for generating HOTP and TOTP tokens.
3. Vector, The C++ Standard Library's vector container for dynamic arrays.


## Acknowledgement:

This app is inspired by the Duo 2-factor authentification application used by The University of Waterloo 

Parts of the idea of this app have referenced Chapter 9, RSA of the Math 135 Textbook of The University of Waterloo 
### Papers Referenced:
[RFC 6238 (TOTP)](https://www.rfc-editor.org/rfc/rfc6238)

[RFC 4226 (HOTP)](https://www.ietf.org/rfc/rfc4226.txt)

