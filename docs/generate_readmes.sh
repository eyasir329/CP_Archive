#!/bin/bash
set -e  # Exit on error

for dir in {00..18}_*/; do
  cat > "$dir/README.md" <<EOF
---
layout: category
title: ${dir//_/ }
---

### Solutions
$(find "$dir" -name "*.cpp" | sed 's|.*/|- [&](&)|; s/.cpp//')
EOF
done