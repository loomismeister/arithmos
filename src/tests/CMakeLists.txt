project(Arithmos_test)

enable_testing()


add_executable(${PROJECT_NAME}
  main.cc)
target_link_libraries(${PROJECT_NAME} Catch)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

add_custom_command(TARGET Arithmos_test
  POST_BUILD
  COMMAND ./${PROJECT_NAME} -sr compact
)
