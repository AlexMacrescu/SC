#include <stdio.h>
#include <iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include "RSA.h"
#include "AES.h"
#include "DES.h"

using namespace std;





int main() {
	int option;
	do {
		std::cout << "\n1 | AES";
		std::cout << "\n2 | DES";
		std::cout << "\n3 | RSA";
		std::cout << "\n0 | EXIT\n";

		RSA myRSA;
		AES myAES;
		DES myDES;


		cin >> option;
		switch (option) {
		case 1:
			myRSA.runRSA();
			break;
		case 2:
			myAES.runAES();
			break;
		case 3:
			myDES.runDES();
		default:
			break;
		}
	} while (option != 0);
}