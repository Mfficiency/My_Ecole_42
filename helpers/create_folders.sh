#!/bin/bash
while read foldername others; do
	mkdir -p ../$foldername
    touch ../$foldername/"$foldername".c
    touch ../$foldername/HowTo.md
done < folderlist.txt