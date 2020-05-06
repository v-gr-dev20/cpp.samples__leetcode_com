#include "pch.h"
#include "BaseSample.h"
#include "output.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

CBaseSample& GetSample( const std::string& sampleName )
{
	const auto& allSamples = CBaseSample::AllSamples();
	auto sample = *find_if( allSamples.begin(), allSamples.end(), [&]( auto& item ) { return item->Name() == sampleName; } );
	assert( sample != nullptr );
	return *sample;
}

void Run( CBaseSample& sample, const std::vector<std::string>& inputLines, std::vector<std::string>& reportLines,
	std::ostream& wout )
{
	const std::string separatorLine( "================================================================================" );
	wout << separatorLine << std::endl;
	wout << ( "Sample: " + sample.Name() ) << std::endl;
	std::stringstream joinedInputLines;
	if( ! inputLines.empty() ) {
		std::copy( inputLines.cbegin(), inputLines.cend() - 1, std::ostream_iterator<std::string>( joinedInputLines, "\n" ) );
		joinedInputLines << *inputLines.crbegin();
	}
	std::stringstream forwardOutput;
	sample.Input( joinedInputLines, forwardOutput );
	const auto& forwardOutputStr = forwardOutput.str();
	if( !forwardOutputStr.empty() ) {
		wout << forwardOutputStr;
		if( '\n' != *forwardOutputStr.crbegin() ) {
			wout << '\n';
		}
	}
	std::copy( inputLines.cbegin(), inputLines.cend(), std::ostream_iterator<std::string>( wout, "\n" ) );
	sample.Run();
	reportLines.clear();
	sample.Report( reportLines );
	std::copy( reportLines.cbegin(), reportLines.cend(), std::ostream_iterator<std::string>( wout, "\n" ) );
	sample.Clean();
}

std::vector<std::string> Run( CBaseSample& sample, const std::vector<std::string>& inputLines, std::ostream& wout )
{
	std::vector<std::string> reportLines;
	Run( sample, inputLines, reportLines, std::forward<std::ostream>( wout ) );
	return reportLines;
}

CBaseSample::SamplesHolder CBaseSample::allSamplesHolder;

CBaseSample::CBaseSample( const std::string& _name )
	: name( _name )
{
	// Контроль первоочередности инициализации списка примеров (до любого модуля примера),
	//	сбой порядка возможен при неверном порядке статической компоновки
	assert( allSamplesHolder.IsReady );
	allSamplesHolder.Samples.push_front( this );
}

CBaseSample::~CBaseSample()
{
	allSamplesHolder.Samples.remove( this );
}

const std::list<CBaseSample*>& CBaseSample::AllSamples()
{
	return allSamplesHolder.Samples;
}

std::shared_ptr<std::ostream> CBaseSample::GetOutputStream()
{
	return ::GetOutputStream();
}

void CBaseSample::Run( std::istream& iStream, std::ostream& oStream )
{
	Clean();
	Input( iStream, oStream );
	Run( oStream );
}

void CBaseSample::Run( std::ostream& oStream )
{
	Run();
	std::vector<std::string> reportLines;
	Report( reportLines );
	std::copy( reportLines.cbegin(), reportLines.cend(), std::ostream_iterator<std::string>( oStream, "\n" ) );
}

std::vector<std::string> CBaseSample::Report() const
{
	std::vector<std::string> reportLines;
	Report( reportLines );
	return reportLines;
}
