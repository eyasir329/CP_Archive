#!/bin/bash
for dir in docs/{00..18}_*; do
  cat > "$dir/README.md" <<EOF
---
layout: category
title: $(basename "$dir" | sed 's/_/ /g')
---

### Problem List
$(find "$dir" -name "*.cpp" | while read file; do
  echo "- [$(basename "$file" .cpp)]($(basename "$file"))"
done)
EOF
done