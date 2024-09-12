#!/bin/bash

git config --global init.defaultBranch main        
git config --global user.name  "Bakamashine"
git config --global user.email ivan.fa.002@gmail.com
git config --global core.editor emacs
git init
git add git.bat
git commit -m "My first commit"
git remote add origin "https://github.com/Bakamashine/test2.git"
git push --set-upstream origin main
