#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <type_traits>
#include <memory>

// Интерфейс тестового примера
///////////////////////////////////////////////////////////////////////////////

struct ISample {
	virtual ~ISample() {}
	// Наименование примера
	virtual std::string Name() const = 0;
	// Выполняет ввод данных примера
	virtual void Input( std::istream& is = std::cin, std::ostream& os = std::cout ) = 0;
	// Запускает выполнение примера
	virtual void Run() = 0;
	// Выдает вычисленный ранее и сохраненный результат
	virtual void Report( std::vector<std::string>& ) const = 0;
	// Очищает экземпляр примера для повторного использования
	virtual void Clean() = 0;
};

// Базовый тестовый пример, собирает все тестовые примеры в singleton-список
///////////////////////////////////////////////////////////////////////////////

class CBaseSample : public ISample {
public:
	explicit CBaseSample( const std::string& _name );
	virtual ~CBaseSample();

	virtual std::string Name() const { return name; }
	virtual void Clean() override {}

	// Выполняет ввод данных примера
	using ISample::Input;
	void Input( std::istream&& is, std::ostream&& os ) { Input( is, os ); }
	void Input( std::istream& is, std::ostream&& os ) { Input( is, os ); }
	void Input( std::istream&& is, std::ostream& os = *CBaseSample::GetOutputStream() ) { Input( is, os ); }

	// Исполнение примера,
	//	- с вводом исходных данных,
	//	- с выводом результата,
	//	- с очисткой.
	void Run( std::istream& iStream, std::ostream& oStream );

	// Исполнение примера,
	//	- предполагающее предварительный ввод исходных данных,
	//	- с выводом результата,
	//	- с очисткой.
	void Run( std::ostream& os );
	void Run( std::ostream&& os ) { Run( os ); }

	// Исполнение примера,
	//	- предполагающее предварительный ввод исходных данных,
	//	- с сохранением результата.
	using ISample::Run;

	// Выдача результата
	using ISample::Report;
	std::vector<std::string> Report() const;

	// Доступ к списку примеров
	static const std::list<CBaseSample*>& AllSamples();
	// Вывод по-умолчанию
	static std::shared_ptr<std::ostream> GetOutputStream();
protected:
	// наименование примера
	std::string name;
private:
	// список всех примеров (с механизмом доступа для контроля порядка инициализации)
	static
	struct SamplesHolder {
		bool IsReady;
		std::list<CBaseSample*> Samples;
		// флаг готовности поднимается в конце после инициализации
		SamplesHolder() { IsReady = true; }
	} allSamplesHolder;
};

// Возвращает ссылку на код тестового примера
CBaseSample& GetSample( const std::string& );

// Запускает тестовый пример с параметрами
// Возвращает и выводит строки результата (отчет)
void Run( CBaseSample& sample, const std::vector<std::string>& inputLines, std::vector<std::string>& reportLines,
	std::ostream& wout = *CBaseSample::GetOutputStream() );
inline void Run( CBaseSample& sample, const std::vector<std::string>& inputLines, std::vector<std::string>& reportLines,
	std::ostream&& wout )
{
	Run( sample, inputLines, reportLines, wout );
}
std::vector<std::string> Run( CBaseSample& sample, const std::vector<std::string>& inputLines = {},
	std::ostream& wout = *CBaseSample::GetOutputStream() );
inline std::vector<std::string> Run( CBaseSample& sample, const std::vector<std::string>& inputLines,
	std::ostream&& wout )
{
	return Run( sample, inputLines, wout );
}
