cmake_minimum_required (VERSION 3.0.0)

file( GLOB Sources "*.cpp" )

add_executable( datafed-repo ${Sources} )
add_dependencies( datafed-repo common )
target_link_libraries( datafed-repo common -lprotobuf -lpthread -lzmq -lboost_system -lboost_filesystem -lboost_program_options )

target_include_directories( datafed-repo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
