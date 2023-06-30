cmake_minimum_required(VERSION 3.10.0)
project(Financial-reimbursement-management-system)

#让cmake自动去寻找Qt5的包,最后用TARGET_LINK_LIBRARIES链接
FIND_PACKAGE(Qt5 COMPONENTS Core Gui Widgets Sql Svg REQUIRED)
SET(QT_USE_QTMAIN TRUE)

#这些生成的中间文件都会在build目录下，这样的话，编译器则不能定位由uic程序产生的诸如_ui_mainwindow.h等文件。所以，我们需要把build目录添加到包含目录中
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#采用C++11标准
set(CMAKE_CXX_STANDARD 11)

#添加所有的源文件
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/.   SOURCES)
file(GLOB SOURCES *.cpp *.cxx *.cc)
#添加所有的头文件
file(GLOB HEADERS *.h *.hpp)
#添加所有的.ui文件
file(GLOB FORMS *.ui)
#添加资源文件
file(GLOB RESOURCES *.qrc)

# 设置生成的项目筛选器
source_group("Form Files" FILES ${FORMS})
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("Resource Files" FILES ${RESOURCES})
source_group("Translation Files" FILES ${TRANSLATIONS})


#自动处理ui,moc处理头文件,rcc处理.qrc文件
set(CMAKE_AUTOUIC ON)	
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


#生成可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} 
	${SOURCES} 
	${FORMS} 
    	${RESOURCES}
	${HEADERS}

)
#ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCES})
#为target添加需要链接的共享库
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql  Qt5::Svg)