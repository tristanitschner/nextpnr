struct mmi {
	std::string name;
	std::string swizzle;
	std::map<std::string, std::string> mapping; // maps component to bram
	void write_json(std::string filename);

	static int row(const std::string& hiername);
	static int column(const std::string& hiername);
	static std::string instname(const std::string& hiername);
};
