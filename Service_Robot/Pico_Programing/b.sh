#Tyler Evans u1313811 bash script made
#with the help of GPT
#!/bin/bash
set -e #exits upon a bad comand

cmake -B build -S .
cd build
make
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .
echo "Generated files complete"
cd ..

#This is the copy and paste command of the uf2 file
ls
echo "the file path is above"
echo "complete :) "
