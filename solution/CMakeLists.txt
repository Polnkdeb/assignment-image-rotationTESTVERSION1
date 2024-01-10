file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources}
        src/deserializer.c
        src/serializer.c
        src/rotate.c
        src/rotate.c)
target_include_directories(image-transformer PRIVATE src include)
