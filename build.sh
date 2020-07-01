#!/bin/bash
if [ -d "./build" ]; then
  echo "Removing build folder."
  rm -r build/;
fi

if [ -d "./lib" ]; then
  echo "Removing lib folder."
  rm -r lib/;

fi

if [ -d "./bin" ]; then
  echo "removing bin folder."
  rm -r bin/;
fi

if [ -d "./include" ]; then
  echo "removing include folder."
  rm -r include/;
fi

mkdir build
cd build
cmake ..
make install

