message("Build ymal-cpp 3pp")

include(ExternalProject)

set(YAML_DIR ${FRAM_3PP_PATH}/yaml-cpp)

set(YAML_CMAKE_ARGS)
list(APPEND YAML_CMAKE_ARGS "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}")
list(APPEND YAML_CMAKE_ARGS "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}")
list(APPEND YAML_CMAKE_ARGS "-DLIBRARY_OUTPUT_PATH=${LIBRARY_OUTPUT_PATH}")
list(APPEND YAML_CMAKE_ARGS "-DEXECUTABLE_OUTPUT_PATH=${EXECUTABLE_OUTPUT_PATH}")

list(APPEND YAML_CMAKE_ARGS "-DYAML_CPP_BUILD_TESTS=OFF")
list(APPEND YAML_CMAKE_ARGS "-DYAML_CPP_BUILD_TOOLS=OFF")
list(APPEND YAML_CMAKE_ARGS "-DYAML_CPP_BUILD_CONTRIB=OFF")
list(APPEND YAML_CMAKE_ARGS "-DBUILD_SHARED_LIBS=ON")

ExternalProject_Add(yaml-cpp
                    PREFIX ${FRAM_ROOT_PATH}/build
                    SOURCE_DIR ${YAML_DIR}
                    CONFIGURE_COMMAND ${CMAKE} ${YAML_CMAKE_ARGS} ${YAML_DIR}
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND ""
                    )

set(3PP_YAML_HRD "${YAML_DIR}/include") 
set(3PP_YAML_LIBS libyaml-cpp.so)

message("Build ymal-cpp 3pp done.")
