#!/bin/bash
while read foldername others; do
    touch ../$foldername/"$foldername"_en.subject.pdf
done < folderlist.txt