// Core.cpp : Defines the entry point for the application.

#include "Core.h"

#include <tbb/tbb.h>

#include <iostream>
#include <vector>
#include <chrono>

auto DummyToyFunction( const int arg )
{
	// Input array of numbers
	const auto size = arg;
	auto nums = std::vector< int >();
	for ( size_t i = 0; i < size; i++ )
	{
		nums.push_back( i );
	}

	auto start1 = std::chrono::high_resolution_clock::now();
	tbb::parallel_for( 0, size, [ & ]( int i )
	{
		nums[ i ] = nums[ i ] * nums[ i ]; // Square each element
	} );
	auto stop1 = std::chrono::high_resolution_clock::now();
	auto duration1 = duration_cast< std::chrono::microseconds >( stop1 - start1 );

	auto start2 = std::chrono::high_resolution_clock::now();
	for ( size_t i = 0; i < size; i++ )
	{
		nums[ i ] = nums[ i ] * nums[ i ]; // Square each element
	}
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = duration_cast< std::chrono::microseconds >( stop2 - start2 );

	auto duration_time1 = std::chrono::duration_cast< std::chrono::nanoseconds >( stop1 - start1 ).count();
	auto duration_time2 = std::chrono::duration_cast< std::chrono::nanoseconds >( stop2 - start2 ).count();
	double speedup_factor = static_cast< double >( duration_time2 ) / duration_time1;
	std::cout << "Time taken by TBB " << duration1.count() << " microseconds" << std::endl;
	std::cout << "Time taken by Normal " << duration2.count() << " microseconds" << std::endl;
	std::cout << "Speedup factor is (greater than 1 indicates that TBB is faster than Normal) " << speedup_factor << std::endl;
}

int main( int argc, char* argv[] )
{
	tbb::flow::graph g;
	tbb::flow::function_node< int, int > n( g, tbb::flow::unlimited, []( int v ) -> int
	{
		std::cout << "n -> " << v << std::endl;
	return v;
	} );
	tbb::flow::function_node< int, int > m( g, tbb::flow::unlimited, []( int v ) -> int
	{
	std::cout << "m -> " << v << std::endl;;
	return v;
	} );
	tbb::flow::make_edge( n, m );
	for ( size_t i = 0; i < 100; i++ )
	{
		n.try_put( i );
	}
	g.wait_for_all();

	return 0;
}
