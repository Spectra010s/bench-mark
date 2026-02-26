#!/bin/bash

counter=1
for file in grok*; do
  mv "$file" "prog$counter${file#grok}"
  counter=$((counter + 1))
done
