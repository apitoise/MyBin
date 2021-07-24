#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>

std::string	upperName(std::string className) {
	std::string	ret = className;
	for (int i = 0; i < className.size(); i++) {
		ret[i] = std::toupper(className[i]);
	}
	return (ret);
}

std::string	getTimeOfDay(void) {
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);
    return (buffer);
}

void	setHeader(std::ostream &file, std::string className, std::string file_type) {
	file << "/* ************************************************************************** */\n";
	file << "/*                                                                            */\n";
	file << "/*                                                        :::      ::::::::   */\n";
	file << "/*   " << className << file_type;
	for (int i = className.size() + 4; i < 51; i++)
		file << " ";
	file << ":+:      :+:    :+:   */\n";
	file << "/*                                                    +:+ +:+         +:+     */\n";
	file << "/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */\n";
	file << "/*                                                +#+#+#+#+#+   +#+           */\n";
	file << "/*   Created: " << getTimeOfDay();
	file << " by apitoise          #+#    #+#             */\n";
	file << "/*   Updated: " << getTimeOfDay();
	file << " by apitoise         ###   ########.fr       */\n";
	file << "/*                                                                            */\n";
	file << "/* ************************************************************************** */\n";

}

void	hppCreator(std::string className) {
	std::ofstream	file(className + ".hpp");

	setHeader(file, className, ".hpp");
	file << std::endl;
	file << "#ifndef " << upperName(className) << "_HPP\n";
	file << "# define " << upperName(className) << "_HPP\n";
	file << std::endl;
	file << "# include <iostream>\n";
	file << std::endl;
	file << "class	" << className << std::endl;
	file << "{\n";
	file << "	public:\n\n";
	file << "		" << className << "(void);\n";
	file << "		" << className << "(const " << className << " &other);\n";
	file << "		" << "~" << className << "(void);\n";
	file << "		" << className << "	&operator=(const " << className << " &other);\n";
	file << "};\n";
	file << std::endl;
	file << "#endif\n";
	file.close();
}

void	cppCreator(std::string className) {

	std::ofstream	file(className + ".cpp");

	setHeader(file, className, ".cpp");
	file << std::endl;
	file << "#include \"" << className << ".hpp\"\n";
	file << std::endl;
	file << className << "::" << className << "(void) {}\n";
	file << std::endl;
	file << className << "::" << className << "(const " << className << " &other) {}\n";
	file << std::endl;
	file << className << "::" << "~" << className << "(void) {}\n";
	file << std::endl;
	file << className << "	&" << className << "::operator=(const " << className << "&other) {\n";
	file << "	return (*this);\n";
	file << "}\n";
}

int	main(int ac, char **av) {
	if (ac != 2)
		std::cout << "This need only one parameter: [ClassName].\n";
	else {
		hppCreator(av[1]);
		cppCreator(av[1]);
	}
	return (0);
}
