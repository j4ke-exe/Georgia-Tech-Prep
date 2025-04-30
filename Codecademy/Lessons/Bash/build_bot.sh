#!/bin/bash
echo "------------------ j4ke.exe ------------------"

firstline=$(head -n 1 source/changelog.md)
read -a splitfirstline <<< $firstline
version=${splitfirstline[1]}

echo "Build version: $version"
echo "Do you want to continue? ('1' = Yes | '2' = No)"
read versioncontinue

if [ "$versioncontinue" == "1" ]
then
  echo "----------------------------------------------"
  echo "Executing."
  echo "----------------------------------------------"
  for file in source/*
  do
    echo "[~] $file"
    if [ "$file" == "source/secretinfo.md" ]
    then
      echo "[!] Not copying $file"
    else
      echo "[+] Copying $file"
      cp $file build/.
    fi
  done
  echo "----------------------------------------------"
  cd build
  echo "\build\ folder now contains: "
  ls
  cd ..
  echo "----------------------------------------------"
  echo "Build version $version contains:"
  ls
  echo "----------------------------------------------"
else
  echo "Please come back when you are ready."
fi
