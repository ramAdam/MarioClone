
file(GLOB ANIMATION_SOURCES "private/Animation/*.cpp")
file(GLOB ENTITY_SOURCES "private/Entity/*.cpp")

# Add the executable
add_executable(${PROJECT_NAME} private/Game.cpp  ${ANIMATION_SOURCES} ${ENTITY_SOURCES})

# Include public headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)

# Link SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)



# Copy the Font directory to the build directory
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#         ${CMAKE_SOURCE_DIR}/font/arial ${CMAKE_BINARY_DIR}/arial
# )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources
)