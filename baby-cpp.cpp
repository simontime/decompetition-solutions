#include <cstring>
#include <iostream>
#include <string>
#include <vector>

bool check(const std::string &hand, const std::string &word)
{
	std::vector<int> occurrences(26, 0);
	
	for (char letter : hand)
	{
		if (isalpha(letter) == 0)
			return false;
		
		occurrences[toupper(letter) - 'A']++;
	}
	
	for (char letter : word)
	{
		if (isalpha(letter) == 0)
			return false;
		
		if (--occurrences[toupper(letter) - 'A'] < 0)
			return false;
	}
	
	return true;
}

int score(const std::string &word)
{
	int score = 0;
	
	std::vector<int> scores = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 5, 4, 8, 3, 10 };
	
	for (char letter : word)
		score += scores[toupper(letter) - 'A'];
	
	return score;
}

int main(int argc, char **argv)
{
	const char *str;
	int         points;
	
	if (argc != 3)
	{
		std::cerr << "USAGE: ./clabbers [hand] [word]" << std::endl;
		return 1;
	}
	else
	{
		std::string hand = argv[1];
		std::string word = argv[2];
		
		if (check(hand, word))
		{
			points = score(word);
			str = (points == 1) ? "" : "s";
			std::cout << points << " point" << str << "." << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Invalid." << std::endl;
			return 2;
		}
	}
}
