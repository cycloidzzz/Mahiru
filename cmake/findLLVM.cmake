find_package(LLVM REQUIRED CONFIG)

if(LLVM_FOUND)
    message(STATUS "Found LLVM: ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
    message(STATUS "LLVM library: ${LLVM_LIBRARY_DIRS}")
    separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
    add_definitions(${LLVM_DEFINITIONS_LIST})

    # LLVM include directory
    include_directories(${LLVM_INCLUDE_DIRS})

    # LLVM link directory
    link_directories(${LLVM_LIBRARY_DIRS})
else()
    message(WARNING "LLVM not found.")
endif()