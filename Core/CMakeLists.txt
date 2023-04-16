add_executable (core "Core.cpp" "Core.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)
FetchContent_Declare(
  onetbb
  GIT_REPOSITORY https://github.com/oneapi-src/oneTBB
  GIT_TAG a00cc3b  # 2021.9.0
)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        605a34765aa5d5ecbf476b4598a862ada971b0cc # v3.0.1
)
FetchContent_MakeAvailable(onetbb Catch2)

find_package(TBB)
target_link_libraries(core TBB::tbb)
