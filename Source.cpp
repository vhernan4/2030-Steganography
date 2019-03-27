#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ios;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

void FullEncode(string file1, string file2, string message);
string encodePix(string pixel, char place, char val);
bool replace(char val, char pixVal);
string Let_To_Bin(char letter);
char change(char var);

int main()
{
	string str("hello world#");
	FullEncode("Pixels2.txt", "newPixList.txt", str);
	system("Pause");
	return 0;
}
void FullEncode(string file1, string file2, string message)
{
	string::iterator first;
	string::iterator second;
	string tmpLine;
	ifstream inFile;
	ofstream outFile;
	int index1 = 0;
	int index2 = 0;
	string binVal;

	//Open Files, Break if unable
	inFile.open(file1);
	outFile.open(file2, ofstream::app);
	if (!inFile)
	{
		cout << "Could not open file: " << file1 << endl;
		return;
	}

	//Itterate through the given string (message), breaking it down into each character.
	for (first = message.begin(); first < message.end(); first++, index1++)
	{
		//Translate the given char into a string of binary numbers
		binVal = Let_To_Bin(*first);
		index2 = 0;
		for (second = binVal.begin(); second < binVal.end(); second++, index2++)
		{
			//While iterating through the binary string, take a pixel and encode the char onto it (Tree cases for r, g, and b)
			getline(inFile, tmpLine);
			if (index2 % 3 == 0)
			{
				outFile << (encodePix(tmpLine, 'r', static_cast<char>(*second)) + "\n");
			}
			else if (index2 % 3 == 1)
			{
				outFile << (encodePix(tmpLine, 'g', static_cast<char>(*second)) + "\n");
			}
			else
			{
				outFile << (encodePix(tmpLine, 'b', static_cast<char>(*second)) + "\n");
			}

		}
	}
	while (!(inFile.eof()))
	{
		getline(inFile, tmpLine);
		outFile << tmpLine;
	}
	return;
}
string encodePix(string pixel, char place, char val)
{
	string newPix = "";
	string::iterator pixIt;
	int step = 0;
	if (place == 'r')
	{
		for (pixIt = pixel.begin(); pixIt < pixel.end(); pixIt++, step++)
		{
			if (step == 1)
			{
				if (replace(val, *pixIt))
				{
					newPix += change(*pixIt);
				}
				else
				{
					newPix += *pixIt;
				}
			}
			else
			{
				newPix += *pixIt;
			}
		}
	}
	else if (place == 'g')
	{
		for (pixIt = pixel.begin(); pixIt < pixel.end(); pixIt++, step++)
		{
			if (step == 3)
			{
				if (replace(val, *pixIt))
				{
					newPix += change(*pixIt);
				}
				else
				{
					newPix += *pixIt;
				}
			}
			else
			{
				newPix += *pixIt;
			}
		}
	}
	else
	{
		for (pixIt = pixel.begin(); pixIt < pixel.end(); pixIt++, step++)
		{
			if (step == 5)
			{
				if (replace(val, *pixIt))
				{
					newPix += change(*pixIt);
				}
				else
				{
					newPix += *pixIt;
				}
			}
			else
			{
				newPix += *pixIt;
			}
		}
	}

	return newPix;
}
bool replace(char val, char pixVal)
{
	bool yes;
	//Returns true if val and pixVal have the same final binary number, otherwise it returns false
	if (val == '1')
	{
		if (pixVal == '1' || pixVal == '3' || pixVal == '5' || pixVal == '7' || pixVal == '9' || pixVal == 'b' || pixVal == 'd' || pixVal == 'f')
		{
			yes = true;
		}
		else
		{
			yes = false;
		}
	}
	else
	{
		if (pixVal == '0' || pixVal == '2' || pixVal == '4' || pixVal == '6' || pixVal == '8' || pixVal == 'a' || pixVal == 'c' || pixVal == 'e')
		{
			yes = true;
		}
		else
		{
			yes = false;
		}
	}
	return yes;
}
string Let_To_Bin(char letter)
{
	//Contains Unicode-8 values of the lowercase alphabet, 0-9, space, and the following four punctuation',' '.' '?' '!'
	string val;
	switch (letter)
	{
	case 'a':
		val = "01100001";
		break;
	case 'b':
		val = "01100010";
		break;
	case 'c':
		val = "01100011";
		break;
	case 'd':
		val = "01100100";
		break;
	case 'e':
		val = "01100101";
		break;
	case 'f':
		val = "01100110";
		break;
	case 'g':
		val = "01100111";
		break;
	case 'h':
		val = "01101000";
		break;
	case 'i':
		val = "01101001";
		break;
	case 'j':
		val = "01101010";
		break;
	case 'k':
		val = "01101011";
		break;
	case 'l':
		val = "01101100";
		break;
	case 'm':
		val = "01101101";
		break;
	case 'n':
		val = "01101110";
		break;
	case 'o':
		val = "01101111";
		break;
	case 'p':
		val = "01110000";
		break;
	case 'q':
		val = "01110001";
		break;
	case 'r':
		val = "01110010";
		break;
	case 's':
		val = "01110011";
		break;
	case 't':
		val = "01110100";
		break;
	case 'u':
		val = "01110101";
		break;
	case 'v':
		val = "01110110";
		break;
	case 'w':
		val = "01110111";
		break;
	case 'x':
		val = "01111000";
		break;
	case 'y':
		val = "01111001";
		break;
	case 'z':
		val = "01111010";
		break;
	case ' ':
		val = "00100000";
		break;
	case '.':
		val = "00101110";
		break;
	case ',':
		val = "00101100";
		break;
	case '?':
		val = "00111111";
		break;
	case '!':
		val = "00100001";
		break;
	case '1':
		val = "00110001";
		break;
	case '2':
		val = "00110010";
		break;
	case '3':
		val = "00110011";
		break;
	case '4':
		val = "00110100";
		break;
	case '5':
		val = "00110101";
		break;
	case '6':
		val = "00110110";
		break;
	case '7':
		val = "00110111";
		break;
	case '8':
		val = "00111000";
		break;
	case '9':
		val = "00111001";
		break;
	case '0':
		val = "00110000";
		break;
	case '#':
		val = "00100011";
	default:
		val = "00000000";
	}
	return val;
}
char change(char var)
{
	char newVar;
	switch (var)
	{
	case '0':
		newVar = '1';
		break;
	case '1':
		newVar = '2';
		break;
	case '2':
		newVar = '3';
		break;
	case '3':
		newVar = '4';
		break;
	case '4':
		newVar = '5';
		break;
	case '5':
		newVar = '6';
		break;
	case '6':
		newVar = '7';
		break;
	case '7':
		newVar = '8';
		break;
	case '8':
		newVar = '9';
		break;
	case '9':
		newVar = 'a';
		break;
	case 'a':
		newVar = 'b';
		break;
	case 'b':
		newVar = 'c';
		break;
	case 'c':
		newVar = 'd';
		break;
	case 'd':
		newVar = 'e';
		break;
	case 'e':
		newVar = 'f';
		break;
	case 'f':
		newVar = 'e';
		break;
	default:
		newVar = '0';
	}
	return newVar;
}