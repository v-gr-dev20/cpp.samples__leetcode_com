#include "pch.h"
#include "gtest/gtest.h"

int main( int argc, char** argv )
{
	std::locale::global( std::locale( "ru_RU.UTF-8" ) );
	std::cout.imbue( std::locale( "ru_RU.UTF-8" ) );
	testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
