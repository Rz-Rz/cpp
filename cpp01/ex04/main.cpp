// main.cpp
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string replaceAll(const std::string &str, const std::string &from, const std::string &to)
{
	size_t start_pos = 0;
	size_t last_pos = 0;
	std::string result;

	while (true)
	{
		start_pos = str.find(from, start_pos);
		if (start_pos == std::string::npos)
		{
			break;
		}
		result.append(str, last_pos, start_pos - last_pos);
		result.append(to);
		start_pos += from.length();
		last_pos = start_pos;
	}
	result.append(str, last_pos, std::string::npos);
	return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << infile.rdbuf();
    infile.close();

    std::string content = buffer.str();
    std::string replaced = replaceAll(content, s1, s2);

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error creating output file: " << outFilename << std::endl;
        return 1;
    }

    outfile << replaced;
    outfile.close();

    return 0;
}
