#!/bin/bash

# This script runs a clean build

if [ -d "./build" ]; then
  echo "Removing build folder."
  rm -r build/;
  mkdir build
else 
  mkdir build
fi

# Remove build artifacts,
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

cd build
Make install

