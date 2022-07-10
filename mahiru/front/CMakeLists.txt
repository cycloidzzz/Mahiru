set(MAHIRU_FRONT_SRCS
    lexer.cc
    parser.cc
)

add_library(mahiru_front ${MAHIRU_FRONT_SRCS})
install(TARGETS mahiru_front DESTINATION lib)

file(GLOB MAHIRU_COMMON_HEADERS "*.h")
install(FILES ${MAHIRU_COMMON_HEADERS} DESTINATION include/mahiru/front)