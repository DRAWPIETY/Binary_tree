#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cstddef>
#include <cctype>
#include <ctime>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

enum Error_code
{
	success, fail, range_error, underflow, overflow, fatal, not_present, duplicate_error, entry_inserted, entry_found, internal_error
};

