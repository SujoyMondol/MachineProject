# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-src"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-build"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/tmp"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src"
  "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Fall 2024 MSU/CSE 335/project2-starter/MachineDemo/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
