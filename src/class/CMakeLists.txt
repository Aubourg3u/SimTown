set(target_name class)
add_library(${target_name} STATIC "")
target_sources(${target_name}
 PRIVATE "${PROJECT_SOURCE_DIR}/src/class/building.cpp"
 PRIVATE "${PROJECT_SOURCE_DIR}/include/class/building.h"
 PRIVATE "${PROJECT_SOURCE_DIR}/include/class/MyVector.h"
 PRIVATE "${PROJECT_SOURCE_DIR}/include/class/globals.h"
 PRIVATE "${PROJECT_SOURCE_DIR}/include/class/storey.h"
 PRIVATE "${PROJECT_SOURCE_DIR}/src/class/storey.cpp"
 PRIVATE "${PROJECT_SOURCE_DIR}/src/class/globals.cpp"
 PRIVATE "${PROJECT_SOURCE_DIR}/src/class/resident.cpp"
 PRIVATE "${PROJECT_SOURCE_DIR}/include/class/resident.h"
)
target_include_directories(${target_name}
 PUBLIC
 "${PROJECT_SOURCE_DIR}/include"
 "${PROJECT_BINARY_DIR}"
)