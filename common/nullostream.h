#pragma once
#include <iostream>

namespace MyTools {

template <class CharT>
class null_streambuf : public std::basic_streambuf<CharT> {
public:
	using Base = std::basic_streambuf<CharT>;
	using char_type = typename Base::char_type;
	using int_type = typename Base::int_type;
	using traits_type = typename Base::traits_type;
protected:
	virtual int_type overflow( int_type c ) override { return traits_type::not_eof( c ); }
};

template<class CharT>
class stream_with_null_buffer {
private:
	null_streambuf<CharT> buffer;
public:
	null_streambuf<CharT>* GetBuffer() { return &buffer; }
};

template <class CharT>
class null_ostream : public std::basic_ostream<CharT>, private virtual stream_with_null_buffer<CharT> {
public:
	using Base = std::basic_streambuf<CharT>;
	using char_type = typename Base::char_type;
	using int_type = typename Base::int_type;
	using traits_type = typename Base::traits_type;
	null_ostream()
		: stream_with_null_buffer<CharT>(), std::basic_ostream<CharT>( stream_with_null_buffer<CharT>::GetBuffer() )
	{
	}
};

using nullostream = null_ostream<char>;

} // namespace MyTools