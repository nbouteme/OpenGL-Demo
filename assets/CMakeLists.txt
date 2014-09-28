ADD_CUSTOM_COMMAND(
	OUTPUT ${PROJECT_BINARY_DIR}/assets.cpp
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMENT "Génération de assets.cpp ..."
	COMMAND xxd -i cube.obj	   | sed "s/unsigned char / char /" >  ${PROJECT_BINARY_DIR}/assets.cpp
	COMMAND xxd -i emerald.obj | sed "s/unsigned char / char /" >> ${PROJECT_BINARY_DIR}/assets.cpp
	COMMAND xxd -i baseFS.glsl | sed "s/unsigned char / char /" >> ${PROJECT_BINARY_DIR}/assets.cpp
	COMMAND xxd -i baseVS.glsl | sed "s/unsigned char / char /" >> ${PROJECT_BINARY_DIR}/assets.cpp
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/cube.obj
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/emerald.obj
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/baseFS.glsl
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/baseVS.glsl
	)

# Un jour, je reglerais le probleme.
ADD_CUSTOM_TARGET(assets ALL
#	DEPENDS ${PROJECT_BINARY_DIR}/assets.cpp
	)

ADD_DEPENDENCIES(assets shaders textures models)

ADD_SUBDIRECTORY(models)
ADD_SUBDIRECTORY(textures)
ADD_SUBDIRECTORY(shaders)

