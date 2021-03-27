#pragma once

// Bloom Precompiled Header (bmpch)

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Bloom/Core/Log.hpp"

#ifdef BM_PLATFORM_WINDOWS
	#include <Windows.h>
#endif