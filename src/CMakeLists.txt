LINK_DIRECTORIES (
	${CMAKE_SOURCE_DIRECTORY}
	)

INCLUDE_DIRECTORIES (
	${PROJECT_BINARY_DIR}/include
	)

ADD_EXECUTABLE(${PROJECT_NAME}
	GLWindow.cpp
	Application.cpp
	Model.cpp
	Scene.cpp
	Camera.cpp
	Shader.cpp
	BetaRoom.cpp
	Emerald.cpp
	Torus.cpp
	Polyedre.cpp
	CubeMap.cpp
	Assets.cpp
	Effect.cpp
	Controller.cpp
	XBoxController.cpp
	utils/OBJData.cpp
	main.cpp
	)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	# TODO: Trouver une meilleure solution
	${CMAKE_BINARY_DIR}/resgen/reslib/src/libreslib.a
    ${GLFW_LIBRARIES}
    ${GL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${SOIL_LIBRARIES}
    ${RESGEN_LIBRARIES}
	assets
	)

ADD_DEPENDENCIES(${PROJECT_NAME} assets resgen)

INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/ PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
