include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.15.0
)
FetchContent_MakeAvailable(googletest)
list(APPEND CMAKE_MODULE_PATH ${googletest_SOURCE_DIR}/extras)
