//
// Created by robgrzel on 01.06.17.
//

#ifndef TEMPLATE_UTILS_H
#define TEMPLATE_UTILS_H


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <valarray>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <limits>
#include <algorithm>

//#define DEBUG

#define PRINTF( format, ... ) fprintf (stdout, format, ##__VA_ARGS__)

#ifdef DEBUG
	#define DPRINTF( format, ... ) fprintf (stdout, format, ##__VA_ARGS__)
#else
	#define DPRINTF( format, ... )
#endif

/*
 * DECLARATIONS
 */

typedef std::numeric_limits<double> maxdbl;

template<class T>
int obj2txt(std::string fname, const T &obj) {
	
	std::ofstream file(fname);
	file.precision(maxdbl::max_digits10);
	file << obj;
	file.close();
	
	return 0;
}

template<class T>
int txt2obj(std::string fname, T &obj) {
	
	std::ifstream file(fname);
	file.precision(maxdbl::max_digits10);
	file >> obj;
	file.close();
	
	return 0;
}


template <typename T> const char* BytesToSize( T Bytes );

template <typename T> int malloc1d( T** array, int n );

template <typename T> int malloc1d_p( T*** array, int n );

template <typename T> int alloc_1d_in_1dp( T*** array, T* row, int n, int m );

template <typename T> int malloc2d_( T*** array, int n, int m );

template <typename T> int malloc2d( T*** array, int n, int m );

template <typename T> int free1d( T** array );

template <typename T> int free2d( T*** array );

template <typename T>
void arr2file( const char* pathFile, int size, T* x );

template <typename T>
void var2file( const char* pathFile, std::valarray<T> a );


template <typename T>
void vec2file( std::string pathFile, std::vector<T> v );

template <typename T>
void mat2file( const char* pathFile, int N, int M, T** x );


template <typename T> std::vector<T> read2vec( const char* pathFile, size_t N );

/*
 * DEFINITIONS
 */

template <typename T>
const char* BytesToSize( T Bytes ) {

	DPRINTF( "BytesToSize : Bytes=%d,%f\n", Bytes, float(Bytes) );

	float tb = 1099511627776;
	float gb = 1073741824;
	float mb = 1048576;
	float kb = 1024;


	char* returnSize;


	if (Bytes >= tb) {
		sprintf( returnSize, "%.2f TB", Bytes / tb );
	} else if (Bytes >= gb && Bytes < tb) {
		sprintf( returnSize, "%.2f GB", Bytes / gb );
	} else if (Bytes >= mb && Bytes < gb) {
		sprintf( returnSize, "%.2f MB", Bytes / mb );
	} else if (Bytes >= kb && Bytes < mb) {
		sprintf( returnSize, "%.2f KB", Bytes / kb );
	} else if (Bytes < kb) {
		sprintf( returnSize, "%.2f Bytes", Bytes );
	} else {
		sprintf( returnSize, "%.2f Bytes", Bytes );
	}

	DPRINTF( "BytesToSize e\n" );

	return returnSize;
}


template <typename T>
int malloc1d( T** array, int n ) {

	/* allocate the row pointers into the memory */
	(*array) = ( T* ) malloc( n * sizeof( T ) );
	if (!(*array)) {
		return -1;
	}

	return 0;
}

template <typename T>
int malloc1d_p( T*** array, int n ) {
	(*array) = ( T** ) malloc( n * sizeof( T* ) );
	if (!(*array)) {
		return -1;
	}
	return 0;
}

template <typename T>
int alloc_1d_in_1dp( T*** array, T* row, int n, int m ) {
	/* set up the pointers into the contiguous memory */
	for ( int i = 0; i < n; i++ ) {
		(*array)[i] = &(row[i * m]);
	}
	return 0;
}

template <typename T>
int malloc2d_( T*** array, int n, int m ) {

	int o = 0;
	/* allocate the n*m contiguous items */
	T* p;

	o = malloc1d( &p, n * m );
	if (o) return -1;

	/* allocate the row pointers into the memory */
	o = malloc1d_p( array, n );

	if (o) {
		free( p );
		return -1;
	}

	/* set up the pointers into the contiguous memory */
	alloc_1d_in_1dp( array, p, n, m );

	return 0;
}

template <typename T>
int malloc2d( T*** array, int n, int m ) {

	int o = 0;
	/* allocate the n*m contiguous items */
	T* p;

	malloc1d( &p, n * m );
	if (!p) return -1;

	/* allocate the row pointers into the memory */
	(*array) = ( T** ) malloc( n * sizeof( T* ) );
	if (!(*array)) {
		free( p );
		return -1;
	}

	/* set up the pointers into the contiguous memory */
	for ( int i = 0; i < n; i++ ) {
		(*array)[i] = &(p[i * m]);
	}

	return 0;
}

