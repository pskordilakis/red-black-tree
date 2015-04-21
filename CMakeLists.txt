CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(redblack-tree)

#set sources dir
set(SRC src)

#build redblack tree library (.so)
include(${SRC}/redblacktree/CMakeLists.txt)

#create the executable
SET(EXEC red)
ADD_EXECUTABLE(${EXEC} ${SRC}/main.c)

TARGET_LINK_LIBRARIES (${EXEC}
   redblacktree
)