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
#include "Circuit.hpp"

namespace nts {

	class Parser {
		protected:
			std::ifstream ntsFile;

		private:
			void performChipsetParsing(Circuit *circuit);
			void performLinksParsing(Circuit *circuit);

			void skipCommentsAndEmptyLines(std::string &line);
			std::vector<std::string> getLineContent(std::string &line);

			void parseComponent(std::string &line, Circuit *circuit);



		public:
				Parser(const std::string &fileName);
				virtual ~Parser();
				Circuit *processParsing();
};

} /* namespace nts */

#endif /* SRC_PARSER_HPP_ */
