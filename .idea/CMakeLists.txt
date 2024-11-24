cmake_minimum_required(VERSION 3.29)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
    CLionProjects.iml
    editor.xml
    misc.xml
    modules.xml
    quoridorv3.iml
    vcs.xml
    workspace.xml)
