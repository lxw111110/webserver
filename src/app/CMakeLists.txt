aux_source_directory(. APP_DSRC)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main ${APP_DSRC})
target_link_libraries(main hello)
target_link_libraries(main ${CMAKE_DL_LIBS})
