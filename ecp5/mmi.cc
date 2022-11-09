#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include "mmi.h" 

// TODO: handle multiple ram definitions in one file
void mmi::write_json(std::string filename) {
	std::ofstream fout(filename);
	fout << "{" << std::endl;
	fout << "    \"name\": \"" << name << "\"," << std::endl;
	fout << "    \"swizzle\": \"" << swizzle << "\"," << std::endl;
	fout << "    \"mapping\": {" << std::endl;
	unsigned int i = 0;
	for (auto& key : mapping) {
	fout << "        \"" << key.first << "\" : \"" << key.second;
	i++;
	if (i != mapping.size())
		fout << "\"," << std::endl;
	else
		fout << "\"" << std::endl;
	}
	fout << "    }" << std::endl;
	fout << "}" << std::endl;
}

// name is instname.mem.[row].[column]
// columns are across the swizzle
// rows are stacked to create a deeper ram if large enough

int mmi::row(const std::string& name) 
{
	std::vector<int> dots;
	for(unsigned int i = 0; i < name.length(); i++) {
		if (name[i] == '.')
			dots.push_back(i);
	}
	int second_last = dots.size() - 2;
	return atoi(name.substr(dots[second_last] + 1, name.length() - dots[second_last] - dots.back() - 1).c_str());
}

int mmi::column(const std::string& name)
{
	std::vector<int> dots;
	for(unsigned int i = 0; i < name.length(); i++) {
		if (name[i] == '.')
			dots.push_back(i);
	}
	return atoi(name.substr(dots.back() + 1, name.length()- dots.back() - 1).c_str());
}

std::string mmi::instname(const std::string& name)
{
	unsigned int i = 0;
	for(; i < name.length(); i++) {
		if (name[i] == '.')
			break;
	}
	return name.substr(0, i);
}
