#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#include <ratio>
#include<chrono>
using namespace std;
class FileNameNode {
public:
	string fileName;
	FileNameNode *next;
	FileNameNode(const string fname) :fileName(fname), next(NULL){}
	FileNameNode() {
		next = NULL;
	}
};
class WordTypeNode {
public:
	string word;
	int wordFreq ;
	FileNameNode* fileListHead;
	WordTypeNode* left , *right;
	WordTypeNode() {
		left = NULL;
		right = NULL;
	}

};
class IndexLinkedList {
private:
	WordTypeNode* head;
public:
	IndexLinkedList() :head(NULL) {}
	void addWord(const string& word, const string& fileName) 
	{
		int tut=0;
		if (head == NULL)
		{
			WordTypeNode* walk = head;
			walk->word = word;
			walk->fileListHead->fileName = fileName;
			walk->wordFreq = 1;
		}
		else
		{
			WordTypeNode* walk = head;
			while (walk != NULL || walk->word != word)
			{
				if (walk.word < word)
				{
					if (walk == NULL) 
					{
						tut = 3;
						break;
					}
					else if (walk->word == word)
					{
						tut = 2;
						break;
					}
					walk = walk->left;
				}
				else 
				{
					if (walk == NULL)
					{
						tut = 3;
						break;
					}
					else if (walk->word == word)
					{
						tut = 2;
						break;
					}
					walk = walk->right;
				}
			}
		
			if (tut == 3) 
			{  
				walk = new WordTypeNode();
				walk->word = word;
				walk->wordFreq = 1;
				walk->fileListHead->fileName = fileName;
			}
			else if (tut == 2) {
				walk->wordFreq = 1 + walk->wordFreq;
				FileNameNode* dosya;
				dosya = new FileNameNode(fileName);
				walk->fileListHead->next = dosya;
			}	
	    }

	}

	void printListOfFiles(const string& singleWordQuery)const {
		WordTypeNode* walk = head;
		int i;
		while (walk != NULL || walk->word != word)
		{
			if (walk.word < word)
			{
				if (walk == NULL)
				{
					i = 2;
					break;
				}
				else if (walk->word == word)
				{
					i = 1;
					break;
				}
				walk = walk->left;
			}
			else
			{
				if (walk == NULL)
				{
					i = 2;
					break;
				}
				else if (walk->word == word)
				{
					i = 1;
					break;
				}
				walk = walk->right;
			}
		}
		if (i == 2)
		{
			cout << "This word  is not existed";
		}
		else if (i == 1)
		{
			FileNameNode* dosya = walk->fileListHead;
			while (dosya != NULL)
			{
				cout << dosya->fileName << " ";
				dosya = dosya->next;
			}
		}

	}

	void Inorder( WordTypeNode* node , int topWhat)
	{
		if (node->wordFreq >= topWhat) {
			node = node;
			return;
		}
		Inorder(node->left);
		Inorder(node->right);
	}

	void printMostFrequentWords(int topWhat) {
		WordTypeNode* walk = head;
		int i = 0;
		string str[10];
		while (walk != NULL)
		{
			if (i == 9)
			{
				break;
			}
			else if (walk->wordFreq >= topWhat)
			{
				Inorder(walk, topWhat);
				str[i] = walk->word;
				i++;
			}

			if (walk == NULL) {
				if (head->left > head->right) {
					walk = head->right;
				}
				else
				{
					walk = head->left;
				}
			}
		}
		for (int k = 0; k <= 9; k++)
		{
			cout << str[i] << " ";
		}

	}

	void printLeastFrequentWords(int topWhat) {
		WordTypeNode* walk = head;
		int i = 0;
		string str[10];
		while (walk != NULL)
		{
			if (i == 9)
			{
				break;
			}
			else if (walk->wordFreq <= topWhat)
			{
				Inorder(walk, topWhat);
				str[i] = walk->word;
				i++;
			}

			if (walk == NULL) {
				if (head->left > head->right) {
					walk = head->right;
				}
				else
				{
					walk = head->left;
				}
			}
		}
		for (int k = 0; k <= 9; k++)
		{
			cout << str[i] << " ";
		}
	}
};

void getValidOption(int& option) {
	do {
		cin >> option;
   } while (!(option < 5 && option>0));
}
int  printDecoratedMenu(const string& indexCreationDuration) {
	int i = 0;
	cout << (char)201;
	for (i; i <= 80; i++) {
		cout << (char)205;
	}
	cout << (char)187;
	cout <<endl << (char)186;
	for (i = 0; i <= 29; i++) {
		cout << " ";
	}
	cout << "Simple Document System";
	for (i = 0; i <= 28; i++) {
		cout << " ";
	}
	cout << (char)186<<endl;
	cout << (char)186;
	cout << "                                 "<< indexCreationDuration<<"                                 ";
	cout<< (char)186<<endl;
	cout << (char)204;
	for (i=0; i <= 80; i++) {
		cout << (char)205;
	}
	cout << (char)185<<endl;
	cout << (char)186;
	cout << "          1.Enter a single keyword to list the document(s)(file names)           " << (char)186<<endl;
	cout <<(char)186<< "          2.Print the top 10 words that appeared most frequently                 " << (char)186 << endl;
	cout << (char)186 << "          3.Print the top 10 words that appeared least frequently                " << (char)186 << endl;
	cout << (char)186 << "          4.Exit                                                                 " << (char)186 << endl;
	cout << (char)200;
	for (i = 0; i <= 80; i++) {
		cout << (char)205;
	}
	cout << (char)188<<endl;
	cout << "Option:";
	int option;
	cin >> option;
	getValidOption(option);
	return option;
}

void createIndex(IndexLinkedList& index, const string directoryOfFiles) {
	fstream dosya;
	string word;
	dosya.open(directoryOfFiles,ios::in);
	while (dosya >> word) {
		index.addWord(word,directoryOfFiles);
	}	
	dosya.close();
}
int main() {
	string dirName = "allDocs";
	IndexLinkedList index;
	string idxCreationTime;
	string ch = "";
	int i=1;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	for (i = 1; i <= 21; i++)
	{
		ch = i + "";
		createIndex(index, ch);
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> final = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);	
	idxCreationTime = std::to_string(final.count())+"Seconds";
	int opt;
	opt = printDecoratedMenu(idxCreationTime);
		while (opt != 4) {
			opt = printDecoratedMenu(idxCreationTime);
			if (opt == 1)
			{
				string queryWord;
				cout << "Enter single query word : ";
				cin >> queryWord;
				index.printListOfFiles(queryWord);
			}
			else if (opt == 2) { index.printMostFrequentWords(10); }
			else if (opt == 3) { index.printLeastFrequentWords(10); }
		}
		return (0);
	}