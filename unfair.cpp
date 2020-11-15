#include <string>
#include <tuple>
#include <iostream>
#include <cstdint>

const std::string UNFAIR[] = {"LREOT", "HQGNU", "YIVXC", "DBKFM", "PZWAS"};

std::tuple<uint64_t, uint64_t> find(char ch)
{
	uint64_t i, pos;
	
	for (i = 0; ;)
	{
		if (i < 5)
		{
			pos = UNFAIR[i].find(ch);
			
			if (pos != -1)
				return std::make_tuple(i, pos);
			
			i++;
		}
		else
		{
			std::cerr << "Chaos and corruption!" << std::endl;
			exit(1);
		}
	}
}

std::string clean(const std::string &str)
{
	std::string out;
	
	for (uint64_t i = 0; i < str.size(); i++)
	{
		if (str[i] == 'j' || str[i] == 'J')
		{
			out += 'I';
		}
		else
		{
			if (isalpha(str[i]))
				out += toupper(str[i]);
		}
	}
	
	if (out.size() % 2 == 1)
	  out += 'X';
	
	return out;
}

std::string crypt(const std::string &str)
{
	std::string cleaned = clean(str);
	std::string out;
	
	for (int i = 0; i < cleaned.size(); i += 2)
	{
		auto c1       = find(cleaned[i]);
		auto &&which1 = std::get<0>((std::tuple<uint64_t, uint64_t> &&)c1);
		auto &&pos1   = std::get<1>((std::tuple<uint64_t, uint64_t> &&)c1);
		
		auto c2       = find(cleaned[i + 1]);
		auto &&which2 = std::get<0>((std::tuple<uint64_t, uint64_t> &&)c2);
		auto &&pos2   = std::get<1>((std::tuple<uint64_t, uint64_t> &&)c2);
		
		if (which1 == which2)
		{
			pos1 = (pos1 + 1) % 5;
			pos2 = (pos2 + 1) % 5;
		}
		else if (pos1 == pos2)
		{
			which1 = (which1 + 1) % 5;
			which2 = (which2 + 1) % 5;
		}
		else
		{
			std::swap(pos1, pos2);
		}
		
		out += UNFAIR[which1][pos1];
		out += UNFAIR[which2][pos2];
	}
	
	return out;
}

int main(int argc, char** argv)
{	
	if (argc != 2)
	{
		std::cerr << "USAGE: ./unfair [text]\n";
		exit(1);
	}
		
	std::cout << crypt(argv[1]) << std::endl;
	
	return 0;
}
