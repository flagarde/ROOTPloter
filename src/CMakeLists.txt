find_package(ROOT 6.24 CONFIG REQUIRED COMPONENTS Hist)

add_library(ROOTPloter ROOTPloter.cpp)

if(USE_SPDLOG)
  include(FetchContent)
  FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.x GIT_SHALLOW TRUE)
  FetchContent_MakeAvailable(spdlog)
  target_compile_definitions(ROOTPloter PRIVATE USE_SPDLOG)
  target_link_libraries(ROOTPloter PRIVATE spdlog::spdlog)
endif()

target_include_directories(ROOTPloter PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(ROOTPloter PRIVATE ROOT::Hist)

add_library(ROOTPloter::ROOTPloter ALIAS ROOTPloter)