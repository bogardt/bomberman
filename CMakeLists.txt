#
# IndieStudio CMake configuration file
#
# Erwan Dupard
#
# /^'--'^\

cmake_minimum_required(VERSION 3.5)

project(bomberman)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(bomberman
  source/Main.cpp				
  source/Menu.cpp
  source/Engine.cpp				
  source/EntityManager.cpp			
  source/EntityFactory.cpp			
  source/Entity.cpp				
  source/components/Component.cpp		
  source/components/PositionComponent.cpp	
  source/components/SpeedComponent.cpp		
  source/components/ModelComponent.cpp		
  source/components/PlayerInputComponent.cpp	
  source/components/SolidityComponent.cpp	
  source/components/ExplosiveComponent.cpp	
  source/components/ExplosionComponent.cpp	
  source/components/HealthComponent.cpp	
  source/components/PowerUpComponent.cpp	
  source/components/ContainerComponent.cpp
  source/components/BasicEnemyComponent.cpp
  source/systems/movementSystem.cpp		
  source/systems/playerInputSystem.cpp		
  source/systems/ExplosiveSystem.cpp		
  source/systems/ExplosionSystem.cpp		
  source/systems/powerUpSystem.cpp		
  source/systems/healthSystem.cpp
  source/systems/basicEnemySystem.cpp			
  source/systems/guiSystem.cpp			
  source/Display.cpp				
  source/EventReceiver.cpp			
  source/EventListener.cpp
  source/Audio.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

FIND_PACKAGE(X11)
FIND_PACKAGE(GLUT)
FIND_PACKAGE(ZLIB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./include ${SFML_INCLUDE_DIR})
link_directories(./lib)

set(IRRLICHT_LIBRARIES
  -L/usr/X11R6/lib
  -L./lib
  -lIrrlicht
  -lGL
  -lGLU
  -lXext
  -lX11
  -lXxf86vm
  -lsfml-graphics
  -lsfml-window
  -lsfml-system
  -lsfml-audio
)

target_link_libraries(bomberman
  ${X11_LIBRARIES}
  ${GLUT_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${SFML_LIBRARIES}
  ${IRRLICHT_LIBRARIES})
