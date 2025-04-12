#!/bin/bash
set -e  # Exit on error

for i in {00..18}; do
  dir=$(ls -d ${i}_*/ 2>/dev/null || true)
  if [ -n "$dir" ]; then
    cat > "${dir}README.md" <<EOF
---
layout: category
title: ${dir//_/ }
---

### Solutions
$(find "$dir" -name "*.cpp" | while read file; do
  filename=$(basename "$file" .cpp)
  echo "- [${filename}](${filename})"
done)
EOF
  fi
done