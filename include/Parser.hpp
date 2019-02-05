/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Parser.hpp
 */

#ifndef SRC_PARSER_HPP_
#define SRC_PARSER_HPP_

#include <string>
#include <fstream>
#include <map>
#include "Circuit.hpp"

namespace nts {

	class Parser {
		protected:
			std::ifstream ntsFile;
			std::map<std::string, IComponent *> components;

		private:
			void performChipsetParsing(Circuit *circuit);
			void performLinksParsing(Circuit *circuit);
			void performArgumentsParsing(int nbArgs, char **arguments);


			void skipCommentsAndEmptyLines(std::string &line);
			std::vector<std::string> getLineContent(std::string &line, const char &delimiter);

			void parseComponent(std::string &line, Circuit *circuit);
			void parseLink(std::string &line, Circuit *circuit);
			void parseArgument(std::string argument);

			size_t getComponentPin(const std::string &component);

			void verifyInputInitialisation();
			void verifyOutputLinkage();

		public:
				Parser(const std::string &fileName);
				virtual ~Parser();
				Circuit *processParsing(int nbArgs, char **arguments);
};

} /* namespace nts */

#endif /* SRC_PARSER_HPP_ */
