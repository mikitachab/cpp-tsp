#!/bin/bash

cpp_version="-std=c++14"
include_path="include"
src_path="src/*.cpp"
output_path="./build/tsp"

echo "Building..."
g++ $cpp_version -I $include_path $src_path -lncurses -pthread -o $output_path

build_err=$?
if [ $build_err -ne 0 ]
then
  echo "Build error."
  exit
fi
echo "Building finished successfully"