template <typename T>
int free1d( T** array ) {
	/* free the memory - the first element of the array is at the start */
	//free( &((*array)[0]) );

	/* free the pointers into the memory */
	free( *array );

	return 0;
}

template <typename T>
int free2d( T*** array ) {
	/* free the memory - the first element of the array is at the start */
	free( &((*array)[0][0]) );

	/* free the pointers into the memory */
	free( *array );

	return 0;
}

template <typename T>
void arr2file( const char* pathFile, int size, T* x ) {
	std::ofstream myfile( pathFile );
	if (myfile.is_open()) {
		for ( int count = 0; count < size - 1; count++ ) {
			myfile << x[count] << "\n";
		}
		myfile << x[size - 1];

		myfile.close();
	}
}

template <typename T>
void var2file( const char* pathFile, std::valarray<T> a ) {

	std::vector<T> v( a.size() );

	v.assign( std::begin( a ), std::end( a ) );

	std::ofstream            output_file( pathFile );
	std::ostream_iterator<T> output_iterator( output_file, "\n" );
	std::copy( v.begin(), v.end(), output_iterator );
}


template <typename T>
void vec2file( std::string pathFile, std::vector<T> v ) {
	std::ofstream            output_file( pathFile );
	std::ostream_iterator<T> output_iterator( output_file, "\n" );
	std::copy( v.begin(), v.end(), output_iterator );
}

template <typename T>
void mat2file( const char* pathFile, int N, int M, T** x ) {
	std::ofstream myfile( pathFile );
	if (myfile.is_open()) {
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < M - 1; j++ ) {
				myfile << x[i][j] << " ";
			}
			myfile << x[i][M - 1] << "\n";
		}
		myfile.close();
	}
}

size_t file_lines_count( const char* pathFile ) ;

size_t file_line_count( const char* pathFile, const char delim = ' ' );

template <typename T>
void printv( const std::vector<T>& vec, const char * f, bool raw = true ) {

	size_t N = vec.size();

	if (raw) {
		printf("####################\n");
		for ( int i = 0; i < N; i++ ) {
			printf( f, vec[i] );
		}
	}
}

template <typename T> std::vector<T> read2vec( const char* pathFile, char delim = ' ' ) {
	std::vector<T> vec( 1, -1 );

	std::fstream fs( pathFile, std::ios::in );
	if (!fs) {
		std::cout << "Error opening file\n";
		return vec;
	}

	size_t N = file_lines_count( pathFile );
	size_t n = file_line_count( pathFile, delim );

	vec.resize( N );

	T   number;
	int i    = 0;
	while ( true ) {
		fs >> number;
		if (fs.eof()) break;
		vec[i] = number;
		i++;
	}

	fs.close();
	return vec;
}

template <typename T> std::vector<T> read2vec( const char* pathFile, size_t N ) {
	std::vector<T> vec( 1, -1 );

	std::fstream fs( pathFile, std::ios::in );
	if (!fs) {
		std::cout << "Error opening file\n";
		return vec;
	}

	vec.resize( N );

	T         number;
	for ( int i = 0; i < N; i++ ) {
		fs >> number;
		vec[i] = number;
	}

	fs.close();
	return vec;
}

template <typename T>
void read2vec( const char* pathFile, size_t N, std::vector<T>& vec, char delim = ' ' ) {

	std::fstream fs( pathFile, std::ios::in );
	if (!fs) {
		std::cout << "Error opening file\n";
		return;
	}

	size_t n    = file_line_count( pathFile, delim );

	vec.resize( n, N );

	if (vec.size() < N) {
		vec.resize( N );
	}

	T         number;
	for ( int i = 0; i < N; i++ ) {
		fs >> number;
		vec[i] = number;
	}

	fs.close();
	return;
}


template <typename T> void read2arr( const char* pathFile, size_t N, T* arr ) {

	std::fstream fs( pathFile, std::ios::in );
	if (!fs) {
		std::cout << "Error opening file\n";
		return;
	}

	T         number;
	for ( int i = 0; i < N; i++ ) {
		fs >> number;
		arr[i] = number;
	}

	fs.close();

}

template <typename T> std::vector<T> zeros( size_t N ) {
	return std::vector<T>( N, 0 );
}


template <typename T> std::vector<T> ones( size_t N ) {
	return std::vector<T>( N, 1 );
}


template <typename T> std::vector<T> _ones( size_t N ) {
	return std::vector<T>( N, -1 );
}


#endif //TEMPLATE_UTILS_H

