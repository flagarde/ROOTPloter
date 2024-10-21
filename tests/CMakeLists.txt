find_package(ROOT 6.24 CONFIG REQUIRED COMPONENTS Gpad Gui)
add_executable(ROOTLinked.test ROOTLinked.test.cpp)
target_link_libraries(ROOTLinked.test PRIVATE ROOTPloter::ROOTPloter ROOT::Gpad ROOT::Gui)

add_executable(ROOTPloter.test ROOTPloter.test.cpp)
target_link_libraries(ROOTPloter.test PRIVATE ROOTPloter::ROOTPloter ROOT::Gpad ROOT::Gui)