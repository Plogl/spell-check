#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

template<typename K, typename V>
void print_map(unordered_map<K, V> const& m)
{
	for (auto const& pair : m)
	{
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}

template <typename S>
ostream& operator<<(ostream& os,
	const vector<S>& vector)
{
	for (auto element : vector)
	{
		os << element << " ";
	}
	return os;
}

class SpellCheck
{
public:
	unordered_map<string, string> dictionary;

	vector<string> swapChar(string x)
	{
		string words = x;
		vector<string> replacementWordsSwap;
		//left these as j in case I went back to taking in a vector as an argument
		for (int j = 0; j < words.size(); j++)
		{
			swap(words[j], words[j + 1]);
			if (dictionary.find(words) != dictionary.end() and find(replacementWordsSwap.begin(),
				replacementWordsSwap.end(), words) == replacementWordsSwap.end())
			{
				replacementWordsSwap.push_back(words);
			}
			words = x;
		}
		return replacementWordsSwap;
	}

	vector<string> delChar(string x)
	{
		string words = x;
		vector<string> replacementWordsDel;
		//left these as j in case I went back to taking in a vector as an argument
		for (int j = 0; j < words.size(); j++)
		{
			char temp;
			string temp2;
			temp = words[j];
			temp2 = temp;
			words.erase(j, 1);
			if (dictionary.find(words) != dictionary.end() and find(replacementWordsDel.begin(),
				replacementWordsDel.end(), words) == replacementWordsDel.end())
			{
				replacementWordsDel.push_back(words);
				// Debating whether or not I should have multiple recommendations by putting this outside the loop, but sticking to one for now
			}
			words.insert(j, temp2);
		}
		return replacementWordsDel;
	}

	vector<string> insChar(string x)
	{
		string words = x;
		vector<string> replacementWordsIns;
		string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n",
								"o","p","q","r","s","t","u","v","w","x","y","z" };
		//left these as j in case I went back to taking in a vector as an argument
		for (int j = 0; j < words.size(); j++)
		{
			char temp;
			string temp2;
			temp = words[j];
			for (int i = 0; i < 26; i++)
			{
				words.insert(j, alphabet[i]);
				if (dictionary.find(words) != dictionary.end() and find(replacementWordsIns.begin(),
					replacementWordsIns.end(), words) == replacementWordsIns.end())
				{
					replacementWordsIns.push_back(words);
					// Debating whether or not I should have multiple recommendations by putting this outside the loop, but sticking to one for now
				}
				words.erase(j, 1);
			}
		}
		return replacementWordsIns;
	}
	vector<string> replaceChar(string x)
	{
		string words = x;
		vector<string> replacementWordsReplace;
		string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n",
								"o","p","q","r","s","t","u","v","w","x","y","z" };
		//left these as j in case I went back to taking in a vector as an argument
		for (int j = 0; j < words.size(); j++)
		{
			char temp;
			string temp2;
			temp = words[j];
			temp2 = temp;
			words.erase(j, 1);
			for (int i = 0; i < 26; i++)
			{
				words.insert(j, alphabet[i]);
				if (dictionary.find(words) != dictionary.end() and find(replacementWordsReplace.begin(),
					replacementWordsReplace.end(), words) == replacementWordsReplace.end())
				{
					replacementWordsReplace.push_back(words);
					// Debating whether or not I should have multiple recommendations by putting this outside the loop, but sticking to one for now
				}
				words.erase(j, 1);
			}
			words.insert(j, temp2);
		}
		return replacementWordsReplace;
	}

	void readInput()
	{
		string input;
		int length;
		cout << "Enter the message you'd like to spell check: ";
		getline(cin, input);
		input += ' ';
		string inputWords = "";
		vector<string> mispeltWordsVec;
		vector<string> inputWordsVec;
		cout << endl;
		int x = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] != ' ')
			{
				inputWords += tolower(input[i]);
			}
			else if (input[i] == ' ')
			{
				inputWordsVec.insert(inputWordsVec.begin() + x, inputWords);
				inputWords = "";
				x++;
			}

		}
		//cout << inputWordsVec << endl;
		for (int i = 0; i < inputWordsVec.size(); i++)
		{
			if (dictionary.find(inputWordsVec.at(i)) != dictionary.end())
			{
				cout << "Word " << i + 1 << " (" << inputWordsVec.at(i) << ")" << " is Ok!\n~\n";
			}
			else
			{
				cout << "	Potential corrections for word " << i + 1 << " (" << inputWordsVec.at(i) << ")";
				//mispeltWordsVec.push_back(inputWordsVec.at(i)); //originally tried to use a vector, ran into issues with iteration
				vector<string> swapCorrectionWordList = swapChar(inputWordsVec.at(i));
				vector<string> delCorrectionWordList = delChar(inputWordsVec.at(i));
				vector<string> insCorrectionWordList = insChar(inputWordsVec.at(i));
				vector<string> replaceCorrectionWordList = replaceChar(inputWordsVec.at(i));
				if (!swapCorrectionWordList.empty())
				{
					cout << "\nReplacing characters, we have these corrections: ";
					for (auto correctionWord : replaceCorrectionWordList)
					{
						cout << correctionWord << " ";
					}
				}
				if (!insCorrectionWordList.empty())
				{
					cout << "\nInserting characters, we have these corrections: ";
					for (auto correctionWord : insCorrectionWordList)
					{
						cout << correctionWord << " ";
					}
				}
				if (!delCorrectionWordList.empty())
				{
					cout << "\nDeleting characters, we have these corrections: ";
					for (auto correctionWord : delCorrectionWordList)
					{
						cout << correctionWord << " ";
					}
				}
				if (!swapCorrectionWordList.empty())
				{
					cout << "\nSwapping adjacent characters, we have these corrections: ";
					for (auto correctionWord : swapCorrectionWordList)
					{
						cout << correctionWord << " ";
					}
				}
				cout << endl << '~' << endl;

			}
		}
		//cout << inputWordsVec.size() << endl;
		//string word;
	}

	void readDictionary(string filename)
	{
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			string word = "";
			//string temp = "";
			while (fin >> word)
			{
				for (int i = 0; i < word.length(); i++)
				{
					word[i] = tolower(word[i]);
				}
				dictionary.emplace(word, word);
				//cout << word << endl;
				//temp = "";

			}
		}
		else if (!fin.is_open())
		{
			cout << "There was a problem opening your file: " << filename << endl;
		}
		//print_map(dictionary);
	}
};

int main()
{
	SpellCheck spellchecker;
	string testFile = "dictionary.txt";
	spellchecker.readDictionary(testFile);
	spellchecker.readInput();


	auto it = spellchecker.dictionary.end(0);
	return 0;
}