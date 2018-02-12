#!/bin/bash
find . -type f \( -name "*.aux" -o -name "*.synctex.gz" -o -name "*.log" -o -name "*.out" -o -name "*.toc" -o -name ".hidden" -o -name "*.idx" \) -exec rm {} \;
