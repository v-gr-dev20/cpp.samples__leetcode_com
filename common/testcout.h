#pragma once

#include <iostream>
#include <sstream>
#include <regex>

namespace MyTest {

class CTestCout : public std::ostringstream
{
public:
	CTestCout( std::ostream& _oStream );
	CTestCout( std::ostream&& _oStream );
	virtual ~CTestCout()
	{
		const std::string gtestLeftBar = "\033[0;32m[   cout<< ]\033[0;0m ";
		const std::string& thisStr = str();
		if( !thisStr.empty() ) {
			oStream << gtestLeftBar << std::regex_replace( thisStr.substr( 0, thisStr.length() - 1 ), std::regex("([\r\n])"), "$1" + gtestLeftBar );
			oStream << *crbegin( thisStr );
			if( '\n' != *crbegin( thisStr ) ) {
				oStream << '\n';
			}
		}
	}
private:
	CTestCout() = delete;
	std::ostream&& oStream;
};

inline CTestCout::CTestCout( std::ostream& _oStream ) : oStream( std::forward<std::ostream>( _oStream ) )
{
}

inline CTestCout::CTestCout( std::ostream&& _oStream ) : oStream( std::forward<std::ostream>( _oStream ) )
{
}

} // namespace MyTest