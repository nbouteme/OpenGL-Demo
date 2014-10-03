FILE(GLOB Shaders
	 RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	 ${CMAKE_CURRENT_SOURCE_DIR}/*.glsl)

ADD_CUSTOM_TARGET (shaders ALL
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS ${PROJECT_SOURCE_DIR}/assets/shaders.o
	)

ADD_CUSTOM_COMMAND(OUTPUT ${PROJECT_SOURCE_DIR}/assets/shaders.o 
	COMMENT "Regeneration des shaders."
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND pwd
	COMMAND resgen *.glsl > shaders.res
	COMMAND ld -r -b binary shaders.res -o ${PROJECT_SOURCE_DIR}/assets/shaders.o
	DEPENDS resgen ${Shaders}
)

