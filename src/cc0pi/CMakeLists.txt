set(VERTEX_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Test.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/EventMap.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/EventMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ParticleTrack.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ParticleTrack.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/EventSelection.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/EventSelection.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SignalEnum.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/SignalEnum.cpp
        )

target_sources(SignalDef PRIVATE ${VERTEX_SOURCES})

target_include_directories(SignalDef PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})